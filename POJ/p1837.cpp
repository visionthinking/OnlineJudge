#include <stdio.h>
#include <string.h>

int dp[25][15005];

void solve(){
	int n, m;
	int c[25], g[25];
	
	memset(dp, 0, sizeof(dp));
	dp[0][7500] = 1;
	
	scanf("%d %d", &n, &m);
	for(int i=0;i<n;i++){
		scanf("%d", &c[i]);
	}
	for(int i=1;i<=m;i++){
		scanf("%d", &g[i]);
	}
	
	for(int i=1;i<=m;i++){
		for(int j=0;j<=15001;j++){
			if(dp[i-1][j] != 0){
				for(int k=0;k<n;k++){
					dp[i][ j + c[k] * g[i] ] += dp[i-1][j];
				}
			}
		}
	}
	
	printf("%d\n", dp[m][7500]);
}

int main(void){
	freopen("p1837.in", "r", stdin);
	solve();
	return 0;
}
