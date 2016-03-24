#include <stdio.h>
#include <string.h>

unsigned int n;

void input(){
	scanf("%u", &n);
}

void solve(){
	if(n == 0){
		printf("0\n");
		return;
	}
	int start = 0;
	int cnt = 0;
	for(int i=31;i>=0;i-=1){
		if(((n >> i) & 1)){
			start = i;
			break;
		}
	}
//	printf("n=%d start:%d\n", n, start);
	for(int i=start-1;i>=0;i-=1){
		if(((n >> i) & 1) == 0){
			cnt += 1;
		}
	}
//	printf("cnt = %d\n", cnt);
	printf("%d\n", 1 << cnt);
}

int main(void){
	freopen("C.in", "r", stdin);
	int kase;
	while(scanf("%d", &kase) != EOF){
		for(int i=0;i<kase;i+=1){
			input();
			solve();
		}
	}
	return 0;
}


