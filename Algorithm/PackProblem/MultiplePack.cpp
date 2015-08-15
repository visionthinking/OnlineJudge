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

void complete_pack(int cost, int value){
	for(int i=cost;i<=capacity;i++){
		dp[i] = max(dp[i], dp[i-cost] + value);
	}	
}

void multiple_pack(int cost, int value, int quantity){
	if(cost * quantity >= capacity){
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
	int cost[MAX], value[MAX], quantity[MAX];
	int n;
	
	scanf("%d %d", &n, &capacity);
	for(int i=0;i<n;i++){
		scanf("%d %d %d", &cost[i], &value[i], &quantity[i]);
	}
	
	memset(dp, 0, sizeof(dp));
	for(int i=0;i<n;i++){
		zero_one_pack(cost[i], value[i]);
	}
	printf("ZeroOnePack: %d\n", dp[capacity]);
	
	memset(dp, 0, sizeof(dp));
	for(int i=0;i<n;i++){
		complete_pack(cost[i], value[i]);
	}
	printf("CompletePack: %d\n", dp[capacity]);
	
	memset(dp, 0, sizeof(dp));
	for(int i=0;i<n;i++){
		multiple_pack(cost[i], value[i], quantity[i]);
	}
	printf("MultiplePack: %d\n", dp[capacity]);
}

int main(void){
	freopen("MultiplePack.in", "r", stdin);
	solve();
	return 0;
}
