#include <stdio.h>

//typedef struct data{
//    char loc1[300];
//    char loc2[300];
//    int price;
//    int rooms;
//    int bathrooms;
//    int carParks;
//    char type[300];
//    int area;
//    char furnish[300];
//}housing;
 	struct data{
    char loc1[300];
    char loc2[300];
    int price;
    int rooms;
    int bathrooms;
    int carParks;
    char type[300];
    int area;
    char furnish[300];
} housing[3940];

int main(void)
{
    FILE *file = fopen("file(1).csv", "r");
    
    if(file == NULL)
    {
        printf("Error opening file.");
        return 1;
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
    int records = 0;
//    data datas[1005];
//    
//    //read each line of the file and store the record ito this datas array
//    //read to store the number of values that we read in successfully from each line of the file
//    int read = 0;

	
    fscanf(file,"%[^;]; %[^;]; %[^;]; %[^;]; %[^;]; %[^;]; %[^;]; %[^;]; %[^\n]\n",
                        loc1,
                        loc2,
                        price,
                        rooms,
                        bathrooms,
                        carParks,
                        type,
                        area,
                        furnish);
//    puts("aman");
    printf("%s | %s | %s | %s | %s | %s | %s | %s | %s\n", 
						loc1,
                        loc2,
                        price,
                        rooms,
                        bathrooms,
                        carParks,
                        type,
                        area,
                        furnish);
                        
    do{
    	fscanf(file, "%[^;]; %[^;]; %d; %d; %d; %d; %[^;]; %d; %[^\n] \n",
						housing[records].loc1,
                        housing[records].loc2,
                        &housing[records].price,
                        &housing[records].rooms,
                        &housing[records].bathrooms,
                        &housing[records].carParks,
                        housing[records].type,
                        &housing[records].area,
                        housing[records].furnish);
    	records++;
    	
	}while(!feof(file));

//    while( != EOF ){
//        records++;    	
//    	printf("p");
//	}
   
   	for(int i = 0; i < records; i++){
   		printf("%s | %s | %d | %d | %d | %d | %s | %d | %s \n", 
						housing[i].loc1,
                        housing[i].loc2,
                        housing[i].price,
                        housing[i].rooms,
                        housing[i].bathrooms,
                        housing[i].carParks,
                        housing[i].type,
                        housing[i].area,
                        housing[i].furnish);
	   }
    printf("\n%d records read.\n\n", records);
    
//    for (int i = 0; i < records; i++)
//    {
//    printf("%s : %d", 
//            datas[i].loc1,
//            datas[i].price); //ini coba2 tp bukan jawaban    
//            printf("\n");
//    }
    return 0;
}
