#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <vector>

using namespace std;
const int MAX = 100005;

struct rect {
	int x1, y1, x2, y2;
};

struct rect a[MAX];
int dp[MAX];
int n;

struct node {
	int curr, u, m;
};
struct node q[MAX];

inline
bool rect_less(struct rect & a, struct rect & b){
	return a.x2 < b.x1 && a.y2 < b.y1;
}

void input(){
	scanf("%d", &n);
	for(int i=0;i<n;i+=1){
		scanf("%d%d%d%d", &a[i].x1, &a[i].y1, &a[i].x2, &a[i].y2);
	}
}

void print(int p){
	for(int i=1;i<=p;i+=1){
		printf("%d ", q[i].u);
	}
	printf("\n");
}

int dfs(int u){
	if(dp[u] > 0){
		return dp[u];	
	}
	int p = 1;
	q[0].m = 0;
	q[1].u = u;
	q[1].curr = 0;
	q[1].m = 0;
	while(p >= 1){
		struct node & x = q[p];
//		printf("x.curr=%d n=%d\n", x.curr, n);
//		print(p);
		if(x.curr >= n){
			dp[x.u] = 1 + x.m;
//			printf("dp[%d]=%d\n", x.u, dp[x.u]);
			q[p-1].m = max(q[p-1].m, dp[x.u]);
			p -= 1;
		}else{
			int v;
			for(v=x.curr; v<n; v+=1){
				if(x.u != v && rect_less(a[x.u], a[v])){
					break;
				}
			}
//			printf("v=%d\n", v);
			x.curr = v+1;
			if(v < n) {
				if(dp[v] == 0){
					p += 1;
					q[p].u = v;
					q[p].curr = 0;
					q[p].m = 0;
				}else{
					x.m = max(x.m, dp[v]);	
				}
			}
		}
	}
	return dp[u];
}

void solve(int kase){
	int res = 0;
	memset(dp, 0, sizeof(dp));
	for(int i=0;i<n;i+=1){
		res = max(res, dfs(i));
	}
	printf("%d\n", res);
}

int main(void){
	freopen("p171.in", "r", stdin);
	int kase = 1;
	scanf("%d", &kase);
	for(int i=1;i<=kase;i+=1){
//		printf("\n\ncase=%d\n", i);
		input();
		solve(i);
	}
	return 0;
}

