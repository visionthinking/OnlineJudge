/* uva437: DAG DP, longest path */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
	int x, y, h;
};

const int MAX = 95;
int a[MAX][MAX];
int b[MAX];
struct node ns[MAX];
int n;

inline
void swap(int & a, int & b){
	int t = a;
	a = b;
	b = t;
}

inline 
int max(int a, int b){
	return (a > b) ? a : b;	
}

void input(){
	n = n*3;
	for(int i=0;i<n;i+=3){
		scanf("%d%d%d", &ns[i].x, &ns[i].y, &ns[i].h);
		memcpy(&ns[i+1], &ns[i], sizeof(struct node));
		swap(ns[i+1].x, ns[i+1].h);
		memcpy(&ns[i+2], &ns[i], sizeof(struct node));
		swap(ns[i+2].y, ns[i+2].h);
	}
}

inline
bool suit(const struct node & b, const struct node & a){
	return (a.x < b.x && a.y < b.y) || (a.y < b.x && a.x < b.y);
}

int dfs(int x){
	if(b[x] != -1) return b[x];
	int m = 0;
	for(int i=0;i<n;i+=1){
		if(a[x][i]){
			m = max(m, dfs(i));
		}
	}
	return b[x] = ns[x].h + m;
}

void solve(int kase){
	/* build graph */
	memset(a, 0, sizeof(a));
	for(int i=0;i<n;i+=1){
		for(int j=0;j<n;j+=1){
			if(suit(ns[i], ns[j])){
				a[i][j] = 1;
			}
		}
	}
	/* print graph
	for(int i=0;i<n;i+=1){
		for(int j=0;j<n;j+=1){
			printf("%d ", a[i][j]);
		}
		printf("\n");
	}
	*/
	memset(b, -1, sizeof(b));
	int m = 0;
	for(int i=0;i<n;i+=1){
		m = max(m, dfs(i));
	}
	printf("Case %d: maximum height = %d\n", kase, m);
}

int main(void){
	freopen("uva437.in", "r", stdin);
	int kase = 1;
	while(scanf("%d", &n) != EOF && n != 0){
		input();
		solve(kase);
		kase += 1;
	}
	return 0;
}
