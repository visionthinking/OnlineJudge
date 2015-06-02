/* MST Kruskal Algorithm */
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

const int MAX_E = 4040400;
const int MAX_V = 2020205;

struct edge {
	int v1, v2;
	int weight;	
};
struct edge E[MAX_E];
int E_len, V_len;

int parent[MAX_V];

int union_find(int v){
	if(parent[v] == v) 
		return v;
	return parent[v] = union_find(parent[v]);
}

void union_merge(int v1, int v2){
	parent[union_find(v1)] = union_find(v2);
}

void union_init(){
	for(int i=0;i<V_len;i++){
		parent[i] = i;
	}
}

bool edge_cmp(const struct edge & e1, const struct edge & e2){
	return e1.weight < e2.weight;
}

void kruskal_algorithm(){
	/* 1. sort edges by weights */
	sort(E, E + E_len, edge_cmp);
	
	/* 2. initialize the union set */
	union_init();
	
	/* 3. traverse the edges(u, v), if find(u) != find(v), then merge them.  */
	int cnt = V_len;
	int sum = 0;
	for(int i=0;i<E_len && cnt>1;i++){
		int v1 = E[i].v1, v2 = E[i].v2;
		if(union_find(v1) != union_find(v2)){
			union_merge(v1, v2);
			cnt -= 1;
			sum += E[i].weight;	
		}
	}
	printf("%d\n", sum);
}

/* HDOJ 5253 */
int pix[1010][1010];
int w, h;

inline
int getid(int r, int c){
	return w*r+c+0;
}

inline
int inside(int r, int c){
	return r>=0 && c>=0 && r<h && c<w;
}

void input(){
	int x, n, m;
	scanf("%d %d", &h, &w);
	for(int i=0;i<h;i++){
		for(int j=0;j<w;j++){
			scanf("%d", &pix[i][j]);
		}
	}
	
	m = 0;
	for(int i=0;i<h;i++){
		for(int j=0;j<w;j++){
			if(inside(i-1, j)){
				E[m].v1 = getid(i, j);
				E[m].v2 = getid(i-1, j);
				E[m].weight = abs(pix[i][j] - pix[i-1][j]);
				m += 1;
			}
			if(inside(i, j+1)){
				E[m].v1 = getid(i, j);
				E[m].v2 = getid(i, j+1);
				E[m].weight = abs(pix[i][j] - pix[i][j+1]);
				m += 1;
			}
		}
	}
	
	n = w * h;
	
	E_len = m;
	V_len = n;
}


int main(void){
	freopen("KruskalAlgorithm.in", "r", stdin);
	int t;
	scanf("%d", &t);
	for(int i=1;i<=t;i++){
		printf("Case #%d:\n", i);
		input();
		kruskal_algorithm();
	}
	return 0;
}
