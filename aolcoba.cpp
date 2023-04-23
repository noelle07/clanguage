#include <stdio.h>
#include <string.h>

typedef struct {
    char loc1[300];
    char loc2[300];
    long long int price;
    int rooms;
    int bathrooms;
    int carParks;
    char type[300];
    int area;
    char furnish[300];
}data;

int main(void)
{
    FILE *file = fopen("file.csv", "r");
    
    if(file == NULL)
    {
        printf("Error opening file.");
        return 1;
    }
    
    char line[200];
    
    while (fgets(line, sizeof(line), file)){
    	char *token;
    	
    	token = sizetoken(line, ",");
    	
    	while(token != NULL){
    		printf("%s", token);
    		token = sizetoken(NULL, ",");
		}
		printf("\n");
	}
    
    char loc1[300];
    char loc2[300];
    char price[200];
    char rooms[300];
    char bathrooms[300];
    char carParks[300];
    char type[300];
    char area[300];
    char furnish[300];
    data datas[1005];
//    
//    //read each line of the file and store the record ito this datas array
//    //read to store the number of values that we read in successfully from each line of the file
//    int read = 0;
    int records = 0;
    
    fscanf(file, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",
                        loc1,
                        loc2,
                        &price,
                        &rooms,
                        &bathrooms,
                        &carParks,
                        type,
                        &area,
                        furnish);
//    puts("aman");
    printf("%s %s %s %s %s %s %s %s %s\n", loc1,
                        loc2,
                        price,
                        rooms,
                        bathrooms,
                        carParks,
                        type,
                        area,
                        furnish);
    
    do{
    	fscanf(file, "%[^,],%[^,],%lld,%d,%d,%d,%[^,],%d,%[^\n]\n",
                        datas[records].loc1,
                        datas[records].loc2,
                        &datas[records].price,
                        &datas[records].rooms,
                        &datas[records].bathrooms,
                        &datas[records].carParks,
                        datas[records].type,
                        &datas[records].area,
                        datas[records].furnish);
    	records++;
    	
	}while(!feof(file));
//    while( != EOF ){
//        records++;    	
//    	printf("p");
//	}
   
    printf("\n%d records read.\n\n", records);
    
    for (int i = 0; i < records; i++)
    {
    printf("%s : %d", 
            datas[i].loc1,
            datas[i].price); //ini coba2 tp bukan jawaban    
            printf("\n");
    }
    return 0;
}
