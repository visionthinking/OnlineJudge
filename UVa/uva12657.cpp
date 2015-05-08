#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>

struct node {
	int data;
	int left;
	int right;		
};

const int MAX = 101000;
struct node a[MAX];

inline
void link(int l, int r){
	a[l].right = r;
	a[r].left = l;
}

inline
void do1(int x, int y){
	if(a[x].right != y){
		link(a[x].left, a[x].right);
		link(a[y].left, x);
		link(x, y);
	}
}

inline
void do2(int x, int y){
	if(a[y].right != x){
		link(a[x].left, a[x].right);
		link(x, a[y].right);
		link(y, x);
	}
}

inline
void do3(int x, int y){
	int xl, xr;
	xl = a[x].left;
	xr = a[x].right;
	if(xl == y){
		link(a[y].left, x);
		link(y, xr);
		link(x, y);
	}else if(xr == y){
		link(x, a[y].right);
		link(xl, y);
		link(y, x);
	}else{
		link(x, a[y].right);
		link(a[y].left, x);
		link(xl, y);
		link(y, xr);
	}
}

void print(){
	printf("print: ");
	for(int i=a[0].right;a[i].right!=0;i=a[i].right){
		printf("%d ", a[i].data);
	}
	printf("\n");
}

void solve(int case_id, int n, int m){
	long long sum = 0;
	int i, op, x, y, t;
	bool inv = false;
	
	a[0].left = 0;
	for(i=0;i<=n;i++){
		a[i].data = i;
		a[i].left = i - 1;
		a[i].right = i + 1;
	}
	a[n + 1].left = n;
	a[n + 1].right = 0;
	
	for(i=0;i<m;i++){
		scanf("%d", &op);
		if(op == 1){
			scanf("%d %d", &x, &y);
			if(inv){
				do2(x, y);
			}else{
				do1(x, y);	
			}
		}else if(op == 2){
			scanf("%d %d", &x, &y);
			if(inv){
				do1(x, y);
			}else{
				do2(x, y);	
			}
		}else if(op == 3){
			scanf("%d %d", &x, &y);
			do3(x, y);
		}else if(op == 4){
			inv = !inv;	
		}
	}
	print();
	printf("Case %d: %lld\n", case_id, sum);
}

int main(void){
	freopen("uva12657.in", "r", stdin);
	int n, m;
	int case_id = 1;
	while(scanf("%d %d", &n, &m) != EOF){
		solve(case_id, n, m);
		case_id += 1;
	}
		
	return 0;
}
