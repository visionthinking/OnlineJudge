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
vector<int> b[MAX];
int dp[MAX];
int n;
 
struct node {
    int curr, u;
};
struct node q[MAX];
 
inline
bool rect_less(struct rect & a, struct rect & b){
    return a.x2 < b.x1 && a.y2 < b.y1;
}
 
void input(){
    scanf("%d", &n);
    for(int i=0;i<n;i+=1){
        b[i].clear();
    }
    for(int i=0;i<n;i+=1){
        scanf("%d%d%d%d", &a[i].x1, &a[i].y1, &a[i].x2, &a[i].y2);
        for(int j=0;j<i;j+=1){
            if(rect_less(a[j], a[i])){
                b[j].push_back(i);
            }
        }
    }
//  for(int i=0;i<n;i+=1){
//      printf("node=%d:", i);
//      for(int j=0;j<b[i].size(); j+=1){
//          printf("%d", b[i][j]);
//      }
//      printf("\n");
//  }
}
 
 
int dfs(int u){
    if(dp[u] > 0){
        return dp[u];  
    }
    int p = 0;
    q[0].u = u;
    q[0].curr = 0;
    while(p >= 0){
        struct node & x = q[p];
        if(x.curr >= b[x.u].size()){
            int mx = 0;
            for(vector<int>::iterator i=b[x.u].begin() ;i != b[x.u].end(); i+=1){
                mx = max(mx, dp[*i]);
            }
            dp[x.u] = 1 + mx;
            p -= 1;
        }else{
            int v = b[x.u][x.curr];
            if(dp[v] == 0){
                p += 1;
                q[p].u = v;
                q[p].curr = 0;
            }
            x.curr += 1;
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
        input();
        solve(i);
    }
    return 0;
}
