#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


const int MAX = 1000;
const int SQRT_MAX = sqrt(MAX);
bool prime[MAX];

//标准的筛法(参见 http://en.wikipedia.org/wiki/Sieve_of_Eratosthenes ) 
void fill_prime(){
	memset(prime, true, sizeof(prime));
	prime[0] = false;
	prime[1] = false;
	for (int i=2; i < SQRT_MAX; i++) {
		if (prime[i]) {
			for (int k=i*i; k < MAX; k+=i) {
				prime[k] = false;
			}
		}
	}
}

void show_prime(){
	for (int i=1; i < MAX; i++) {
		if(prime[i]) printf("%d ", i);     
	}	
}

int main(void){
	fill_prime();
	show_prime();
	return 0;	
}
