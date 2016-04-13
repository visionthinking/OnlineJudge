#include <stdio.h>
#include <string.h>

const int MAX = 50000006;
const int MOD = 23333;
int k, n;
int K[MAX];

int gcd(int a, int b){
	return (b == 0) ? a : gcd(b, a % b);
}

int f(int m){
	if(K[m] != 0){
		return K[m];	
	}
	if(m & 1){
		return K[m] = (f(m-1) * k) % MOD;
	}
	return K[m] = (f(m>>1) * f(m>>1)) % MOD;
}

void solve(){
	memset(K, 0, sizeof(K));
	K[0] = 1;
	
	scanf("%d %d", &k, &n);
//	printf("gcd(%d, %d)=%d\n", 4, 1, gcd(4, 1));
	int half = n >> 1;
	int sum = 0;
//	printf("sum=%d half=%d\n", sum, half);
	for(int i=1; i<=half; i+=1){
		sum = (sum + 2 * f(gcd(n, i))) % MOD;
//		printf("gcd(%d, %d)=%d\n", n, i, gcd(n, i));
	}
	if(n & 1){
		sum = (sum + f(n)) % MOD;
	}else{
		sum = (sum - f(half) + f(n)) % MOD;
	}
	printf("%d\n", sum);
}

int main(void){
	freopen("D.in", "r", stdin);
	int kase;
	scanf("%d", &kase);
	for(int i=1;i<=kase;i+=1){
		solve();
	}
	return 0;
}
