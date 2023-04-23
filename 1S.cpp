#include <stdio.h>
//print the code
int main(){
	char string[150];
	scanf("%[^\n]", &string);
	printf("#include <stdio.h>\nint main()\n{\n    printf(\"%%s\", \"%s\");\n    return 0;\n}",string);
	
	return 0;
}
