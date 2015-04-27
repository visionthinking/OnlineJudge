#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;

struct node {
	int parent;
	int brother;
	int fchild;
	int lchild;
	int color;
	int count;
};

const int MAX = 100005;
struct node a[MAX];

void debug(int n){
	if(n == 0) return;
	printf("%d ", n);
	for(int i=a[n].fchild;i>0;i=a[i].brother){
		debug(i);
	}
}

void debug2(int n){
	for(int i=1;i<=n;i++){
		printf("n=%d parent=%d fchild=%d brother=%d %d c=%d\n", i, a[i].parent, a[i].fchild, a[i].brother, a[i].color, a[i].count);
	}
	printf("\n");
}

int calc(int n){
	if(n == 0) return 0;
	a[n].count = 1;
	if(a[n].fchild == 0){
		return 1;
	}
	//printf("n=%d count=%d\n", n, a[n].count);
	for(int i=a[n].fchild;i>0;i=a[i].brother){
		if(a[i].color != a[n].color){
			a[n].count += calc(i);
		}else{
			a[n].count += calc(i) - 1;
		}
	}
	//printf("n=%d count=%d\n", n, a[n].count);
	return a[n].count;
}

void update(int n){
	if(n == 0) return;
	a[n].count = 1;
	for(int i=a[n].fchild;i>0;i=a[i].brother){
		if(a[i].color != a[n].color){
			a[n].count += a[i].count;
		}else{
			a[n].count += a[i].count - 1;
		}
	}
	update(a[n].parent);
}

void solution(bool is_last){
	int n, m, i, j, k, x, y, q;
	memset(a, 0, sizeof(a));
	scanf("%d", &n);
	
	for(i=1;i<n;i++){
		scanf("%d %d", &x, &y);
		if(a[y].parent != 0){
			int t = x;
			x = y;
			y = t;	
		}
		if(a[x].fchild == 0){
			a[x].fchild = y;
			a[x].lchild = y;
		}else{
			a[a[x].lchild].brother = y;
			a[x].lchild = y;
		}
		a[y].parent = x;
		a[y].brother = 0;
	}
	
	int root = 1;
	while(a[root].parent != 0){
		root = a[root].parent;
	}
	if(n > 1){
		calc(root);
	}
	//debug2(10);
	
	scanf("%d", &q);
	if(q>=1){
		//printf("\n");	
	}
	for(i=0;i<q;i++){
		scanf("%d", &m);
		if(m == 1){
			//根节点一定是1么? 
			if(n == 1){
				printf("\n%d", 1);
			}else{
				printf("\n%d", a[root].count);
			}
		}else if(m == 2){
			scanf("%d %d", &x, &y);
			if(n > 1){
				a[x].color = y;
				update(x);
			}
		}
	}
	if(!is_last){
		printf("\n");
	}
}

int main(void){
	freopen("A.in", "r", stdin);
	int t, i;
	while(scanf("%d", &t)!=EOF){
		for(i=1;i<=t;i++){
			printf("Case #%d:", i);
			solution((i==t));
		}
	}
	return 0;
}


