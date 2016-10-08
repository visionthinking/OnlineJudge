#include <stdio.h>
#include <string.h>
#include <string>
#include <map>
#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <utility>
#include <queue>
#include <climits>
using namespace std;

/* macros */
#define endl '\n'
#define FOR(i, a, b) for(int i=(a); i<(b); i++)
#define FORE(i, a, b) for(int i=(a); i<=(b); i++)
typedef pair<int, int> ii;
typedef long long LL;
typedef long double LD;

/* the graph */ 
vector<int> g[1005];
int s[1005];
int n, m;

/* For debug */
void print(vector<vector<int> >& x) {
	FORE(i, 0, m) cout << x[0][i] << " ";
	cout << endl;
	FORE(i, 0, m) cout << x[1][i] << " ";
	cout << endl;
	FORE(i, 0, m) cout << x[2][i] << " ";
	cout << endl;
	cout << endl;
}

/* helper function */
inline void get_max(int& x, int y, int m_add) {
    if(m_add <= m) {
        x = max(x, y);
    }
}

/* 当前节点被选多少次,  */
const int T[3][3] = {
    {0, 1, 0},
    {1, 2, 1},
    {0, 1, 0}
};

/* 当前节点要选时，左孩子是否要选 */
const int TL[3][3] = {
    {1, 1, 1},
    {0, 0, 0},
    {0, 0, 0} 
};

/* 当前节点要选时，右孩子是否要选 */
const int TR[3][3] = {
    {1, 0, 0},
    {1, 0, 0}, 
    {1, 0, 0},
};

/* dfs the graph, trade it as a binary tree (n nodes, n-1 edges) */
void dfs(vector<vector<int> >& res, int root, int parent) {
    int left = -1, right = -1;
    FOR(i, 0, g[root].size()) {
        if(parent != g[root][i]) {
            if(left == -1) left = g[root][i];
            else right = g[root][i];   
        }
    }
    
    int s0 = s[root], sp = s[parent];
    if(left == -1 && right == -1) {
        // leaf
        res[0][0] = 0;
        res[1][1] = s0 + sp;
    } else if(left != -1 && right != -1) {
        // both children
        vector< vector<int> > L(3, vector<int>(m+1, -1));
        vector< vector<int> > R(3, vector<int>(m+1, -1));
        dfs(L, left, root);
        dfs(R, right, root);
        int s1 = s[left], s2 = s[right];
        
        FOR(i1, 0, 3) FOR(i2, 0, 3) {
            FORE(m1, 0, m) {
                if(L[i1][m1] == -1) continue;
                FORE(m2, 0, m) {
                    if(m1 + m2 > m) break;
                    if(R[i2][m2] == -1) continue;
                    int sL = L[i1][m1], sR = R[i2][m2];
                    
                    if(i1 == 0 && i2 == 0) {
                        get_max(res[0][m1+m2], sL+sR, m1+m2);
                        get_max(res[1][m1+m2+1], sL+sR+s0+s1+s2+sp, m1+m2+1);
                    } else if(i1 == 0 && i2 == 1) {
                        get_max(res[2][m1+m2], sL+sR, m1+m2);
                        get_max(res[1][m1+m2+1], sL+sR+s1+sp, m1+m2+1);
                    } else if(i1 == 0 && i2 == 2) {
                        get_max(res[0][m1+m2], sL+sR, m1+m2);
                        get_max(res[1][m1+m2+1], sL+sR+s0+s1+sp, m1+m2+1);
                    } else if(i1 == 1 && i2 == 0) {
                        get_max(res[2][m1+m2], sL+sR, m1+m2);
                        get_max(res[1][m1+m2+1], sL+sR+s2+sp, m1+m2+1);
                    } else if(i1 == 1 && i2 == 1) {
                        get_max(res[2][m1+m2], sL+sR-s0, m1+m2);
                        get_max(res[1][m1+m2+1], sL+sR-s0+sp, m1+m2+1);
                    } else if(i1 == 1 && i2 == 2) {
                        get_max(res[2][m1+m2], sL+sR, m1+m2);
                        get_max(res[1][m1+m2+1], sL+sR+sp, m1+m2+1);
                    } else if(i1 == 2 && i2 == 0) {
                        get_max(res[0][m1+m2], sL+sR, m1+m2);
                        get_max(res[1][m1+m2+1], sL+sR+s0+s2+sp, m1+m2+1);
                    } else if(i1 == 2 && i2 == 1) {
                        get_max(res[2][m1+m2], sL+sR, m1+m2);
                        get_max(res[1][m1+m2+1], sL+sR+sp, m1+m2+1);
                    } else if(i1 == 2 && i2 == 2) {
                        get_max(res[0][m1+m2], sL+sR, m1+m2);
                        get_max(res[1][m1+m2+1], sL+sR+sp+s0, m1+m2+1);
                        
                    }
                }
            }
        }
        
    } else {
        // left child
        vector<vector<int> > L(3, vector<int>(m+1, -1));
        dfs(L, left, root);
        int s1 = s[left];
        FOR(i1, 0, 3) {
            FORE(m1, 0, m) {
                int sL = L[i1][m1];
                if(sL == -1) continue;
                
                if(i1 == 0) {
                    get_max(res[0][m1], sL, m1);
                    get_max(res[1][m1+1], sL+s0+s1+sp, m1+1);
                } else if(i1 == 1) {
                    get_max(res[2][m1], sL, m1);
                    get_max(res[1][m1+1], sL+sp, m1+1);
                } else {
                    get_max(res[0][m1], sL, m1);
                    get_max(res[1][m1+1], sL+s0+sp, m1+1);
                }
            }
        }
    }
}

void solve(){
    /* find a node which has only one edge */
    int root = 0;
    FOR(i, 1, n+1) {
        if(g[i].size() == 1) {
            root = i;
            break;
        }
    }
    
    vector<vector<int> > r(3, vector<int>(m+1, -1));
    dfs(r, root, 0);
    int m1 = *max_element(r[0].begin(), r[0].end());
    int m2 = *max_element(r[1].begin(), r[1].end());
    int m3 = *max_element(r[2].begin(), r[2].end());
    cout << max(m1, max(m2, m3)) << endl; 
}

int main(int argc, char *argv[]) {
    ios::sync_with_stdio(false);
    std::cin.tie(0);
    freopen("b0.in", "r", stdin);
    
    s[0] = 0;
    while(cin >> n >> m) {
        FORE(i, 1, n) g[i].clear();
        FORE(i, 1, n) cin >> s[i];
        FOR(i, 1, n) {
            int u, v;
            cin >> u >> v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        solve();
    }
    
    return 0;
}
