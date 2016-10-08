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

LL x;

void print(LL n) {
	for(int i=31; i>=0; i--) {
		cout << (n >> i & 1);
	}
	cout << endl;
}

void solve(){
	cout << "x=" << endl;
	print(x); 
	LL rightOne = x & -x;
	cout << "-x=" << endl;
 	print(-x); 
 	cout << "rightOne=" << endl;
    print(rightOne); 
    // reset the pattern and set next higher bit
    // left part of x will be here
    LL nextHigherOneBit = x + rightOne;
 	cout << "nextHigherOneBit=" << endl;
	print(nextHigherOneBit);
    // nextHigherOneBit is now part [D] of the above explanation.
 
    // isolate the pattern
    LL rightOnesPattern = x ^ nextHigherOneBit;
 	cout << "rightOnesPattern=" << endl;
	print(rightOnesPattern);
 	
    // right adjust pattern
    rightOnesPattern = (rightOnesPattern)/rightOne;
 	cout << "rightOnesPattern=" << endl;
	 print(rightOnesPattern);
 	
    // correction factor
    rightOnesPattern >>= 2;
    cout << "rightOnesPattern=" << endl;
 	print(rightOnesPattern);
 	
    // rightOnesPattern is now part [A] of the above explanation.
 
    // integrate new pattern (Add [D] and [A])
    LL next = nextHigherOneBit | rightOnesPattern;
    print(next);
    
	cout << next << endl;
}

void solve2(){
	LL res = x + 1;
	int cnt = __builtin_popcountll(x);
	while(__builtin_popcountll(res) != cnt) {
		res += 1;
	}
	cout << res << endl;
}

int main(int argc, char *argv[]){
    ios::sync_with_stdio(false);
    std::cin.tie(0);
    freopen("Netease02.in", "r", stdin);    
    while(cin >> x) {
    	solve();
    }
    return 0;
}
