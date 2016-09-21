#include<stdio.h>
#include<string.h>
#include<queue>
#include<algorithm>
#include<vector>
using namespace std;
int now,head[200010],nex[200010],p[200010];
int vis[200010];
int degree[200010];
vector<int>map[200010];
int ans[200010];

int main(){
    int n,m,k=0;
    int kase;
    scanf("%d", &kase);
    for(int _kase=1; _kase<=kase; _kase+=1){
	    scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++) {
            map[i].clear();
        }
        memset(vis,0,sizeof(vis));
        memset(degree,0,sizeof(degree));
        memset(head,0,sizeof(head));
        now=0;
        while(m--) {
            int x,y;
            scanf("%d%d",&x,&y);
            map[x].push_back(y);
            degree[y]++;
        }
        priority_queue<int>s;
        for(int i=1;i<=n;i++)
        {
            if(degree[i]<=k)
            s.push(i);
        }
        int cont=0;
        while(!s.empty()) {
            int u=s.top();
            s.pop();
            if(vis[u]||degree[u]>k)continue;
            vis[u]=1;
            k-=degree[u];
            ans[++cont]=u;

            for(int j=0;j<map[u].size();j++){
                int v=map[u][j];
                degree[v]--;
                if(degree[v]<=k&&vis[v]==0)
                s.push(v);
            }
        }
        long long sum = 0;
        for(int i=1;i<=cont;i++){
        	int me = 99999999;
        	for(int j=1; j<=i; j+=1){
        		me = min(me, ans[j]);
        	}
            sum += me;
			// printf("%d ",ans[i]);
        }
        printf("%I64d\n", sum);
	}
    return 0;
}
