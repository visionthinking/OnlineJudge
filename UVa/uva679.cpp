#include <stdio.h>

void solve(){
	int d, n, ans;
	scanf("%d %d", &d, &n);
	ans = 1;
	for(int i=1;i<d;i++){
		if(n%2){
			ans = ans<<1;
			n = (n+1) >> 1;
		}else{
			ans = ans<<1|1;
			n = n >> 1;
		}
	}
	printf("%d\n", ans);
}

int main(void){
	freopen("uva679.in", "r", stdin);
	int n;
	while(scanf("%d", &n) != EOF){
		if(n == -1) {
			break;
		}
		for(int i=0;i<n;i++){
			solve();
		}
	}
	return 0;
}
