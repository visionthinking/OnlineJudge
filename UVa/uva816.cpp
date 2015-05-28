#include <stdio.h>
#include <string.h>

char line[100];

#define UP 0
#define DOWN 1
#define LEFT 2
#define RIGHT 3
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
const int MAXQ = 100000;
struct point a[MAX][MAX];
struct node q[MAXQ];
int rr[MAXQ], cc[MAXQ];
int startR, startC, endR, endC;
char startD;
int qp, len;

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
int getDD(int r, int c, int pr, int pc){
	int dr = r - pr;
	int dc = c - pc;
	int d = 0;
	if(dr == 1){
		d = 0;
	}else if(dr == -1){
		d = 1;
	}else if(dc == 1){
		d = 2;
	}else if(dc == -1){
		d = 3;
	}
	return d;
}

void print_way(int n){
	int cnt = 0;
	
	rr[cnt] = endR;
	cc[cnt] = endC;
	cnt += 1;
	for(;n != -1;n = q[n].parent){
		rr[cnt] = q[n].r;
		cc[cnt] = q[n].c;
		cnt += 1;
	}
	
	int id = 0;
	for(int i=cnt-1;i>=0;i--){
		if(id % 10 == 0){
			printf("\n ");
		}
		printf(" (%d,%d)", rr[i], cc[i]);
		id += 1;
	}
	printf("\n");
}

bool push(int nr, int nc){
	const struct node & curr = q[qp];
	if(nr == endR && nc == endC){
		print_way(qp);
		return true;
	}
	if(a[nr][nc].exist){
		q[len].r = nr;
		q[len].c = nc;
		q[len].parent = qp;
		q[len].move = getDD(nr, nc, curr.r, curr.c);
		bool flag = true;
		for(int i=0;i<len;i++){
			if(q[i].r == nr && q[i].c == nc && q[i].move == q[len].move){
				flag = false;
				break;	
			}
		}
		if(flag){
			len += 1;
		}
	}
	return false;
}

void bfs(){
	qp = 1;
	len = 2;
	q[0].r = startR;
	q[0].c = startC;
	q[0].parent = -1;
	q[0].move = -1;
	q[1].r = startR - D[getD(startD)][0];
	q[1].c = startC - D[getD(startD)][1];
	q[1].move = getD(startD);
	q[1].parent = 0;
	
	if(q[1].r == endR && q[1].c == endC){
		/* hack. fix bug */
		printf("\n  (%d,%d) (%d,%d)\n", startR, startC, endR, endC);
		return;		
	}
	if(!a[q[1].r][q[1].c].exist){
		printf("\n  No Solution Possible\n");
		return;
	}
	
	int dr, dc, parent, nr, nc;
	while(qp < len){
		const struct node & curr = q[qp];
		int * curr_pnt = a[curr.r][curr.c].d[curr.move];
		dr = curr.r - q[curr.parent].r;
		dc = curr.c - q[curr.parent].c;
		if(curr_pnt[0]){
			//L
			nr = curr.r - dc;
			nc = curr.c + dr;
			if(push(nr, nc)){
				return;	
			}
		}
		if(curr_pnt[1]){
			//R
			nr = curr.r + dc;
			nc = curr.c - dr;
			if(push(nr, nc)){
				return;	
			}
		}
		if(curr_pnt[2]){
			//F
			nr = curr.r + dr;
			nc = curr.c + dc;
			if(push(nr, nc)){
				return;	
			}
		}
		
		qp += 1;
	}
	printf("\n  No Solution Possible\n");
}

void solve(){
	int r, c, p, t;
	char x, ss[99];
	
	memset(a, 0, sizeof(a));
	
	scanf("%d %d %s %d %d\n", &startR, &startC, ss, &endR, &endC);
	startD = ss[0];
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
	
	bfs();
}

int main(void){
	freopen("uva816.in", "r", stdin);
	while(scanf("%s", line) != EOF){
		if(strcmp(line, "END") == 0){
			break;
		}
		printf("%s", line);
		solve();
	}
	return 0;
}
