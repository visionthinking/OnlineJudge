#include <stdio.h>
#include <string.h>

inline
int max(int a, int b){
	return a > b ? a : b;	
}

const int MAX = 100005;

int dp[MAX];
int cost[105], quantity[105];
int n, m;

void solve(){
	for(int i=1;i<=n;i++){
		scanf("%d", &cost[i]);
	}
	for(int i=1;i<=n;i++){
		scanf("%d", &quantity[i]);
	}
	
	memset(dp, -1, sizeof(dp));
	dp[0] = 0;
	for(int i=1;i<=n;i++){
		for(int j=0;j<=m;j++){
			dp[j] = (dp[j] >= 0) ? quantity[i] : -1;
		}
		for(int j=0;j<=m-cost[i];j++){
			if(dp[j] > 0 && dp[j] - 1 > dp[j+cost[i]]){
				dp[j+cost[i]] = dp[j] - 1;
			}
		}
		/*
		for(int k=0;k<=m;k++){
			printf("[%d] ", dp[k]);
		}
		printf("\n");
		*/
	}
	
	int sum = 0;
	for(int i=1;i<=m;i++){
		if(dp[i]>=0){
			sum += 1;	
		}
	}
	printf("%d\n", sum);
}

int main(void){
	freopen("p1742.in", "r", stdin);
	
	while(1){
		scanf("%d %d", &n, &m);
		if(n == 0 && m == 0){
			break;
		}
		solve();
	}
	
	return 0;
}
