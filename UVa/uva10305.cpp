#include <stdio.h>
#include <string.h>

const int MAX = 105;
int n, m;
int a[MAX][MAX];
int access[MAX];
//0 for unaccess, 1 for accessed, -1 for accessing
int result[MAX], p;

bool dfs(int x){
	access[x] = -1;
	for(int i=1;i<=n;i++){
		if(a[x][i]){
			if(access[i] == -1){
				return false;	
			}else if(access[i] == 0 && !dfs(i)){
				return false;	
			}
		}
	}
	
	access[x] = 1;
	result[--p] = x;
	return true;
}

void solve(){
	memset(access, 0, sizeof(access));
	p = n;
	
	for(int i=1;i<=n;i++){
		if(access[i] == 0){
			if(!dfs(i)){
				return;
			}
		}
	}
	for(int i=0;i<n;i++){
		if(i>0) printf(" ");
		printf("%d", result[i]);
	}
	printf("\n");
}

int main(void){
	freopen("uva10305.in", "r", stdin);
	while(scanf("%d %d", &n, &m) != EOF && n | m){
		memset(a, 0, sizeof(a));
		int x, y;
		for(int i=0;i<m;i++){
			scanf("%d %d", &x, &y);
			a[x][y] = 1;
		}
		solve();
	}
	return 0;
}


