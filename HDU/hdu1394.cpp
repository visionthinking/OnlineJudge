/* Minimum Inversion Number */
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

const int MAX = 5005;

int n;
int a[MAX];

void solve(){
	for(int i=0;i<n;i+=1){
		scanf("%d", &a[i]);
	}
	
	int sum = 0, res;
	for(int i=0;i<n;i+=1){
		for(int j=i+1;j<n;j+=1){
			if(a[i] > a[j]){
				sum += 1;
			}
		}
	}
	res = sum;
	for(int i=0;i<n;i+=1){
		sum += (n-1)-a[i]-a[i];
		res = min(res, sum);
	}
	printf("%d\n", res);
}

int tree[(MAX << 2) + 10];

void push_up(int rt){
	tree[rt] = tree[rt << 1] + tree[rt << 1 | 1];
}

#define lchild rt << 1, l, m
#define rchild rt << 1 | 1, m+1, r
void build(int rt = 1, int l = 1, int r = n){
	memset(tree, 0, sizeof(tree));
}

void update(int p, int delta, int rt = 1, int l = 1, int r = n){
	if(l == r){ tree[rt] += delta; return;}
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

void solve_by_segment_tree(){
	build();
	for(int i=0;i<n;i+=1){
		scanf("%d", &a[i]);
	}
	
	int sum = 0, res;
	for(int i=0;i<n;i+=1){
		int x = a[i] + 1;
		sum += query(x+1, n);
		update(x, 1);
	}
	res = sum;
	for(int i=0;i<n;i+=1){
		sum += (n-1)-a[i]-a[i];
		res = min(res, sum);
	}
	printf("%d\n", res);
}

int main(void){
	freopen("hdu1394.in", "r", stdin);
	while(scanf("%d", &n) != EOF){
//		solve();
		solve_by_segment_tree();
	}
	return 0;
}


