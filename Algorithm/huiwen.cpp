#include <stdio.h>
#include <string.h>
#include <algorithm>
 
using namespace std;
const int MAX = 1005;

char a[MAX], b[MAX];
int dp[MAX][MAX];
int len;

int LCS(char * a, char * b, int len){
	memset(dp, 0, sizeof(dp));
	for(int i=1; i<=len; i+=1){
		for(int j=1; j<=len; j+=1){
			dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
			dp[i][j] = max(dp[i][j], dp[i-1][j-1] + (a[i] == b[j] ? 1 : 0));
		}
	}
	return dp[len][len];
}

int main(void){
	freopen("huiwen.in", "r", stdin);
	scanf("%s", a+1);
	len = strlen(a+1);
	strcpy(b+1, a+1);
	reverse(b+1, b+1 + len);
	printf("%d\n", LCS(a, b, len));
	return 0;
}
