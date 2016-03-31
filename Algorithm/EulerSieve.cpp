#include <stdio.h>
#include <string.h>

const int MAX = 100000002;
int m[MAX], euler[MAX], prime[MAX], prime_len;
/* m[i] is `i`'s min-prime-diversor */

// slow version:  Eratosthenes
bool is_prime[MAX];
void Eratosthenes_Phi() {
	memset(is_prime, true, sizeof(is_prime));
	is_prime[1] = false;
	for(int i = 1; i < MAX; i++) euler[i] = 1;
	for(int i = 2; i < MAX; i++) {
	    if( is_prime[i] ) {
	        euler[i] *= i - 1;
	        for(int j = i+i; j < MAX; j += i) {
	            is_prime[j] = false;
	            int n = j / i;
	            euler[j] *= (i - 1);
	            while(n % i == 0) {
					n /= i;
					euler[j] *= i;
				}
	        } 
	    }
	}
}

void fill_euler(){
	memset(m, 0, sizeof(m));
	euler[1] = 1;
    int k;
    for(int i=2;i<MAX;i++) {
        if(m[i] == 0) {
            prime[prime_len++] = m[i] = i;
			euler[i] = i-1;
        }
        for(int j = 0; j < prime_len && (k = prime[j]*i) < MAX; j++) {
            m[k] = prime[j];
            if(m[i] == prime[j]) {
                euler[k] = euler[i] * prime[j];
				break;
            } else {
                euler[k] = euler[i] * (prime[j]-1);
            }
        }
    }
}

int main(void){
	fill_euler();
//	Eratosthenes_Phi();
	int len = 20;
	for(int i=1; i<=len; i+=1){
		printf("euler[%d]: %d\n", i, euler[i]);
	}
	for(int i=0; i<=len; i+=1){
		printf("prime[%d]: %d\n", i, prime[i]);
	}
	for(int i=0; i<=len; i+=1){
		printf("m[%d]: %d\n", i, m[i]);
	}
	printf("\n");
	return 0;
}
