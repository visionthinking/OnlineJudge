#include <stdio.h>
#include <string.h>

char line[100];

/* UDLR */
const int D[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

struct point {
	int exist;
	int d[4][3]; /* LRF */
};

struct node {
	int r, c;
	int move;
	int parent;	
};

const int MAX = 20;
struct point a[MAX][MAX];
struct node q[100000];

inline 
int getD(char x){
	int p = 0;
	if(x == 'S'){
		p = 0;
	}else if(x == 'N'){
		p = 1;
	}else if(x == 'E'){
		p = 2;
	}else if(x == 'W'){
		p = 3;
	}
	return p;
}

inline 
int getDD(int dr, int dc){
	int d;
	if(dr == -1){
		d = 0;
	}else if(dr == 1){
		d = 1;
	}else if(dc == -1){
		d = 2;
	}else if(dc == 1){
		d = 3;
	}
	return d;
}

void solve(){
	int startR, startC, endR, endC, r, c, p, t, len;
	char startD, x;
	
	memset(a, 0, sizeof(a));
	
	scanf("%d %d %c %d %d\n", &startR, &startC, &startD, &endR, &endC);
	while(1){
		scanf("%d ", &r);
		if(r == 0){
			break;
		}
		scanf("%d ", &c);
		while(1){
			scanf("%c", &x);
			if(x == '*' || x == '\n'){
				break;
			}else if(x == 'L'){
				a[r][c].d[p][0] = 1;
			}else if(x == 'R'){
				a[r][c].d[p][1] = 1;
			}else if(x == 'F'){
				a[r][c].d[p][2] = 1;
			}else{
				p = getD(x);
				a[r][c].exist = 1;
			}
		}
	}
	
	p = 1;
	len = 2;
	q[0].r = startR;
	q[0].c = startC;
	q[0].parent = -1;
	q[1].r = startR + D[getD(startD)][0];
	q[1].c = startC + D[getD(startD)][1];
	q[1].move = getD(startD);
	q[1].parent = 0;
	
	if(!a[q[1].r][q[1].c].exist){
		printf(" No Solution Possible\n");
		return;
	}
	
	int dr, dc, parent;
	while(p < len){
		parent = q[p].parent;
		
	}
}

int main(void){
	freopen("uva816.in", "r", stdin);
	while(scanf("%s", line) != EOF){
		if(strcmp(line, "END") == 0){
			break;
		}
		printf("%s\n", line);
		solve();
	}
	return 0;
}
