#include <stdio.h>
#include <string.h>
#include <algorithm>
 
using namespace std;
const int MAX = 1005;

int a[MAX][MAX];
int n;
int D[4][2] = {{0, +1}, {+1, 0}, {0, -1}, {-1, 0}};

inline bool inside(int row, int col){
	return row >= 0 && col >=0 && row < n && col < n;
}

void solve(){
	memset(a, 0, sizeof(a));
	
	int d = 0, r = 0, c = 0, tr, tc;
	a[0][0] = 1;
	for(int i=2; i<=n*n; i+=1){
		tr = r + D[d][0]; tc = c + D[d][1];
		if(inside(tr, tc) && a[tr][tc] == 0){
			r = tr; c = tc;
		}else{
			d = (d + 1) % 4;
			r += D[d][0]; c += D[d][1];
		}
		a[r][c] = i;
	}
	
	for(int i=0; i<n; i+=1){
		for(int j=0; j<n; j+=1){
			printf("%3d ", a[i][j]);
		}
		printf("\n");
	}
}

int main(void){
	n = 5;
	solve();
	return 0;
}
