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
int visit[50][50];
int R, C, sr, sc, S;
LD P, Q;
char t;

void print() {
	for(int i=0; i<R; i+=1) {
		for(int j=0; j<C; j+=1) {
			printf("%c", a[i][j]);
		}
		printf("\n");
	}	
}

int D[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
LD powp[20], powq[20];

LD res;
void dfs(int r, int c, int step, LD curr_res) {
	if(step >= S) return;
//	printf("(%d, %d) step = %d\n", r, c, step);
	
	for(int i=0; i<4; i+=1) {
		int tr = D[i][0] + r, tc = D[i][1] + c;
		if(tr >= 0 && tc >= 0 && tr < R && tc < C) {
			int v = visit[tr][tc];
			if(a[tr][tc] == 'A') {
				LD _res = curr_res + powp[v];
				res = max(res, _res);
				visit[tr][tc] += 1;
				dfs(tr, tc, step + 1, _res);
				visit[tr][tc] -= 1;
			} else {
				LD _res = curr_res + powq[v];
				res = max(res, _res);
				visit[tr][tc] += 1;
				dfs(tr, tc, step + 1, _res);
				visit[tr][tc] -= 1;
			}
		}
	}
}

void solve(int kase){
	scanf("%d%d%d%d%d\n", &R, &C, &sr, &sc, &S);
	cin >> P >> Q;
	scanf("\n");
	for(int i=0; i<R; i+=1) {
		for(int j=0; j<C; j+=1) {
			scanf("%c%c", &a[i][j], &t);
		}
	}
	for(int i=0; i<=15; i+=1) {
		powp[i] = P * pow(1.0-P, (LD)i);
		powq[i] = Q * pow(1.0-Q, (LD)i);
	}
	memset(visit, 0, sizeof(visit));
	res = 0.0;
	dfs(sr, sc, 0, res);
	cout << "Case #" << kase << ": " << setprecision(10) << fixed << res << endl;
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

