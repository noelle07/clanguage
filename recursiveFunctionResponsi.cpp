#include <stdio.h>
// bikin array buat nyimpen fibonacci ,  [41] di soal parameternya 40
long long int storage[41];

int Fibonacci(int n){
	// base case => kondisi kapan recursivenya bakal berhenti
	// misal : 0
	// misal : 1
	// misal : 2
	if(storage[n] == -1){
		// storage ke n buat kalo n udh keisi (langsung)
		// misal 0 <= 1 bener masuk storage -> 0 = 0 langsung return
		// misal 1 = 1 bener masuk storage -> 1 = 1 langsung return 
		// misal 2 != 1 salah masuk ke else
		if(n <= 1) storage[n]=n;
		// misal 2 masuk ke storage [n] = Fibonacci(n-1)+Fibonacci(n-2) trus return hasilnya 
		else{
			storage [n] = Fibonacci(n-1)+Fibonacci(n-2);
		}	 
	}
	return storage [n];	
}	
	


int main(){
	// for loop buat batesin storagenya max 40 
	for(int i = 0; i < 41; i++){
		// kalau salah kasih tanda -1
		storage[i] = -1;
	}
	// testcase
	int tc;
	scanf("%d", &tc);
	for(int i = 0; i < tc; i++){
		int n;
		scanf("%d", &n);
		// i+1 buat testcase mulai dari 1 trus ditambahin 1 dst, kalau engga gabisa soalnya 
		printf("Case #%d: %d\n", i+1, Fibonacci(n));	
	}	
	return 0;
}


