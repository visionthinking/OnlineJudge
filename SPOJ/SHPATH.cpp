#include <stdio.h>
#include <string.h>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <utility>
#include <queue>
#include <climits>
using namespace std;

#define endl '\n'
#define FOR(i, a, b) for(int i=(a); i<(b); i++)
typedef pair<int, int> ii;
typedef long long LL;
typedef long double LD;

/* Dijkstra (0-based id) */
struct edge { 
    int to, cost; 
    edge(int _to, int _cost): to(_to), cost(_cost) {};
};

int dijkstra(vector<vector<edge>>& g, int source, int target) {
    vector<int> d(g.size(), INT_MAX); // distance
    d[source] = 0;
    priority_queue<ii, vector<ii>, greater<ii>> q; q.push({0, source}); // {distance, v}

    while(!q.empty()) {
        int v = q.top().second, dv = q.top().first; q.pop();
        for(int i=0; dv <= d[v] && i < g[v].size(); i++) {
            int u = g[v][i].to, w = g[v][i].cost;
            if(d[u] > d[v] + w) {
                d[u] = d[v] + w;
                q.push({d[u], u});
            }
        }
    }
    return d[target];
}

int V, E;
vector<vector<edge>> g;
unordered_map<string, int> id;

void solve(int kase){
    cin >> V;
    g = vector<vector<edge>>(V, vector<edge>());
    FOR(i, 0, V) {
    	string name;
        int p, nr, cost;
        cin >> name;
        id[name] = i;
        cin >> p;
        FOR(j, 0, p) {
        	cin >> nr >> cost;
        	nr -= 1;
        	g[i].push_back(edge(nr, cost));
        }
    }
    int r;
    string c1, c2;
    cin >> r;
    FOR(i, 0, r) {
    	cin >> c1 >> c2;
	    int res = dijkstra(g, id[c1], id[c2]);
    	cout << res << endl;
	}
}

int main(int argc, char *argv[]){
    ios::sync_with_stdio(false);
    std::cin.tie(0);
    freopen("SHPATH.in", "r", stdin);
    int kase;
    cin >> kase;
    for(int i=1; i<=kase; i+=1){
        solve(i);    
    }
    return 0;
}
