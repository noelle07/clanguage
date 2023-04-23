#include <stdio.h>
#include <string.h>
#include <limits.h>

char maxValue[30];
int maxFrequency = 0;
char minValue[30];
int minFrequency = INT_MAX;

struct BSTNode {
    char value[30];
    int frequency;
    struct BSTNode *left;
    struct BSTNode *right;
};

struct BSTNode* insert(struct BSTNode* node, char value[30]) {
    if (node == NULL) {
        struct BSTNode* newNode = (struct BSTNode*) malloc(sizeof(struct BSTNode));
        strcpy(newNode->value, value);
        newNode->frequency = 1;
        newNode->left = NULL;
        newNode->right = NULL;
        return newNode;
    }

    if (strcmp(value, node->value) < 0) {
        node->left = insert(node->left, value);
    } else if (strcmp(value, node->value) > 0) {
        node->right = insert(node->right, value);
    } else {
        node->frequency++;
    }
    return node;
}

int search(struct BSTNode* root, char value[30]) {
    if (root == NULL) {
        return 0;
    }

    if (strcmp(value, root->value) < 0) {
        return search(root->left, value);
    } else if (strcmp(value, root->value) > 0) {
        return search(root->right, value);
    } else {
        return root->frequency;
    }
}

void inorder(struct BSTNode* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%s : %d\n", root->value, root->frequency);
        if (root->frequency > maxFrequency) {
            maxFrequency = root->frequency;
            strcpy(maxValue, root->value);
        }
        if (root->frequency < minFrequency) {
            minFrequency = root->frequency;
            strcpy(minValue, root->value);
        }
        inorder(root->right);
    }
}

struct property {
    char loc1[30];
    char loc2[30];
    int price;
    char rooms[3];
    char bathrooms[3];
    char carparks[3];
    char type[30];
    int area;
    char furnish[30];
};

int main() {
//	int frequency[100];
    //open csv file
    FILE *file = fopen("data housing.csv", "r");
    if (file == NULL) {
        printf("Error opening file!\n");
        return 1;
    }

    //parse CSV file and store information in struct array
    struct property properties[4000];
    int count = 0;
    char line[1000];
    while (fgets(line, 1000, file)) {
        if (count == 0) {
            count++;
            continue;
        }
        //parse line and store information in struct
        char *token = strtok(line, ";");
        strcpy(properties[count].loc1, token);
        token = strtok(NULL, ";");
        strcpy(properties[count].loc2, token);
        token = strtok(NULL, ";");
        properties[count].price = atoi(token);
        token = strtok(NULL, ";");
        strcpy(properties[count].rooms, token);
        token = strtok(NULL, ";");
        strcpy(properties[count].bathrooms, token);
        token = strtok(NULL, ";");
        strcpy(properties[count].carparks, token);
        token = strtok(NULL, ";");
        strcpy(properties[count].type, token);
        token = strtok(NULL, ";");
        properties[count].area = atoi(token);
        token = strtok(NULL, ";");
        strcpy(properties[count].furnish, token);
        count++;
    }
    fclose(file);
    //prompt user for column name
    char column[20];
    printf("Enter column name (loc1, loc2, room, bathrooms, carparks, type, furnish, area, price): ");
    scanf("%s", column);
    
    struct BSTNode* root = NULL;
	//check for unique values and update frequency count
	if(strcmp(column, "loc1") == 0){
	    for(int i=0; i<count; i++) {
	        if(i == 0){
	            continue;
	        }
		    root = insert(root, properties[i].loc1);
		}
	}
	if(strcmp(column, "loc2") == 0){
	    for(int i=0; i<count; i++) {
	        if(i == 0){
	            continue;
	        }
		    root = insert(root, properties[i].loc2);
		}
	}
	if(strcmp(column, "rooms") == 0){
	    for(int i=0; i<count; i++) {
	        if(i == 0){
	            continue;
	        }
		    root = insert(root, properties[i].rooms);
		}
	}
	if(strcmp(column, "bathrooms") == 0){
	    for(int i=0; i<count; i++) {
	        if(i == 0){
	            continue;
	        }
		    root = insert(root, properties[i].bathrooms);
		}
	}
	if(strcmp(column, "carparks") == 0){
	    for(int i=0; i<count; i++) {
	        if(i == 0){
	            continue;
	        }
		    root = insert(root, properties[i].carparks);
		}
	}
	if(strcmp(column, "type") == 0){
	    for(int i=0; i<count; i++) {
	        if(i == 0){
	            continue;
	        }
		    root = insert(root, properties[i].type);
		}
	}
	if(strcmp(column, "furnish") == 0){
	    for(int i=0; i<count; i++) {
	        if(i == 0){
	            continue;
	        }
		    root = insert(root, properties[i].furnish);
		}
	}
	if(strcmp(column, "area") == 0){
        //initialize min, max, and sum for area column
        int minArea = INT_MAX;
        int maxArea = INT_MIN;
        int sumArea = 0;
        for(int i=0; i<count; i++) {
            if(properties[i].area < minArea){
                minArea = properties[i].area;
            }
            if(properties[i].area > maxArea){
                maxArea = properties[i].area;
            }
            sumArea += properties[i].area;
        }
        int avgArea = sumArea/count;
        printf("Minimum value for column area: %d\n", minArea);
        printf("Maximum value for column area: %d\n", maxArea);
        printf("Average value for column area: %d\n", avgArea);
    }
    if(strcmp(column, "price") == 0){
        //initialize min, max, and sum for price column
        int minPrice = INT_MAX;
        int maxPrice = INT_MIN;
        int sumPrice = 0;
        for(int i=0; i<count; i++) {
            if(properties[i].price < minPrice){
                minPrice = properties[i].price;
            }
            if(properties[i].price > maxPrice){
                maxPrice = properties[i].price;
            }
            sumPrice += properties[i].price;
        }
        int avgPrice = sumPrice/count;
        printf("Minimum value for column price: %d\n", minPrice);
        printf("Maximum value for column price: %d\n", maxPrice);
        printf("Average value for column price: %d\n", avgPrice);
    }
	
	if (strcmp(column, "area") != 0 && strcmp(column, "price") != 0){
		inorder(root);
		printf("Maximum value : %s with frequency %d\n", maxValue, maxFrequency);
	    printf("Minimum value : %s with frequency %d\n", minValue, minFrequency);
	}
	
    return 0;
}
