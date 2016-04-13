#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <cmath>

using namespace std;
 
const int MAX = 30;
int k, xr, xc, n;
int row, col, min_col;
char a[MAX][MAX];
int b[MAX][MAX];

struct node {
	int r, c;	
};

void input(){
	scanf("%d %d %d", &row, &col, &k);
    for(int i=0;i<row;i+=1){
    	scanf("%s", a[i]);
    }
//    for(int i=0;i<row;i+=1){
//    	printf("%s\n", a[i]);
//    }
    for(int i=0;i<row;i+=1){
    	for(int j=0;j<col;j+=1){
    		if(a[i][j] == 'x'){
    			xr = i;
    			xc = j;
    			return;
    		}
    	}
	}
}

bool inside(int r, int c){
	return (r >= 0) && (c >= 0) && (r < row) && (c < col);
}

bool is_clear_row(int r, int c1, int c2){
	for(int i=c1;i<=c2;i+=1){
		if(a[r][i] == 'y'){
			return false;
		}
	}
	return true;
}

int max_rect(int sr, int sc){
	int i = sc, w, h;
	while(i < col && inside(sr, i) && a[sr][i] != 'y'){
		i += 1;
		if(min_col != -1 && i >= min_col){
			break;	
		}
	}
	if(min_col == -1 || i < min_col) min_col = i;
	i -= 1;
	w = i - sc + 1;
	int j = sr;
	for(; j < row; j += 1){
		if(!is_clear_row(j, sc, i)){
			break;
		}
	}
	h = j - sr;
	return w * h;
}

void solve(int kase){
   	memset(b, 0, sizeof(b));
	struct node q[500];
	int qlen = 1, p = 0;
	q[0].r = xr;
	q[0].c = xc;
	b[xr][xc] = 1;
	min_col = -1;
	
	for(int i=xr-1;i>=0;i-=1){
		if(inside(i, xc) && a[i][xc] != 'y' && b[i][xc] == 0){
			q[qlen].r = i;
			q[qlen].c = xc;
			b[i][xc] = 1;
			qlen += 1;
		}
	}
	
	for(int i=xc-1;i>=0;i-=1){
		if(inside(xr, i) && a[xr][i] != 'y' && b[xr][i] == 0){
			q[qlen].r = xr;
			q[qlen].c = i;
			b[xr][i] = 1;
			qlen += 1;
		}
	}
	while(p < qlen){
		int tr, tc;
		tr = q[p].r - 1;
		tc = q[p].c - 1;
		if(inside(tr, tc) && a[tr][tc] == '.' && b[tr][tc] == 0){
			if(inside(tr+1, tc) && b[tr+1][tc] == 1 && inside(tr, tc+1) && b[tr][tc+1] == 1){
				q[qlen].r = tr;
				q[qlen].c = tc;
				b[tr][tc] = 1;
				qlen += 1;
			}
		}
		p += 1;
	}
//   	for(int i=0;i<row;i+=1){
//   		for(int j=0;j<col;j+=1){
//   			printf("%d", b[i][j]);
//   		}
//   		printf("\n");
//   	}
   	int result = 1;
   	for(int i=0;i<qlen;i+=1){
   		result = max(result, max_rect(q[i].r, q[i].c));
//   		printf("result: %d\n", result);
   	}
   	printf("Case #%d: %d\n", kase, result);
}
 
int main(void){
    freopen("H.in", "r", stdin);
	int kase = 1;
    while(scanf("%d", &n) != EOF){
        input();
        solve(kase);
        kase += 1;
    }
    return 0;
}
