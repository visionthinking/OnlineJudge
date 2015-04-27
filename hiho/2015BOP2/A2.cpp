#include<iostream>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<map>
using namespace std;
struct bian{
	int next,point;
}b[210000];
int p[110000],n,m,len,w[110000],father[110000];
map<int,int>A[110000];
void ade(int k1,int k2){
	b[++len]=(bian){p[k1],k2}; p[k1]=len;
}
void add(int k1,int k2){
	ade(k1,k2); ade(k2,k1);
}
void dfs(int k1,int k2){
	father[k1]=k2; if (k2!=0) A[k2][0]++;
	for (int i=p[k1];i;i=b[i].next){
		int j=b[i].point;
		if (j!=k2) dfs(j,k1);
	}
}
void solve(){
	scanf("%d",&n); len=0;
	for (int i=1;i<=n;i++) p[i]=0;
	for (int i=1;i<n;i++){
		int k1,k2; scanf("%d%d",&k1,&k2); add(k1,k2);
	}
	for (int i=1;i<=n;i++) A[i].clear();
	for (int i=1;i<=n;i++) w[i]=0;
	dfs(1,0);
	scanf("%d",&m); int ans=1;
	for (;m;m--){
		int k1; scanf("%d",&k1);
		if (k1==1) printf("%d\n",ans);
		else {
			int k2,k3; scanf("%d%d",&k2,&k3);
			if (k2!=1){
				k1=father[k2];
				if (w[k1]!=w[k2]) ans--;
				A[k1][w[k2]]--; A[k1][k3]++;
				if (k3!=w[k1]) ans++;
			}
			ans+=A[k2][w[k2]]-A[k2][k3]; w[k2]=k3;
		}
	}
}				
int main(){
	freopen("A.in", "r", stdin);
	int t; scanf("%d",&t);
	for (int i=1;i<=t;i++){
		printf("Case #%d:\n",i); solve();
	}
	return 0;
}
