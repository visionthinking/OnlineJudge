#include <stdio.h>
#include <string.h>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <set>
#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>

#define FOR(i, a, b) for(int i=(a); i<(b); i++)
typedef long long LL;
typedef long double LD;

using namespace std;

unordered_map<string, int> gid;
vector<int> g[1000000];
int visit[1000000];
int idx;
set<int> L, R;

int get_id(string& x) {
	if(gid.count(x) > 0) {
		return gid[x];
	}
	gid[x] = idx++;
	return idx-1;
}

void parse(string& s) {
	string x = s.substr(0, s.find('='));
	int xid = get_id(x);
	int i = s.find('(') + 1;
	while(i < s.length() && s[i] != ')') {
		int j = i;
		while(s[j] != ',' && s[j] != ')') j++;
		string token = s.substr(i, j - i);
		int token_id = get_id(token);
		g[token_id].push_back(xid);
		i = j + 1;
		R.insert(token_id);
	}
	L.insert(xid);
}

bool dfs(int x) {
	visit[x] = -1;
	for(int i : g[x]) {
		if(visit[i] == -1) {
			return false;	
		} else if(visit[i] == 0 && !dfs(i)) {
			return false;
		}
	}
	visit[x] = 1;
	return true;
}

void solve(int kase){
    int N;
    string s;
	cin >> N;
	idx = 0;
	memset(visit, 0, sizeof(visit));
	gid.clear();
	L.clear();
	R.clear();
	bool good = true;
	FOR(i, 0, 1005) {
		g[i].clear();	
	}
	FOR(i, 0, N) {
		cin >> s;
		parse(s);
	}
	FOR(i, 0, idx) {
		if(visit[i] == 0 && !dfs(i)) {
			good = false;
			break;	
		}
	}
	for(int x : R) {
		if(L.count(x) == 0) {
			good = false;
			break;
		}
	}
	cout << "Case #" << kase << ": ";
    if(good) {
    	cout << "GOOD" << endl;	
    } else {
    	cout << "BAD" << endl;	
    }
}

int main(int argc, char *argv[]){
    ios::sync_with_stdio(false);
	if(argc >= 2) {
        freopen(argv[1], "r", stdin);
    }else{
        freopen("C.in", "r", stdin);    
    }
    int kase;
    cin >> kase;
	for(int i=1; i<=kase; i+=1){
        solve(i);    
    }
    return 0;
}


