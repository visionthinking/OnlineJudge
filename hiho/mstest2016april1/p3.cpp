/* HihoCoder #1290 : Demo Day */
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <algorithm>
using namespace std;

const int MAX = 105;
int n, m;
char a[MAX][MAX];

struct node {
	int r, d;
} dp[MAX][MAX];

void print(){
	for(int i=0; i<=n; i+=1){
		for(int j=0; j<=m; j+=1){
			printf("%c", a[i][j]);
		}
		printf("\n");
	}
}

void print_dp(){
	for(int i=0; i<n; i+=1){
		for(int j=0; j<m; j+=1){
			printf("%c[%2d,%2d] ", a[i][j], dp[i][j].r, dp[i][j].d);
		}
		printf("\n");
	}
}

inline int is_block(int r, int c){
	return a[r][c] == 'b' ? 1 : 0;
}

inline int not_block(int r, int c){
	return a[r][c] == 'b' ? 0 : 1;
}

void solve(){
	for(int i=0; i<n; i+=1) a[i][m] = 'b';
	for(int i=0; i<m; i+=1) a[n][i] = 'b';
//	print();
	
	dp[0][0].r = is_block(0, 0);
	dp[0][0].d = is_block(0, 0) + not_block(0, 1);
	
	for(int c=1; c<m; c+=1) {
		dp[0][c].r = dp[0][c-1].r + is_block(0, c);
		dp[0][c].d = dp[0][c-1].r + is_block(0, c) + not_block(0, c+1);
	}
	for(int r=1; r<n; r+=1) {
		dp[r][0].d = dp[r-1][0].d + is_block(r, 0);
		dp[r][0].r = dp[r-1][0].d + is_block(r, 0) + not_block(r+1, 0);
	}
	
	
	for(int r=1; r<n; r+=1){
		for(int c=1; c<m; c+=1){
			dp[r][c].d = min(
				dp[r-1][c].d + is_block(r, c), 
				dp[r][c-1].r + is_block(r, c) + not_block(r, c+1)
			);
			dp[r][c].r = min(
				dp[r][c-1].r + is_block(r, c), 
				dp[r-1][c].d + is_block(r, c) + not_block(r+1, c)
			);
		}
	}
//	print_dp();
	printf("%d\n", min(dp[n-1][m-1].d, dp[n-1][m-1].r));
}

int main(void){
	freopen("p3.in", "r", stdin);
	scanf("%d %d\n", &n, &m);
	for(int i=0;i<n;i+=1){
		scanf("%s", a[i]);
	}
	solve();
	return 0;
}
