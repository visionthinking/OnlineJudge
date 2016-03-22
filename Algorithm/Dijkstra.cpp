#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int MAX = 1024;
const int MAX_INT = 1 << 30;
struct edge {
	int n1, n2, w;
};
int g[MAX][MAX];
struct edge e[MAX];
int es, n;

// for dijkstra
int label[MAX];
int score[MAX];
int open[MAX];
int parent[MAX];
int len;

void input(){
	memset(g, -1, sizeof(g));
	for(int i=0;i<es;i+=1){
		scanf("%d %d %d", &e[i].n1, &e[i].n2, &e[i].w);
		g[e[i].n1][e[i].n2] = e[i].w;
		printf("%d %d %d\n", e[i].n1, e[i].n2, e[i].w);
	}
}

int pop_min(int * open, int * score, int len){
	int m = 0, x;
	for(int i=1;i<len;i+=1){
		if (score[open[m]] > score[open[i]]){
			m = i;
		}
	}
	x = open[m];
	open[m] = open[len - 1];
	return x;
}

void dijkstra(int start){
	memset(label, 0, sizeof(label));
	memset(open, 0, sizeof(open));
	for(int i=0;i<=n;i+=1) {
		score[i] = MAX_INT;
	}
	
	label[start] = 1;
	score[start] = 0;
	parent[start] = -1;
	open[0] = start;
	len = 1;
	
	int count = 0;
	while (count < n) {
		int p = pop_min(open, score, len);
		label[p] = 1;
		len -= 1;
		for(int i=1;i<=n;i+=1){
			if(g[p][i] != -1 && label[i] == 0){
				if(score[i] > g[p][i] + score[p]){
					score[i] = g[p][i] + score[p];
					parent[i] = p;
					open[len++] = i;
				}
			}
		}
		count += 1;
	}
	for(int i=1;i<=n;i+=1){
		printf("[%d] parent: %3d score: %3d\n", i, parent[i], score[i]);	
	}
}

void output(int start){
	int r[MAX], rs;
	for(int i=1;i<=n;i+=1){
		if(start == i) continue;
		int p = i;
		rs = 0;
		while(p != start){
			r[rs++] = p;
			p = parent[p];
		}
		r[rs++] = start;
		for(int j=rs-1;j>=0;j-=1){
			printf("%d", r[j]);
			if(j > 0) printf(" -> ");
		}
		printf("\n");
	}
}

void solve(){
	int start = 1;
	dijkstra(start);
	output(start);
}

int main(void){
	freopen("graph.in", "r", stdin);
	while(scanf("%d %d", &n, &es) != EOF){
		input();
		solve();
	}
	return 0;	
}


