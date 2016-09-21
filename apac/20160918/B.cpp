#include <stdio.h>
#include <string.h>
#include <string>
#include <unordered_map>
#include <map>
#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>

using namespace std;

int a[3005][3005];
long long dp[3005][3005];
int R, C, K;

inline 
bool inside(int r, int c) {
	return r >= 0 && c >= 0 && r < R && c < C;
}

void solve(int kase){
	long long res = 0;
	scanf("%d %d %d\n", &R, &C, &K);
	memset(a, 0, sizeof(a));
	memset(dp, 0, sizeof(dp));
	for(int i=0; i<K; i+=1) {
		int r, c;
		scanf("%d %d", &r, &c);
		a[r][c] = 1;
	}
	for(int i=0; i<R; i+=1) {
		for(int j=0; j<C; j+=1) {
			if(a[i][j] == 0) {
				res += 1;
				dp[i][j] = 1;
				if(inside(i-1, j) && inside(i, j-1) && inside(i-1, j-1)) {
					res += min(min(dp[i-1][j], dp[i][j-1]), dp[i-1][j-1]);
					dp[i][j] += min(min(dp[i-1][j], dp[i][j-1]), dp[i-1][j-1]);
				}
			}
		}
	}
	cout << "Case #" << kase << ": " << res << endl;	
}

int main(int argc, char *argv[]){
	if(argc >= 2) {
		freopen(argv[1], "r", stdin);
	}else{
		freopen("B.in", "r", stdin);	
	}
	int kase;
	scanf("%d\n", &kase);
	for(int i=1; i<=kase; i+=1){
		solve(i);	
	}
	return 0;
}

