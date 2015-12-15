/* uva116, dp */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct node {
	int value;
	long long sum;
	int next_row;
	bool operator<(const struct node & b) { return sum < b.sum; };
};

int row, col;
struct node a[20][105];

void input(){
	memset(a, 0, sizeof(a));
	for(int i=0;i<row;i+=1){
		for(int j=0;j<col;j+=1){
			scanf("%d", &a[i][j].value);
		}
	}
}

void solve(){
	for(int i=0;i<row;i+=1){
		a[i][col-1].sum = a[i][col-1].value;
	}
	for(int j=col-2;j>=0;j-=1){
		for(int i=0;i<row;i+=1){
			int t;
			t = (row + i - 1) % row;
			a[i][j].next_row = t;
			a[i][j].sum = a[i][j].value + a[t][j+1].sum;
			for(int k=0;k<=1;k+=1){
				t = (row + i + k) % row;
				if(a[i][j].value + a[t][j+1].sum < a[i][j].sum
				  || (a[i][j].value + a[t][j+1].sum == a[i][j].sum && t < a[i][j].next_row)){
					a[i][j].next_row = t;
					a[i][j].sum = a[i][j].value + a[t][j+1].sum;
				}
			}
		}
	}
	int argm = 0;
	for(int i=1;i<row;i+=1){
		if(a[i][0].sum < a[argm][0].sum){
			argm = i;	
		}
	}
	printf("%d", argm + 1);
	for(int i=1, n=a[argm][0].next_row;i<col;i+=1){
		printf(" %d", n + 1);
		n = a[n][i].next_row;
	}
	printf("\n");
	printf("%lld\n", a[argm][0].sum);
}

int main(void){
	freopen("uva116.in", "r", stdin);
	while(scanf("%d %d", &row, &col) != EOF){
		input();
		solve();
	}
	return 0;	
}
