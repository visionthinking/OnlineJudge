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

#define FOR(i, a, b) for(int i=(a); i<(b); i++)
typedef long long LL;
typedef long double LD;

using namespace std;

int a[256];

void solve(){
	int res = 0, cnt;
    memset(a, 0, sizeof(a));
    string s;
    cin >> s;
    if(s.length() == 0) {
    	printf("0\n");
		return;
    }
	cnt = 1;
    for(int i=1; i<s.length(); i++) {
    	if(s[i] == s[i-1]) {
    		cnt += 1;
    	} else {
    		a[s[i-1]] = max(a[s[i-1]], cnt);
    		cnt = 1;	
    	}
    }
    a[s[s.length()-1]] = max(a[s[s.length()-1]], cnt);
    res = 0;
    FOR(i, 0, 256) {
    	res += a[i];
    }
	printf("%d\n", res);
}

int main(int argc, char *argv[]){
	freopen("Baidu01.in", "r", stdin);
    solve();
    return 0;
}


