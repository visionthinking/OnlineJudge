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

int a[100005];
void solve(){
    int n, res = 0;
    cin >> n;
    FOR(i, 1, n+1) cin >> a[i];
    FOR(i, 1, n+1) {
    	if(a[a[i]] == i) {
    		res += 1;
    	}
    }
    cout << res / 2 << endl;
}

int main(int argc, char *argv[]){
    ios::sync_with_stdio(false);
    std::cin.tie(0);
    if(argc >= 2) {
        freopen(argv[1], "r", stdin);
    }else{
        freopen("B.in", "r", stdin);    
    }
    solve();
    return 0;
}
