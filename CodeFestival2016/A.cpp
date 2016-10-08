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

void solve(int kase){
    cout << "Case #" << kase << ": " << 0 << endl;
}

int main(int argc, char *argv[]){
    ios::sync_with_stdio(false);
    std::cin.tie(0);
    string s;
	cin >> s;
	cout << s.substr(0, 4) << " " << s.substr(4) << endl;
    return 0;
}
