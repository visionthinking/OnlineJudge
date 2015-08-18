#include <stdio.h>
#include <string.h>

const int MAX = 105;
int dp[100005], cost[MAX], quantity[MAX];
int cash, n;

void solve(){
	for(int i=0;i<n;i++){
		scanf("%d %d", &quantity[i], &cost[i]);
	}
	if(cash == 0 || n == 0){
		printf("0\n");
		return;
	}
	
	memset(dp, -1, sizeof(dp));
	dp[0] = 0;
	for(int i=0;i<n;i++){
		for(int j=0;j<=cash;j++){
			dp[j] = (dp[j] >= 0) ? quantity[i] : -1;
		}
		for(int j=0;j<=cash-cost[i];j++){
			if(dp[j] >= 0 && dp[j]-1 > dp[j+cost[i]]){
				dp[j+cost[i]] = dp[j]-1;
			}
		}
	}
	for(int i=cash;i>=0;i--){
		if(dp[i]>=0){
			printf("%d\n", i);
			return;	
		}
	}
}

int main(void){
	freopen("p1276.in", "r", stdin);
	
	while(scanf("%d %d", &cash, &n) != EOF){
		solve();
	}
	
	return 0;
}
