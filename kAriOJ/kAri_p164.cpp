#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

const int MAX = 11;
char a[MAX][MAX];
int D8[8][2] = {{-1, 0}, {-1, +1}, {0, 1}, {+1, +1}, {+1, 0}, {+1, -1}, {0, -1}, {-1, -1}};
int D4[4][2] = {{-1, 0}, {+1, 0}, {0, -1}, {0, +1}};
bool input(){
	for(int i=0;i<10;i+=1){
		scanf("%s", a[i]);
	}
	char t;
	if(scanf("%c", &t) == EOF){
		return false;
	}
	return true;
}

inline 
bool inside(int row, int col){
	return row >= 0 && col >= 0 && row < 10 && col < 10;
}

int calc_target(int row, int col){
	char x = a[row][col];
	if(x == '.') return 0;
	int sum = 0, tr, tc, s;
	for(int i=0;i<4;i+=1){
		s = 0;
		tr = row + D8[i][0]; tc = col + D8[i][1];
		while(inside(tr, tc) && a[tr][tc] == x){
			s += 1;	
			tr += D8[i][0]; tc += D8[i][1];
		}
		tr = row - D8[i][0]; tc = col - D8[i][1];
		while(inside(tr, tc) && a[tr][tc] == x){
			s += 1;	
			tr -= D8[i][0]; tc -= D8[i][1];
		}
		if(s >= 4){
			sum += s;	
		}
	}
	if(sum > 0) sum += 1;
	return sum;
}

struct node {
	int r, c;		
};
struct node q[MAX*MAX];
int qlen, p;
int mark[MAX][MAX];

int bfs(int row, int col){
	if(a[row][col] == '.') return 0;
//	printf("start: %d %d\n", row, col);
	memset(mark, 0, sizeof(mark));
	q[0].r = row;
	q[0].c = col;
	qlen = 1;
	p = 0;
	int res = 0;
	char x = a[row][col];
	a[row][col] = '.';
	mark[row][col] = 1;
	while(p < qlen){
		for(int i=0;i<4;i+=1){
			int tr = q[p].r + D4[i][0], tc = q[p].c + D4[i][1];
			if(inside(tr, tc) && mark[tr][tc] == 0 && a[tr][tc] == '.'){
				a[tr][tc] = x;
				res = max(res, calc_target(tr, tc));
//				printf("res=%d, (%d, %d)\n", res, tr, tc);
				a[tr][tc] = '.';
				
				mark[tr][tc] = 1;
				q[qlen].r = tr;
				q[qlen].c = tc;
				qlen += 1;
			}
		}
		p += 1;
	}
	a[row][col] = x;
	return res;
}

void solve(int kase){
//	for(int i=0;i<10;i+=1){
//		printf("i=%d %s\n", i, a[i]);
//	}
	
	printf("Case #%d: ", kase);
	
	for(int i=0;i<10;i+=1){
		for(int j=0;j<10;j+=1){
			if(a[i][j] != '.' && calc_target(i, j) >= 5){
				printf("Waiting!\n");
				return;
			}
		}
	}
	
	int res = 0;
	for(int i=0;i<10;i+=1){
		for(int j=0;j<10;j+=1){
			if(a[i][j] != '.'){
				res = max(res, bfs(i, j));
			}
		}
	}
	printf("%d\n", res);
}

int main(void){
	freopen("p164.in", "r", stdin);
	int kase = 1;
	input();
	do {
		if(kase > 1){
			printf("\n");	
		}
		solve(kase);
		kase += 1;
	} while(input());
	return 0;
}
