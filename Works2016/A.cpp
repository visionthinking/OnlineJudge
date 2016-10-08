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

int M, N, P;
int a[10][10][10];

struct cube {
    int x[10][10][10];
    int L;  
};

struct pt {
    int x, y, z;
    pt(int _x, int _y, int _z): x(_x), y(_y), z(_z) {};  
};

cube b[15];

void print() {
    FOR(i, 0, M) FOR(j, 0, M) FOR(k, 0, M) 
        cout << a[i][j][k] << ' ';
    cout << endl << endl;
}

int add_up(pt& p, int id) {
    int L = b[id].L;
    int cnt = 0;
    FOR(i, 0, L) FOR(j, 0, L) FOR(k, 0, L) {
        bool zero = (a[i+p.x][j+p.y][k+p.z] % P == 0);
        a[i+p.x][j+p.y][k+p.z] += b[id].x[i][j][k];
        if(a[i+p.x][j+p.y][k+p.z] % P == 0) {
            if(!zero) cnt -= 1;
        } else {
            if(zero) cnt += 1;   
        }
    }
    return cnt;
}

int restore(pt& p, int id) {
    int L = b[id].L;
    int cnt = 0;
    FOR(i, 0, L) FOR(j, 0, L) FOR(k, 0, L) {
        bool zero = (a[i+p.x][j+p.y][k+p.z] % P == 0);
        a[i+p.x][j+p.y][k+p.z] -= b[id].x[i][j][k];
        if(a[i+p.x][j+p.y][k+p.z] % P == 0) {
            if(!zero) cnt -= 1;
        } else {
            if(zero) cnt += 1;   
        }
    }
    return cnt;
}

bool dfs(int cnt, int id, vector<pt>& res) {
    if(id >= N) return cnt == 0;
    int L = b[id].L;
    FORE(i, 0, M-L) FORE(j, 0, M-L) FORE(k, 0, M-L) {
        pt p(i, j, k);
        cnt += add_up(p, id);
        res.push_back(p);
        if(dfs(cnt, id+1, res)) return true;
        res.pop_back();
        cnt += restore(p, id); 
    }
    return false;
}

void solve() {
    int cnt = M*M*M;
    FOR(i, 0, M) FOR(j, 0, M) FOR(k, 0, M) {
        if(a[i][j][k] % P == 0) {
            cnt -= 1;
        }
    }
    
    vector<pt> res;
    int L = b[0].L;
    FORE(i, 0, M-L) FORE(j, 0, M-L) FORE(k, 0, M-L) {
        pt p(i, j, k);
        cnt += add_up(p, 0);
        res.push_back(p);
        if(dfs(cnt, 1, res)) {
            FOR(l, 0, res.size()) {
                cout << res[l].x << ' ' << res[l].y << ' ' << res[l].z << endl;
            }
            return;
        }
        res.pop_back();
        cnt += restore(p, 0); 
    }
}

int main(int argc, char *argv[]) {
    ios::sync_with_stdio(false);
    std::cin.tie(0);
    
    while(cin >> M >> N >> P) {
        FOR(i, 0, M) FOR(j, 0, M) FOR(k, 0, M) {
            cin >> a[i][j][k];
        }
        FOR(n, 0, N) {
            int L;
            cin >> L;
            b[n].L = L;
            FOR(i, 0, L) FOR(j, 0, L) FOR(k, 0, L) {
                cin >> b[n].x[i][j][k];
            }
        }
        solve();
    }
    
    return 0;   
}
