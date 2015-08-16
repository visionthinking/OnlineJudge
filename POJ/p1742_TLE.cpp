#include <stdio.h>
#include <string.h>

inline
int max(int a, int b){
	return a > b ? a : b;	
}

const int MAX = 100005;

int dp[MAX], cost[105], quantity[105];
int n, m;

void zero_one_pack(int cost, int value){
	for(int i=m;i>=cost;i--){
		dp[i] = max(dp[i], dp[i-cost] + value);
	}
}

void complete_pack(int cost, int value){
	for(int i=cost;i<=m;i++){
		dp[i] = max(dp[i], dp[i-cost] + value);
	}
}

void multiple_pack(int cost, int value, int quantity){
	if(quantity * cost >= m){
		complete_pack(cost, value);
		return;
	}
	int k = 1;
	while(k < quantity){
		zero_one_pack(cost * k, value * k);
		quantity -= k;
		k *= 2;	
	}
	zero_one_pack(cost * quantity, value * quantity);
}


void solve(){
	for(int i=0;i<n;i++){
		scanf("%d", &cost[i]);
	}
	for(int i=0;i<n;i++){
		scanf("%d", &quantity[i]);
	}
	
	memset(dp, 0, sizeof(dp));
	for(int i=0;i<n;i++){
		multiple_pack(cost[i], cost[i], quantity[i]);
	}
	int sum = 0;
	for(int i=1;i<=m;i++){
		//printf("[%d] ", dp[i]);
		if(dp[i] != dp[i-1]){
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
