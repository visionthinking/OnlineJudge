#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>

using namespace std;
int data[1000][1000];
int datatop[1000];
int flag[1000];
int main()
{
	//std::ios::sync_with_stdio(false);
	int T,n,m,u,v;
	scanf("%d",&T);;
	for(int loop=0;loop<T;loop++)
	{
		scanf("%d %d",&n,&m);
		int grouptop = -1;
		memset(datatop,0,sizeof(datatop));
		for(int i=0;i<m;i++)
		{
			scanf("%d %d",&u,&v);
			u--;
			v--;
			data[u][datatop[u]++]=v;
			data[v][datatop[v]++]=u;
		}
		for(int j=0;j<n;j++)
		{
			memset(flag,0,sizeof(flag));
			flag[j]=1;
			int num=0;
			for(int i=0;i<datatop[j];i++)
				flag[data[j][i]]=1;
			for(int i=0;i<datatop[j];i++)
			{
				int number = data[j][i];
				for(int p=0;p<datatop[number];p++)
				{
					if(flag[data[number][p]]==0)
					{
						num++;
						flag[data[number][p]]=1;
					}
				}
			}
			printf("%d\n",num);
		}
	}
}
