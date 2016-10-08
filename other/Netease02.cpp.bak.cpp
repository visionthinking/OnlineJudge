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

LL n;

int get(int i) {
	return (n >> i) & 1;	
}

void solve(){
	LL res;
	int m = -1, first = -1, cnt = 0;
    FOR(i, 0, 32) {
    	if(get(i)) {
			cnt += 1;
			m = i;
			if(first == -1) first = i;
		}
    }
    FOR(i, first+1, m) {
    	if(get(i) == 0) {
    		res = n | (1LL << i);
    		res = res - (1LL << first);
    		cout << res << endl;
			return;	
    	}
    }
    res = 1LL << (m+1);
    cnt -= 1;
	FOR(i, 0, 32) {
    	if(cnt > 0) {
			res = res | (1LL << i);
			cnt -= 1;
		}
    }
    cout << res << endl;
}

int main(int argc, char *argv[]){
    ios::sync_with_stdio(false);
    std::cin.tie(0);
    freopen("Netease02.in", "r", stdin);    
    while(cin >> n) {
    	solve();
    }
    return 0;
}
