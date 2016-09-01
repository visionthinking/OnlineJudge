#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <limits.h>
#include <vector>
#include <utility>

using namespace std;

const int MAX = 500;

struct graph {
	int w[MAX][MAX];
	int n;
};

void build_graph(struct graph & g) {
	scanf("%d", &g.n);
	for(int i=0; i<g.n; i+=1){
		for(int j=0; j<g.n; j+=1){
			scanf("%d", &g.w[i][j]);
			if(g.w[i][j] == -1){
				g.w[i][j] = INT_MAX;
			}
		}
	}
}

struct node {
	int cost;
	int id, parent, cnt;
};
struct node q[MAX * MAX];
int qlen;
int mark[MAX];

int get_min_2_sum(int * a, int len) {
	int sum = 0;
	int b[MAX];
	memcpy(b, a, sizeof(int) * len);
	nth_element(b, b + 2, b + len);
	for(int i=0; i<2; i+=1){
		sum += b[i];
	}
	return sum;
}

int get_lower_bound(struct graph & g) {
	int lb = 0;
	for(int i=0; i<g.n; i+=1){
		lb += get_min_2_sum(g.w[i], g.n);
	}
	return (lb % 2 == 0) ? lb / 2 : (lb + 1) / 2;
}

int get_upper_bound(struct graph & g) {
	int ub = 0;
	int p = 0, cnt = 0;
	memset(mark, 0, sizeof(mark));
	mark[0] = 1;
	while(cnt < g.n){
		int m = INT_MAX, mi = 0;
		for(int i=0; i<g.n; i+=1){
			if(mark[i] == 0){
				if(g.w[p][i] <= m){
					mi = i;
					m = g.w[p][i];
				}
			}
		}
		cnt += 1;
		if( cnt == g.n ){
			mi = 0;
			m = g.w[p][mi];
		}
		ub += m;
		p = mi;
		mark[p] = 1;
//		printf("m=%d p=%d\n", m, p);
	}
	return ub;
}

bool check_path_has(int p, int id){
	if(p == id){
		return true;	
	}
	do {
		p = q[p].parent;
		if(p == id) return true;
	} while(p != -1);
	return false;
}

void get_path(int p, vector< int > & path){
	path.clear();
	do {
		if (p != -1) {
			path.push_back( p );
		}
		p = q[p].parent;
	} while(p != -1);
	reverse(path.begin(), path.end());
}

void select_smallest_2(int * a, int len, int & min_1, int & min_2) {
	int b[MAX];
	memcpy(b, a, sizeof(int) * len);
	nth_element(b, b+2, b+len);
	min_1 = b[0];
	min_2 = b[1];
}

int get_lower_bound(struct graph & g, vector< int > & path) {
	int lb = 0;
	for(int i=0; i<g.n; i+=1){
		int min_1, min_2;
		select_smallest_2(g.w[i], g.n, min_1, min_2);
		
		for(int j=0; j<path.size()-1; j+=1){
			int p1 = path[j], p2 = path[j+1];
			if(p1 == i){
				
			}
		}
	}
	return (lb % 2 == 0) ? lb / 2 : (lb + 1) / 2;
}



int brand_and_bound(struct graph & g, int start_id, int lb, int ub){
	qlen = 1;
	q[0].cost = 0;
	q[0].id = start_id;
	q[0].parent = -1;
	q[0].cnt = 1;
	int p = 0, m = ub;
	memset(mark, 0, sizeof(mark));
	mark[start_id] = 1;
	while(p < qlen){
		if(q[p].cnt == g.n){
			m = min(m, q[p].cost);
		}
		int id = q[p].id;
		mark[id] = 1;
		for(int i=0; i<g.n; i+=1){
			int cost = q[p].cost + g.w[id][i];
			if(mark[i] == 0 && cost <= ub && !check_path_has(p, i)){
				q[qlen].cost = cost;
				q[qlen].id = i;
				q[qlen].parent = id;
				q[qlen].cnt = q[p].cnt + 1;
				qlen += 1;	
			}
		}
		p += 1;
		printf("p=%d qlen=%d\n", p, qlen);
	}
	return m;
}

void solve_brand_and_bound(struct graph & g) {
	int lb = get_lower_bound(g);
	int ub = get_upper_bound(g);
	printf("[lb, ub] = [%d, %d]\n", lb, ub);
	int r = brand_and_bound(g, 0, lb, ub);
	printf("result=%d\n", r);
}

int main(void){
	freopen("TSP.in", "r", stdin);
	struct graph g;
	build_graph(g);
	solve_brand_and_bound(g);
	return 0;
}


