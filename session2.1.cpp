#include <stdio.h>
#include <string.h>

struct car {
	char brand[50];
	char model[50];
	int year;
};

struct customer{
	char name[50];
	char address[50];
	int salary;
};

struct employee{
	char name[50];
	int salary;
	int id;
};
int main(){
	struct car car1 ={"BM", "X", 1999};
	struct car car2 = {"Ford", "Mustang", 1969};
	struct car car3 = {"Toyota", "Corolla", 2011};
	 
	struct customer cus1 = {"Alam", "Malang", 30000000};
	struct customer cus2 = {"Hannis", "Lampung", 70000000};
	struct customer cus3 = {"Ghina", "Tangerang", 90000000};
	
	struct employee e1= {"Alif", 400000000, 1};
	struct employee e2 = {"Hafid", 600000000, 2};
	struct employee e3 = {"Rizki", 5000000000, 3};
	
	printf("%s %s %d\n", car1.brand, car1.model, car1.year);
	printf("%s %s %d\n", car2.brand, car2.model, car2.year);
	printf("%s %s %d\n", car3.brand, car3.model, car3.year);
	
	printf("%s %s %d\n", cus1.name, cus1.address, cus1.salary);
	printf("%s %s %d\n", cus2.name, cus2.address, cus2.salary);
	printf("%s %s %d\n", cus3.name, cus3.address, cus3.salary);
	
	printf("%s %d %d\n", e1.name, e1.salary, e1.id);
	printf("%s %d %d\n", e2.name, e2.salary, e2.id);
	printf("%s %d %d\n", e3.name, e3.salary, e3.id);
	return 0;
}
