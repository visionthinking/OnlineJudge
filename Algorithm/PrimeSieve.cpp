#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


const int MAX = 1000;
bool prime[MAX];

//Prime Sieve ( see http://en.wikipedia.org/wiki/Sieve_of_Eratosthenes ) 
void fill_prime(const int max){
	int sqrt_max = sqrt(max);
	memset(prime, true, sizeof(prime));
	prime[0] = false;
	prime[1] = false;
	for (int i=2; i <= sqrt_max; i++) {
		if (prime[i]) {
			for (int k=i*i; k < max; k+=i) {
				prime[k] = false;
			}
		}
	}
}

void show_prime(const int max){
	for (int i=1; i < MAX; i++) {
		if(prime[i]) printf("%d ", i);     
	}	
}

int main(void){
	fill_prime(MAX);
	show_prime(MAX);
	return 0;	
}
