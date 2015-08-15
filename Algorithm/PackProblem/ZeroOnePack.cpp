#include <stdio.h>
#include <string.h>

int max(int a, int b){
	return a > b ? a : b;
}

const int MAX = 1000;

int dp[MAX];
int capacity;

void zero_one_pack(int cost, int value){
	for(int i=capacity;i>=cost;i--){
		dp[i] = max(dp[i], dp[i-cost] + value);
	}
}

void solve(){
	int cost[MAX], value[MAX];
	int n;
	
	memset(dp, 0, sizeof(dp));
	
	scanf("%d %d", &n, &capacity);
	for(int i=0;i<n;i++){
		scanf("%d", &cost[i]);
	}
	for(int i=0;i<n;i++){
		scanf("%d", &value[i]);
	}
	
	for(int i=0;i<n;i++){
		zero_one_pack(cost[i], value[i]);
	}
	
	printf("%d\n", dp[capacity]);
}

int main(void){
	freopen("ZeroOnePack.in", "r", stdin);
	solve();
	return 0;
}
