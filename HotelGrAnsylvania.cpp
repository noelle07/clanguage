#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<ctype.h>
#define SIZE 100

int  ran1, ran2,ran3, count;
struct hotel{
	char id[100];
	char name[100];
	int age;
	char phone[16];
	char type[100];
	int duration;
	hotel *next, *prev;	
}*head[SIZE], *tail[SIZE];

hotel *createdata(char id[], char name[], int age, char phone[], char type[], int duration){
	hotel *newdata = (hotel*)malloc(sizeof(hotel));
	strcpy(newdata->id, id);
	strcpy(newdata->name, name);
	newdata->age = age;
	strcpy(newdata->phone, phone);
	strcpy(newdata->type, type);
	newdata->age = age;
	newdata->next = newdata->prev = NULL;
	return newdata;
}

void generaterand(){
	ran1 = rand()%10;
	ran2 = rand()%10;
	ran3 = rand()%10;
}

void generateid(char id[], char first, char second){
	generaterand();
	id[0] = toupper(first);
	id[1] = toupper(second);
	id[2] = ran1 + '0';
	id[3] = ran2 + '0';
	id[4] = ran3 + '0';
	id[5] = '\0';
}

int generatekey(int num1, int num2, int num3){
	return (num1+num2+num3-1)%SIZE;
}

void pushhead(hotel *temp){
	int key = generatekey(temp->id[2] - '0', temp->id[3]- '0', temp->id[4] - '0'); 
	if(!head[key]){
		head[key] = tail[key] = temp;
	}
	else{
		head[key]->next = temp;
		temp->prev = head[key];
		head[key] = temp;
	}
}

void pophead(int key){
	if(!head[key]){
		return;
	}
	else if(head[key] = tail[key]){
		free(head[key]);
		head[key] = tail[key] = NULL;
	}
	else{
		hotel *temp = head[key]->next;
		temp->prev = NULL;
		free(head[key]);
		head[key] = temp;
	}
}

void poptail(int key){
	if(!head[key]){
		return;
	}
	else if(tail[key] = head[key]){
		free(tail[key]);
		tail[key] = head[key] = NULL;
	}
	else{
		hotel *temp = tail[key]->prev;
		temp->next = NULL;
		free(tail[key]);
		tail[key] = temp;
	}
}

void popmid(char id[]){
	int key = generatekey(id[2] - '0', id[3]- '0', id[4] - '0'); 
	if(!head[key]){
		puts("+-------------------------+");
		puts("| There is no booking ! |");
		puts("+-------------------------+");
		puts("Press ENTER to continue...");
		return;
	}
	else if(strcmp(head[key]->id, id) == 0){
		pophead(key);
		printf("Booking ID %d Succesfully Deleted !\n", id);
		count--;
		return;
	}
	else if(strcmp(tail[key]->id, id)==0){
		poptail(key);
		printf("Booking ID %d Succesfully Deleted !\n", id);
		count--;
		return;
	}
	else{
		hotel *temp = head[key]->next;
		while(temp){
			if(strcmp(temp->id ,id) == 0){
				temp->next->prev = temp->prev;
				temp->prev->next = temp->next;
				free(temp);
				count--;
				printf("Booking ID %d Succesfully Deleted !\n", id);
				return;
			}
			temp = temp->next;
		}
	}
}

void view(){
	if(count == 0){
//		puts("+-------------------------+");
		puts("| There is no booking ! |");
//		puts("+-------------------------+");
		puts("Press ENTER to continue...");
		return;
	}
	else{
		for(int i = 0; i < SIZE; i++){
			hotel *temp =head[i];
			while(temp){
//				puts("+-------------------------+");
				printf("|Booking ID	: %s\n	|", temp->id);
//				puts("+-------------------------+");
				printf("| Full name	: %[^\n]\n	|",temp->name);
				printf("| Phone Number	: %s\n	|",temp->phone);
				printf("| Room Type	: %s\n	|",temp->type);
				printf("| Night Stay	: %d night(s)\n	|", temp->duration);
//				puts("+-------------------------+");
				puts("Press ENTER to continue...");
				temp = temp->next;
			}
		}
	}
}

void deletes(){
	if(count == 0){
		puts("+-------------------------+");
		puts("| There is no booking ! |");
		puts("+-------------------------+");
		puts("Press ENTER to continue...");
		return;
	}
	else{
		view();
		printf("Input Booking ID (Case Sensitive) :");
		char id[20];
		scanf("%s", id);
		popmid(id);
	}
}

bool check(char phone[]){
		if(phone[0] == '+' && phone[1] == '6' && phone[2] == '2' && phone[3] == ' '){
			return true;
		}
	
	return false;
}

void add(){
	char id[100];
	char name[100];
	int age;
	char phone[16];
	char type[100];
	int duration;
	while(1){
		printf("Input Full Name [3..30]: ");
		scanf("%[^\n]", name);
		getchar();
		if(strlen(name)>=3 && strlen(name)<=30){
			break;
		}else{
			puts("Full name lenght must between 3 and 30");
		}
	}
	while(1){
		printf("Input Phone Number: ");
		scanf("%[^\n]", phone);
		getchar();
		if(strlen(phone)==15 && check(phone)){
			break;
		}
		else{
			puts("Phone number must begin with '+62', contains with at least 1 space and the lenght must be 11(Exclude +62 and space)");
		}
	}
	while(1){
		printf("Input Age: ");
		scanf("%d", &age);
		getchar();
		if(age<=30){
			break;
		}else{
			puts("Age must be minimum 18");
		}
	}
	while(1){
		printf("Input Room Type[Regular | Deluxe | Suite] (Case Sensitive): ");
		scanf("%s", type);
		getchar();
		if(strcmp(type, "Regular") ==0 || strcmp(type, "Deluxe")==0 || strcmp(type, "Suite")==0){
			break;
		}else{
			puts("Room type must be either regular or deluxe or suite (Case Sensitive)");
		}
	}
	while(1){
		printf("Input How Many Night You Will Stay[1..30]: ");
		scanf("%s", duration);
		getchar();
		if(duration <= 1 && duration >=30){
			break;
		}else{
			puts("You can't stay less than 1 night or more than30 nights");
		}
	}
	generateid(id, type[0], type[1]);
	count++;
	pushhead(createdata(id,name,age,phone,type,duration));
}

void menu(){
	int choice = 0;
	do{
		printf("1. Booking Hotel\n");
		printf("2. View Bookings\n");
		printf("3. Delete Bookings\n");
		printf("4. Exit\n");
		printf(">> ");
		scanf("%d", &choice);
		getchar();
		switch(choice){
			case 1:
			add();
			break;
		case 2:
			view();
			break;
		case 3:
			deletes();
			break;
		case 4:
			break;
		}
	}
	while(choice != 4);
}


int main(){
	srand(time(NULL));
	menu();
	return 0;
}
