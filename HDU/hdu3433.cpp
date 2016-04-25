/* 
HDU3433. A Task Process

There are two kinds of tasks, namely A and B.
There are N workers and the i-th worker would like to finish one task A 
in ai minutes, one task B in bi minutes. Now you have X task A and Y task B,
you want to assign each worker some tasks and finish all the tasks as soon 
as possible. You should note that the workers are working simultaneously.
*/

#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <algorithm>
using namespace std;

const int MAXN = 55;
const int MAXXY = 205;
int n, x, y;
int A[MAXN], B[MAXN];
int F[MAXN][MAXXY], dp[MAXN][MAXXY];

bool is_valid(int T){
	for(int i=0; i<=n; i+=1){
		for(int j=0; j<=x; j+=1){
			F[i][j] = -214748364;
			dp[i][j] = -214748364;
		}
	}
	for(int i=1; i<=n; i+=1){
		for(int j=0; j<=x && T>=j*A[i]; j+=1){
			F[i][j] = (T - j*A[i]) / B[i];
		}
	}
	dp[0][0] = 0;
	for(int i=1; i<=n; i+=1){
		for(int u=0; u<=x; u+=1){
			for(int k=0; k<=u; k+=1){
				// u = k + u-k
				dp[i][u] = max(dp[i][u], dp[i-1][k] + F[i][u-k]);
			}
		}
	}
	/*
	printf("T=%d\n", T);
	for(int i=1; i<=n; i+=1){
		for(int j=0; j<=x; j+=1){
			if(F[i][j] < 0){
				printf(" - ");
			}else{
				printf("%2d ", F[i][j]);
			}
		}
		printf("\n");
	}
	printf("------\n");
	for(int i=0; i<=n; i+=1){
		for(int j=0; j<=x; j+=1){
			if(dp[i][j] < 0){
				printf(" - ");
			}else{
				printf("%2d ", dp[i][j]);
			}
		}
		printf("\n");
	}
	printf("\n");
	*/
	return dp[n][x] >= y;
}

void solve(int kase){
	scanf("%d %d %d", &n, &x, &y);
	for(int i=1; i<=n; i+=1){
		scanf("%d %d", &A[i], &B[i]);
	}
	
	int min_bound = 0, max_bound = A[1]*x+B[1]*y;
	// printf("bound: [%d, %d]\n", min_bound, max_bound);
	while(min_bound < max_bound){
		int m = min_bound + (max_bound - min_bound) / 2;
		if(is_valid(m)){
			max_bound = m;
		}else{
			min_bound = m+1;	
		}
	}
	printf("Case %d: %d\n", kase, min_bound);
}

int main(void){
	freopen("hdu3433.in", "r", stdin);
	int kase;
	while(scanf("%d", &kase) != EOF){
		for(int i=1; i<=kase; i+=1){
			solve(i);
		}
	}
	return 0;	
}
