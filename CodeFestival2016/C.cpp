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

string s;
LL k;

void solve(){
	FOR(i, 0, s.length()-1) {
		int need = 'z' - s[i] + 1;
		if(s[i] > 'a' && need <= k) {
			k -= need;
			s[i] = 'a';
		}
	}
	s[s.length()-1] = (s[s.length()-1] - 'a' + k % 26LL) % 26 + 'a';
    cout << s << endl;
}

int main(int argc, char *argv[]){
    ios::sync_with_stdio(false);
    std::cin.tie(0);
    freopen("C.in", "r", stdin);    
    while(cin >> s >> k) {
	    solve();
	}
    return 0;
}
