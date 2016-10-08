#include <iostream>
#include <vector>
#include <cmath>
#include <ctime>
#include <cassert>
#include <cstdio>
#include <queue>
#include <set>
#include <map>
#include <fstream>
#include <cstdlib>
#include <string>
#include <cstring>
#include <algorithm>
#include <numeric>
 
#define mp make_pair
#define mt make_tuple
#define fi first
#define se second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define for1(i, n) for (int i = 1; i <= (int)(n); ++i)
#define ford(i, n) for (int i = (int)(n) - 1; i >= 0; --i)
#define fore(i, a, b) for (int i = (int)(a); i <= (int)(b); ++i)
 
using namespace std;
 
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vpi;
typedef vector<vi> vvi;
typedef long long i64;
typedef pair<i64, i64> pi64;
typedef vector<i64> vi64;
typedef vector<vi64> vvi64;
 
template<class T> bool uin(T &a, T b) { return a > b ? (a = b, true) : false; }
template<class T> bool uax(T &a, T b) { return a < b ? (a = b, true) : false; }
 
const int maxn = 110000;
vector<pi64> e[2][maxn];
int vis[2][maxn];
i64 val[2][maxn];
 
bool dfs(int h, int v, i64 p, i64 &p1, i64 &p2) {
    if (p < -1e12 || p > 1e12) return false;
    if (!vis[h][v]) {
//        cerr << h << ' ' << v << ' ' << p << '\n';
        val[h][v] = p;
        vis[h][v] = 1;
        uin((h ? p1 : p2), p);
    } else return val[h][v] == p;
    if (val[h][v] != p) return false;
    for (auto w: e[h][v]) {
        if (!dfs(h ^ 1, w.fi, w.se - p, p1, p2)) return false;
    }
    return true;
}
 
int main() {
    cout.precision(10);
    cout << fixed;
    freopen("D.in", "r", stdin);
 
    int r, c, n;
    cin >> r >> c >> n;
    forn(i, n) {
        int x, y, w;
        cin >> x >> y >> w;
        --x; --y;
        e[0][x].pb(mp(y, w));
        e[1][y].pb(mp(x, w));
        printf("e[%d][%d]: {%d, %d}\n", 0, x, y, w);
        printf("e[%d][%d]: {%d, %d}\n", 1, y, x, w);
    }
 
    bool ok = true;
    forn(i, r) {
        if (vis[0][i]) continue;
        i64 p1 = 1e18, p2 = 1e18;
        if (!dfs(0, i, 0, p1, p2) || p1 + p2 < 0) {
            ok = false;
            break;
        }
    }
    cout << (ok ? "Yes" : "No") << '\n';
 
    return 0;
}
