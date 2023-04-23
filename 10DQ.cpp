#include <stdio.h>
#include <string.h>

int vowelCheck(char);

int main(){
	long int t;
	scanf("%ld", &t);
	getchar();
	for(int a = 1; a <=t; a++){
		char str[1500], str2[1500];
		long int d = 0;
		scanf("%[^\n]", &str);
		getchar();
		// buat check trus lepasin vowel
		for(int i = 0; str[i] != '\0'; i++){
			// kalau bukan vowel
			if(vowelCheck(str[i]) == 0){
				str2 [d] = str[i];
				d++;
			}
		}
		str2[d] = '\0';
		strcpy(str,str2);
		printf("Case #%ld: %s\n", a, str);
	}
	
	return 0;
}

int vowelCheck (char l){
	if(l == 'a' || l == 'A' || l == 'i' || l == 'I' || l == 'u' || l == 'U' || l == 'e' || l == 'E' || l == 'o' || l == 'O')
	return 1;
	return 0;
}
