#include <stdio.h>
#include <string.h>
#include <math.h>

const int MAX = 2001;
const int MOD = 1000000007;

long long S[MAX+5];

long long f(int n){
	int m = ((n+1)*n) >> 1;
	long long r = n;
	for(int i=m-n+1;i<=m-1;i+=1){
		r = (r * i) % MOD;
	}
	return r;
}

void init(){
	S[1] = 1;
	for(int i=2;i<MAX;i+=1){
		S[i] = S[i-1] * f(i) % MOD;
	}
}

int main(void){
	freopen("E.in", "r", stdin);
	init();
	int kase, n;
	while(scanf("%d", &kase) != EOF){
		for(int i=0;i<kase;i+=1){
			scanf("%d", &n);
			printf("%lld\n", S[n]);
		}
	}
	return 0;
}
