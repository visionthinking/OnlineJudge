#include <stdio.h>
#include <string.h>
#include <math.h>

const int MAX = 1000002;

int T[MAX];
int S[MAX];
int n;

void init(){
	memset(T, 0, sizeof(T));
	S[0] = 0;
	S[1] = 1;
	T[1] = 1;
	for (int i=2; i <= MAX; i++) {
		for (int k=i*2; k <= MAX; k+=i) {
			T[k] += 1;
		}
		T[i] += 2;
		S[i] = S[i-1] + T[i];
	}
}

void input(){
	scanf("%d", &n);
}

void solve(){
	printf("%d\n", S[n]);
}

int main(void){
	freopen("A.in", "r", stdin);
	init();
	int kase;
	while(scanf("%d", &kase) != EOF){
		for(int i=0;i<kase;i+=1){
			input();
			solve();
		}
	}
	return 0;
}
