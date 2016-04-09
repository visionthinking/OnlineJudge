/* Uva 1698 Just a Hook */

#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

const int MAX = 100005;
int n, Q;
int tree[MAX * 4 + 10], lazy[MAX * 4 + 10];

void input(){
	scanf("%d %d", &n, &Q);
}

void push_up(int rt) {
    tree[rt] = tree[rt << 1] + tree[rt << 1 | 1];
}

void push_down(int rt, int len) {
    tree[rt << 1] = lazy[rt] * (len - (len >> 1));
    lazy[rt << 1] = lazy[rt];
    tree[rt << 1 | 1] = lazy[rt] * (len >> 1);
    lazy[rt << 1 | 1] = lazy[rt];
    lazy[rt] = 0;
}

#define lchild rt << 1, l, m
#define rchild rt << 1 | 1, m + 1, r

void update(int L, int R, int value, int rt = 1, int l = 1, int r = n) {
    if (L <= l && r <= R) {
        tree[rt] = value * (r - l + 1);
        lazy[rt] = value;
        return;
    }
    if (lazy[rt]) push_down(rt, r - l + 1);
    int m = (l + r) >> 1;
    if (L <= m) update(L, R, value, lchild);
    if (R > m)  update(L, R, value, rchild);
    push_up(rt);
}

void solve(int kase){
	int res, x, y, z;

	lazy[1] = 1;
	tree[1] = n;
	
	for(int i=0;i<Q;i+=1){
		scanf("%d %d %d", &x, &y, &z);
		update(x, y, z);
	}
	
	res = tree[1];
	printf("Case %d: The total value of the hook is %d.\n", kase, res);
}

int main(void){
	freopen("uva1698.in", "r", stdin);
	int kase;
	while(scanf("%d", &kase) != EOF){
		for(int i=1;i<=kase;i+=1){
			input();
			solve(i);
		}
	}
	return 0;
}
