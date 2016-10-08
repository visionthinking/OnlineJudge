struct edge {
    int to;
    double cost;
    edge(int _to, double _cost): to(_to), cost(_cost) {};
};

class Solution {
public:
    bool dfs(vector<vector<edge>>& g, int v, int t, vector<double>& r, vector<int>& visit) {
        if(v == t) return true;
        for(edge& e : g[v]) {
            if(visit[e.to] == 0) {
                visit[e.to] = 1;
                r.push_back(e.cost);
                if(dfs(g, e.to, t, r, visit)) return true;
                r.pop_back();
                visit[e.to] = 0;
            }
        }
        return false;
    }
    
    vector<double> calcEquation(
            vector<pair<string, string>> equations, 
            vector<double>& values, 
            vector<pair<string, string>> queries) {
        
        vector<double> res;
        unordered_map<string, int> id;
        vector<vector<edge>> g(equations.size() * 2, vector<edge>());
        int idx = 0;
        
        for(int i=0; i<equations.size(); i++) {
            auto& p = equations[i];
            if(id.count(p.first) == 0) {
                id[p.first] = idx++;
            }
            if(id.count(p.second) == 0) {
                id[p.second] = idx++;
            }
            int id1 = id[p.first], id2 = id[p.second];
            g[id1].push_back(edge(id2, values[i]));
            g[id2].push_back(edge(id1, 1.0 / values[i]));
        }
        
        for(auto& p : queries) {
            if(id.count(p.first) == 0 || id.count(p.second) == 0) {
                res.push_back(-1.0);
                continue;
            }
            int id1 = id[p.first], id2 = id[p.second];
            if(id1 == id2) {
                res.push_back(1.0);
            } else {
                vector<int> visit(idx, 0);
                vector<double> rs;
                visit[id1] = 1;
                if(dfs(g, id1, id2, rs, visit)) {
                    double r = 1.0;
                    for(double x : rs) {
                        r *= x;
                    }
                    res.push_back(r);
                } else {
                    res.push_back(-1.0);
                }
            }
        }
        
        return res;
    }
};