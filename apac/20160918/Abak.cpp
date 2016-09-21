#include <stdio.h>
#include <string.h>
#include <string>
#include <unordered_map>
#include <map>
#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>

using namespace std;

typedef long double LD;

char a[50][50];
int r, c, sr, sc, s;
LD P, Q;
char t;

void print() {
	for(int i=0; i<r; i+=1) {
		for(int j=0; j<c; j+=1) {
			printf("%c", a[i][j]);
		}
		printf("\n");
	}	
}

struct node {
	int r, c;
	int parent;
	int step;
	LD res;
	
	void set(int _r, int _c, int _parent, int _step, LD _res) {
		r = _r; c = _c; parent = _parent; step = _step; res = _res;
	}
};

node q[2000000];
int D[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
LD pw[10];

int visit_count(int p, int tr, int tc, LD& prob) {
	
}

LD bfs() {
	LD res = 0.0;
	int qlen = 1, p = 0;
	q[0].set(sr, sc, -1, 0, 0.0);
	while(p < qlen) {
		node & curr = q[p];
		if(curr.step < s) {
			for(int i=0; i<4; i+=1) {
				int tr = D[i][0] + curr.r, tc = D[i][1] + curr.c;
				if(tr >= 0 && tc >= 0 && tr < r && tc < c) {
					if(a[tr][tc] == '.') {
						LD prob = q;
						int visits = visit_count(p, tr, tc, prob);
						LD curr_res = curr.res + 
						q[qlen].set(tr, tc, p, curr.step + 1, curr.res + )
						qlen += 1;	
					} else {
							
					}
				}
			}
		}
		p += 1;
	}
	return res;
}

void dfs(int ) {
		
}

void solve(int kase){
	scanf("%d%d%d%d%d\n", &R, &C, &sr, &sc, &S);
	scanf("%lf%lf\n", &P, &Q);
	for(int i=0; i<R; i+=1) {
		for(int j=0; j<C; j+=1) {
			scanf("%c%c", &a[i][j], &t);
		}
	}
	cout << "Case #" << kase << ": " << setprecision(10) << fixed << bfs() << endl;
}

int main(int argc, char *argv[]){
	if(argc >= 2) {
		freopen(argv[1], "r", stdin);
	}else{
		freopen("A.in", "r", stdin);	
	}
	int kase;
	scanf("%d\n", &kase);
	for(int i=1; i<=kase; i+=1){
		solve(i);	
	}
	return 0;
}

