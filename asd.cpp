#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define SIZE 50

bool isFirst = true;
bool isEmpty = true;
char prevPropID[10];

struct Prop{
	char propID[10];
	char propName[100];
	char propType[100];
	int propQuantity;
	char propOwner[100];
	char propStreet[100];
	
	Prop* next;
	Prop* prev;
}*propTable[SIZE], *curr;

int generateHashKey(char propID[]){
	return (propID[2] + propID[3] + propID[4])%SIZE;
}

char* generateID(char propType[]){
	if(isFirst == true){
		if(strcmp(propType, "Mansion") == 0){
			strcpy(prevPropID, "MA001");
		}
		else if(strcmp(propType, "Bungalow") == 0){
			strcpy(prevPropID, "BU001");
		}
		else if(strcmp(propType, "Cluster") == 0){
			strcpy(prevPropID, "CL001");
		}
		isFirst = false;
	} else {
		char currPropID[10];
		currPropID[0] = prevPropID[2];
		currPropID[1] = prevPropID[3];
		currPropID[2] = prevPropID[4];
		int id = atoi(currPropID) + 1;
		itoa(id, currPropID, 10);
		
		char newPropID[10];
		if(strlen(currPropID) == 1){ //1-9
			if(strcmp(propType, "Mansion") == 0){
				strcpy(newPropID, "MA00");
			}else if(strcmp(propType, "Bungalow") == 0){
				strcpy(newPropID, "BU00");
			}else if(strcmp(propType, "Cluster") == 0){
				strcpy(newPropID, "CL00");
			}
		} else if(strlen(currPropID) == 2){ //10-99
			if(strcmp(propType, "Mansion") == 0){
				strcpy(newPropID, "MA0");
			}else if(strcmp(propType, "Bungalow") == 0){
				strcpy(newPropID, "BU0");
			}else if(strcmp(propType, "Cluster") == 0){
				strcpy(newPropID, "CL0");
			}
		} else if(strlen(currPropID) == 3){ //100-999
			if(strcmp(propType, "Mansion") == 0){
				strcpy(newPropID, "MA");
			}else if(strcmp(propType, "Bungalow") == 0){
				strcpy(newPropID, "BU");
			}else if(strcmp(propType, "Cluster") == 0){
				strcpy(newPropID, "CL");
			}
		}
		strcat(newPropID, currPropID);
		strcpy(prevPropID, newPropID);
	}
	
	return prevPropID;
}

Prop* createProp(char propID[], char propName[], char propType[], int propQuantity, char propOwner[], char propStreet[]){
	Prop* newProp = (Prop*)malloc(sizeof(Prop));
	strcpy(newProp->propID, propID);
	strcpy(newProp->propName, propName);
	strcpy(newProp->propType, propType);
	newProp->propQuantity = propQuantity;
	strcpy(newProp->propOwner, propOwner);
	strcpy(newProp->propStreet, propStreet);
	newProp->next = newProp->prev = NULL;
	
	isEmpty = false;
	
	return newProp;
}

void addProp(char propName[], char propType[], int propQuantity, char propOwner[], char propStreet[]){
	char propID[10];
	strcpy(propID, generateID(propType));
	
	int hashKey = generateHashKey(propID);
	if(propTable[hashKey] == NULL){
		propTable[hashKey] = createProp(propID, propName, propType, propQuantity, propOwner, propStreet);
		return;
	} else {
		curr = createProp(propID, propName, propType, propQuantity, propOwner, propStreet);
		Prop* pos = propTable[hashKey];
		while(pos->next != NULL){
			pos = pos->next;
		}
		pos->next = curr;
		curr->prev = pos;
		return;
	}
}

//bool propOwnerValidation(char propOwner[]){
//	//Mr. || Mrs.
//	if(strncmp(propOwner, "Mr.", 3) != 0 && strncmp(propOwner, "Mrs.", 4) != 0){
//            continue;
//        } Lena-a ga gini aja ko
//}

bool propStreetValidation(char propStreet[]){
	//street
	int len = strlen(propStreet);
	if(propStreet[len-1] == 't' &&
		propStreet[len-2] == 'e' &&
		propStreet[len-3] == 'e' &&
		propStreet[len-4] == 'r' &&
		propStreet[len-5] == 't' &&
		propStreet[len-6] == 's'){
		return false;
	}
	return true;
}

