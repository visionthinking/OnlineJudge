#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


const int MAX = 1000000;
bool prime[MAX];
int prime_count[MAX];
int S[MAX];

void fill_prime_count(const int max){
	prime_count[0] = prime_count[1] = 0;
	for(int i=2;i<=max;i++){
		prime_count[i] = prime_count[i-1] + (prime[i] ? 1 : 0);	
	}
}

//Prime Sieve
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

void fill_submultiplex(const int max){
	fill_prime(sqrt(max)+1);
	fill_prime_count(sqrt(max)+1);
	S[0] = 0;
	S[1] = 1;
	int sq;
	for(int i=2; i <= max; i++){
		sq = sqrt(i);
		S[i] = prime_count[sq]*2 + (sq*sq == i ? 1 : 2);
	}
	printf("%d\n", S[1000000]);
}

void show_prime(const int max){
	for (int i=1; i < MAX; i++) {
		if(prime[i]) printf("%d ", i);     
	}
	printf("\n");
	for (int i=1; i < MAX; i++) {
		printf("%d ", prime_count[i]);
	}
}

int main(void){
	fill_submultiplex(MAX);
	return 0;	
}
