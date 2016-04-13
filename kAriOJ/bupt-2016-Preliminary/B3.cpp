#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

const int MAX = 2002;
const long long MOD = 1000000009;
const int C[18] = {0, 1, 4, 9, 16, 25, 36, 49, 64, 81, 100, 121, 144, 169, 196, 225, 256, 289};
long long a[MAX];
int n;

long long dp(int x, long long parent){
//	printf("dp( %d ): %lld \n", x, a[x]);
	if(a[x] != 0){
//		return a[x];
	}
	if(x == 0){
		return 1;	
	}
	long long r = 0;
	int i = 1;
	while(x >= C[i] && parent >= C[i] && i <= 17) {
		r = (r + dp(x - C[i], C[i])) % MOD;
		i += 1;
	}
//	printf("%d\n", r);
	a[x] = r;
//	printf("dp( %d ): %lld \n", x, a[x]);
	return r;
}

void init(){
	memset(a, 0, sizeof(a));
	a[0] = 1;
}

void input(){
	scanf("%d", &n);
//	printf("case %d: ", n);
}

void solve(){
	printf("%lld\n", dp(n, MOD));
	for(int i=0;i<20;i+=1){
		printf("a[%d]=%d\n", i, a[i]);
	}
}

int main(void){
	freopen("B.in", "r", stdin);
	init();
	int kase;
	while(scanf("%d", &kase) != EOF){
		for(int i=1; i<=kase; i+=1){
			input();
			solve();
		}
	}
	return 0;
}



