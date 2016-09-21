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
	
void solve(int kase){
	cin >> V >> E;
	g = vector<vector<edge>>(V, vector<edge>());
	FOR(i, 0, E) {
		int u, v, cost;
		cin >> u >> v >> cost;
		g[u-1].push_back(edge(v-1, cost));
	}
	int res = dijkstra(g, 0, V-1);
    cout << "Case #" << kase << ": " << res << endl;
}

int main(int argc, char *argv[]){
    ios::sync_with_stdio(false);
    std::cin.tie(0);
    freopen("Dijkstra.in", "r", stdin);
    int kase;
    cin >> kase;
	for(int i=1; i<=kase; i+=1){
        solve(i);    
    }
    return 0;
}


