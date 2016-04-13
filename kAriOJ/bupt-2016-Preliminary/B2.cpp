#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

const int MAX = 2002;
const long long MOD = 1000000009;
const int C[18] = {0, 1, 4, 9, 16, 25, 36, 49, 64, 81, 100, 121, 144, 169, 196, 225, 256, 289};
long long a[MAX];
int n, m;

void dp(int x){
	if(a[x] == -1){
		a[x] = 0;
	}else{
		return;	
	}
	if(x == 0){
		m = (1 + m % MOD);
	}
	int i = 1;
	while(x >= C[i] && x >= x - C[i] && i <= 17) {
		dp(x - C[i]);
		i += 1;
	}
}

void init(){
	memset(a, -1, sizeof(a));
	a[0] = 1;
}

void input(){
	scanf("%d", &n);
	printf("case: %d\n", n);
}

void solve(){
	memset(a, -1, sizeof(a));
	m = 0;
	dp(n);
	printf("%lld\n", m);
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