void add(){
	char propName[100];
	char propType[100];
	int propQuantity;
	char propOwner[100];
	char propStreet[100];
	char confirmation[10];
	
	do{
		puts("Input property name[length 5..20]:");
		printf(">");
		scanf("%[^\n]", propName); getchar();
	}while(strlen(propName) < 5 || strlen(propName) > 20);
	do{
		puts("Input property type [Mansion|Bungalow|Cluster](case sensitive):");
		printf(">");
		scanf("%[^\n]", propType); getchar();
	}while(strcmp(propType, "Mansion") != 0 && strcmp(propType, "Bungalow") != 0 && strcmp(propType, "Cluster") != 0);
	do{
		puts("Input room quantity [1..8]:");
		printf(">");
		scanf("%d", &propQuantity); getchar();
	}while(propQuantity < 1 || propQuantity > 8);
	do{
		puts("Input owner name start with Mr. or Mrs. :");
		printf(">");
		scanf("%[^\n]", propOwner); getchar();
	}while(strncmp(propOwner, "Mr.", 3) != 0 && strncmp(propOwner, "Mrs.", 4) != 0);
	do{
		puts("Input street name of property endswith 'street' (case sensitive) :");
		printf(">");
		scanf("%[^\n]", propStreet); getchar();
	}while(propStreetValidation(propStreet));
	do{
		puts("Are you sure to add this property[Y or N](case sensitive):");
		printf(">");
		scanf("%[^\n]", confirmation); getchar();
	}while(strcmp(confirmation, "Y") != 0 && strcmp(confirmation, "N") != 0);
	if(strcmp(confirmation, "Y") == 0){
		addProp(propName, propType, propQuantity, propOwner, propStreet);
	}
	
}

void view(){
	puts("LIST OF PROPERTY");
	puts("----------------");
	puts("");
	if(isEmpty){
		puts("No Data!");
		puts("");
		puts("Press any key to continue..."); getchar();
	} else {
		for(int i = 0; i < SIZE; i++){
			curr = propTable[i];
			if(curr != NULL){
				printf("Property ID : [%s]\n", curr->propID);
				printf("Property Name : %s\n", curr->propName);
				printf("Propety Type : %s\n", curr->propType);
				printf("Room Quantity : %d\n", curr->propQuantity);
				printf("Owner Name : %s\n", curr->propOwner);
				printf("Property Street : %s\n", curr->propStreet);
				while(curr->next != NULL){
					curr = curr->next;
					printf("Property ID : [%s]\n", curr->propID);
					printf("Property Name : %s\n", curr->propName);
					printf("Propety Type : %s\n", curr->propType);
					printf("Room Quantity : %d\n", curr->propQuantity);
					printf("Owner Name : %s\n", curr->propOwner);
					printf("Property Street : %s\n", curr->propStreet);
				}
			}
		}
		puts("");
		puts("Press any key to continue..."); getchar();
	}
}

void delProp(char propID[]){
	int hashKey = generateHashKey(propID);
	if(propTable[hashKey] == NULL){
		printf("Property not found!");
		return;
	}else{
		curr = propTable[hashKey];
		if(strcmp(propID, curr->propID) == 0){
			printf("%s - %s deleted!\n", curr->propID, curr->propName);
			getchar();
			propTable[hashKey] = curr->next;
			free(curr);
			curr = NULL;
			return;
		} else {
			while(curr != NULL && strcmp(propID, curr->propID) != 0){
				curr = curr->next;
			}
			if(curr == NULL){
				printf("Property not found!");
				return;
			} else {
				if(curr->next == NULL){
					printf("%s - %s deleted!\n", curr->propID, curr->propName);
					getchar();
					curr->next->prev = NULL;
					free(curr);
					curr = NULL;
					return;
				} else {
					printf("%s - %s deleted!\n", curr->propID, curr->propName);
					getchar();
					curr->prev->next = curr->next->prev;
					curr->next->prev = curr->prev;
					free(curr);
					curr = NULL;
					return;
				}
			}
		}
	}
}

void del(){
	puts("DELETE PROPERTY");
	puts("----------------");
	puts("");
	if(isEmpty){
		puts("No Data!");
		puts("");
		puts("Press any key to continue..."); getchar();
	} else {
		for(int i = 0; i < SIZE; i++){
			curr = propTable[i];
			if(curr != NULL){
				printf("Property ID : [%s]\n", curr->propID);
				printf("Property Name : %s\n", curr->propName);
				printf("Propety Type : %s\n", curr->propType);
				printf("Room Quantity : %d\n", curr->propQuantity);
				printf("Owner Name : %s\n", curr->propOwner);
				printf("Property Street : %s\n", curr->propStreet);
				while(curr->next != NULL){
					curr = curr->next;
					printf("Property ID : [%s]\n", curr->propID);
					printf("Property Name : %s\n", curr->propName);
					printf("Propety Type : %s\n", curr->propType);
					printf("Room Quantity : %d\n", curr->propQuantity);
					printf("Owner Name : %s\n", curr->propOwner);
					printf("Property Street : %s\n", curr->propStreet);
				}
			}
		}
		char propIDdel[10];
		do{
			puts("Chose the Property's' ID [MAXXX | BUXXX | CUXXX]");
			printf(">");
			scanf("%[^\n]", propIDdel);
		}while(false);
		delProp(propIDdel);
	}
}


int main(){
	
	int inp;
	do{
		system("cls");
		puts("1. Add new property");
		puts("2. View Property");
		puts("3. Delete property");
		puts("4. Exit");
		printf("Choose [1 - 4] >>");
		scanf("%d", &inp); getchar();
		
		switch(inp){
			case 1:
				add();
				break;
			case 2:
				view();
				break;
			case 3:
				del();
				break;
			case 4:
				
				break;
			default:
				break;
		}
		
	}while(inp != 4);
	
	
	return 0;
}
