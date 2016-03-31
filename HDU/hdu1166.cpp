#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int MAX = 50005;
int n;
int tree[MAX * 4 + 10];

void push_up(int rt){
	tree[rt] = tree[rt << 1] + tree[rt << 1 | 1];
}

#define lchild rt << 1, l, m
#define rchild rt << 1 | 1, m+1, r
void build(int rt = 1, int l = 1, int r = n){
	if(l == r) { scanf("%d", &tree[rt]); return; }
	int m = (l + r) >> 1;
	build(lchild); build(rchild);
	push_up(rt);
}

void update(int p, int delta, int rt = 1, int l = 1, int r = n) {
	if(l == r) { tree[rt] += delta; return; }
	int m = (l + r) >> 1;
	if(p <= m) update(p, delta, lchild);
	else update(p, delta, rchild);
	push_up(rt);
}

int query(int L, int R, int rt = 1, int l = 1, int r = n){
	if(L <= l && r <= R) return tree[rt];
	int m = (l + r) >> 1, res = 0;
	if (L <= m) res += query(L, R, lchild);
	if (R > m) res += query(L, R, rchild);
	return res;
}

void input(){
	memset(tree, 0, sizeof(tree));
	scanf("%d", &n);
	build();
}

void solve(int kase){
	printf("Case %d:\n", kase);
	char cmd[20];
	int x, y;
	do {
		scanf("%s", cmd);
//		printf("%s\n", cmd);
		if(strcmp(cmd, "Query") == 0){
			scanf("%d %d", &x, &y);
			printf("%d\n", query(x, y));
		}else if(strcmp(cmd, "Add") == 0){
			scanf("%d %d", &x, &y);
			update(x, y);
		}else if(strcmp(cmd, "Sub") == 0){
			scanf("%d %d", &x, &y);
			update(x, -y);
		}
	} while(strcmp(cmd, "End") != 0);
}

int main(void){
	freopen("p1166.in", "r", stdin);
	int kase;
	while(scanf("%d", &kase) != EOF){
		for(int i=1;i<=kase;i+=1){
			input();
			solve(i);
		}
	}
	return 0;
}

