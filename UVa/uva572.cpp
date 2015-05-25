#include <stdio.h>
#include <string.h>

const int MAX = 105;
const int D[8][2] = {
	{-1, -1}, {-1, 0}, {-1, 1}, 
	{0, -1}, {0, 1},
	{1, -1}, {1, 0}, {1, 1}
};

int mark[MAX][MAX];
char pix[MAX][MAX];
int id;
int n, m;

void dfs(int r, int c){
	if(pix[r][c] == '@' && mark[r][c] == -1){
		mark[r][c] = id;
		for(int i=0;i<8;i++){
			int tr = r + D[i][0];
			int tc = c + D[i][1];
			if(tr >= 0 && tr < m && tc >= 0 && tc < n){
				dfs(tr, tc);
			}
		}
	}
}

void solve(){
	for(int i=0;i<m;i++){
		scanf("%s", pix[i]);
	}
	memset(mark, -1, sizeof(mark));
	id = 0;
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			if(pix[i][j] == '@' && mark[i][j] == -1){
				id += 1;
				dfs(i, j);
			}
		}
	}
	printf("%d\n", id);
}

int main(void){
	freopen("uva572.in", "r", stdin);
	while(scanf("%d %d", &m, &n) != EOF){
		if(m == 0){
			break;
		}
		solve();
	}
	return 0;
}
