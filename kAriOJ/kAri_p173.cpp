#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <cmath>
 
using namespace std;
const int MAX = 1005;
 
char a[MAX], b[MAX];
int dp[MAX][MAX];
int n, k;

void input(){
    scanf("%s", (a+1));
    scanf("%s", (b+1));
}
 
void solve(){
    dp[0][0] = 0;
    for(int i=1; i<=n; i+=1){
    	dp[0][i] = dp[0][i-1] + (b[i] == '0' ? -1 : 1);
    	dp[i][0] = abs(dp[i-1][0]) > k ? 20000 : (dp[i-1][0] + (a[i] == '0' ? -1 : 1));
    }
    
    for(int i=1; i<=n; i+=1){
    	for(int j=1; j<=n; j+=1){
    		if(abs(dp[i-1][j]) > k && abs(dp[i][j-1]) > k){
    			dp[i][j] = 20000;
    		}else{
    			dp[i][j] = dp[i-1][j] + (a[i] == '0' ? -1 : 1);
    		}
    	}
	}
	
	if(abs(dp[n][n]) > k){
		printf("Poor Alice\n");	
		return;
	}
	int r = n, c = n, tr, tc;
	int res[MAX*2];
	int len = 0;
	while(r >= 0 && c >= 0){
		tr = r; tc = c - 1;
		if(tc >= 0 && abs(dp[tr][tc]) <= k){
			c -= 1;
			res[len++] = 2;
		}else if(abs(dp[r-1][c]) <= k){
			r -= 1;
			if(r >= 0){
				res[len++] = 1;
			}
		}else{
			printf("Poor Alice\n");	
			return;
		}
	}
	for(int i=len-1;i>=0;i-=1){
		printf("%d", res[i]);
	}
	printf("\n");
	
	for(int i=0; i<=n; i+=1){
		for(int j=0; j<=n; j+=1){
			printf("%5d ", dp[i][j]);	
		}
    	printf("\n");
	}
}
 
int main(void){
	freopen("p173.in", "r", stdin);
    while(scanf("%d %d\n", &n, &k) != EOF){
        input();
        solve();
    }
    return 0;
}
