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

int n, a, b;
int h[100]

void hit(int t) {
	h[t] -= a;
	h[t+1] -= b;
	h[t-1] -= b; 
}

void unhit(int t) {
	h[t] += a;
	h[t+1] += b;
	h[t-1] += b;
}

bool need_hit(int t) {
	return h[t] >= 0 || h[t-1] >= 0 || h[t+1] >= 0;
}

int alive() {
	int cnt = 0;
	FOR(i, 0, n) if(h[i] >= 0) cnt++;
	return cnt;
}

bool dfs(int t, vector<int>& s) {
	// cout << "t: " << t << endl;
	if(alive() == 0){
		res = s;
		return true;	
	}
	for(int i=t; i<=t+1 && i<=n-2; i+=1) {
		if(need_hit(i)) {
			hit(i);
			s.push_back(i);
			if(dfs(i, s)){
				return true;	
			}
			s.pop_back();
			unhit(i);
		}
	}
	return false;
}

void solve(){
	FOR(i, 0, n) cin >> h[i];
	vector<int> res;
	res_len = INT_MAX;
	while(h[0] >= 0) {
		hit(1);
		res.push_back(1);
	}
	dfs(1, s);
	cout << res.size() << endl;
	if(res.size() > 0) cout << res[0] + 1;
	FOR(i, 1, res.size()) {
		cout << " " << res[i] + 1;
	}
	cout << endl;
}

int main(int argc, char *argv[]){
    ios::sync_with_stdio(false);
    std::cin.tie(0);
    if(argc >= 2) {
        freopen(argv[1], "r", stdin);
    }else{
        freopen("youdao3.in", "r", stdin);    
    }
    while(cin >> n >> a >> b) {
        solve();
    }
    return 0;
}
