#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
int field[20][20];
int main()
{
    std::ios::sync_with_stdio(false);
    int T;
    int n,m,k;
    string input;
    cin>>T;
    for(int loop=0;loop<T;loop++)
    {
        cin>>n>>m>>k;
        int x,y;
        for(int i=0;i<n;i++)
        {
            cin>>input;
            for(int j=0;j<m;j++)
            {
                if(input[j]=='.')
                    field[i][j]=0;
                if(input[j]=='x')
                {
                    field[i][j]=0;
                    x=i;
                    y=j;
                }
                if(input[j]=='y')
                    field[i][j]=1;
            }
        }
        int x0,x1,y0,y1,max=1;
        for(x0=x;x0>=0;x0--)
            if(field[x0][y]==1)
                break;
        for(x1=x;x1<n;x1++)
            if(field[x1][y]==1)
                break;
        for(y0=y;y0>=0;y0--)
            if(field[x][y0]==1)
                break;
        for(y1=y;y1<m;y1++)
            if(field[x][y1]==1)
                break;
        if(k>1)
        {
            for(int p=x;p>x0;p--)
            {
                for(int q=x;q<x1;q++)
                {
                    int left=0,right=0;
                    int flag=1;
                    while(flag)
                    {
                        left++;
                        if(y<left)
                        {
                            break;
                        }
                        for(int z=p;z<=q;z++)
                        {
                            if(field[z][y-left]==1)
                            {
                                flag=0;
                                break;
                            }
                        }
                    }
                    left--;
                    flag=1;
                    while(flag)
                    {
                        right++;
                        if(y+right>=m)
                        {
                            break;
                        }
                        for(int z=p;z<=q;z++)
                        {
                            if(field[z][y+right]==1)
                            {
                                flag=0;
                                break;
                            }
                        }
                    }
                    right--;
                    int sum=(q-p+1)*(left+1+right);
                    if(sum>max)max=sum;
                }
            }
        }
        else
            max=n*m;
        cout<<"Case #"<<(loop+1)<<": "<<max<<endl;
    }
}
