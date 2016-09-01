#include <stdio.h>
#include <string.h>
#include <string>
#include <algorithm>

using namespace std;

#define MAX 100

int a[MAX][MAX];
int mark[MAX][MAX];
int row, col;
int max_value;

void print(){
	for(int i=0; i<row; i+=1){
		for(int j=0; j<col; j+=1){
			printf("%d ", a[i][j]);
		}
		printf("\n");
	}
}

bool is_near_sea(int r, int c){
	return r == 0 || c == 0 || r == row-1 || c == col-1;
}

const int D[4][2] = {
	{-1, 0}, {0, 1}, {1, 0}, {0, -1}
};

struct node {
	int r, c;
};
struct node q[3000];
int qlen;

// return res+
int bfs(int r, int c){
	int init_value, min_value, p;
	memset(mark, 0, sizeof(mark));
	
	init_value = a[r][c];
	min_value = max_value;
	mark[r][c] = 1;
	
	qlen = 1;
	q[0].r = r;
	q[0].c = c;
	p = 0;
	
	while(p < qlen){
		struct node & curr = q[p];
		for(int i=0; i<4; i+=1){
			int tr = curr.r + D[i][0];
			int tc = curr.c + D[i][1];
			if(mark[tr][tc] == 0){
				if(a[tr][tc] <= init_value){
					if(is_near_sea(tr, tc)){
						return 0;	
					}
					q[qlen].r = tr;
					q[qlen].c = tc;
					mark[tr][tc] = 1;
					qlen += 1;
				}else{
					min_value = min(a[tr][tc], min_value);	
				}
			}
		}
		p += 1;	
	}
	
	int res = 0;
	if(min_value > init_value){
		for(int i=0; i<qlen; i+=1){
			res += min_value - a[q[i].r][q[i].c];
			a[q[i].r][q[i].c] = min_value;
		}
	}
	return res;
}

void solve(int kase){
	scanf("%d %d", &row, &col);
	max_value = 0;
	for(int i=0; i<row; i+=1){
		for(int j=0; j<col; j+=1){
			scanf("%d", &a[i][j]);
			max_value = max(max_value, a[i][j]);
		}
	}
	
	int res = 0;
	for(int i=1; i<row-1; i+=1){
		for(int j=1; j<col-1; j+=1){
			res += bfs(i, j);
		}
	}
	// print();
	printf("Case #%d: %d\n", kase, res);
}

int main(void){
	freopen("B-large.in", "r", stdin);
	int kase;
	scanf("%d", &kase);
	for(int i=1; i<=kase; i+=1){
		solve(i);	
	}
	return 0;
}
