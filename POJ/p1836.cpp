#include <stdio.h>
#include <string.h>

inline
int max(int a, int b){
	return a > b ? a : b;
}

const int MAX = 1005;

int n;
double a[MAX];
int dp1[MAX], dp2[MAX];

void solve(){
	memset(dp1, 0, sizeof(dp1));
	memset(dp2, 0, sizeof(dp2));
	for(int i=0;i<n;i++){
		int j, m = 0;
		for(j=i-1;j>=0;j--){
			if(a[j] < a[i]){
				m = max(m, dp1[j]);
			}
		}
		dp1[i] = m + 1;
	}
	for(int i=n-1;i>=0;i--){
		int j, m = 0;
		for(j=i+1;j<n;j++){
			if(a[j] < a[i]){
				m = max(m, dp2[j]);
			}
		}
		dp2[i] = m + 1;
	}
	
	int result = dp1[0] + dp2[1];
	for(int i=0;i<n-1;i++){
		for(int j=i+1;j<n;j++){
			result = max(result, dp1[i] + dp2[j]);
		}
	}
	printf("%d\n", n - result);
}

int main(void){
	freopen("p1836.in", "r", stdin);
	scanf("%d", &n);
	for(int i=0;i<n;i++){
		scanf("%f", &a[i]);
	}
	solve();
	return 0;
}
