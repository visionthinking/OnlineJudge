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

char a[100005];
int n, m;

int check(int x) {
	int i = 0, cnt = 0;
	while(i < n) {
		if(a[i] == '1') {
			i += max(1, x);
			cnt += 1;
		} else {
			i += 1;	
		}
	}
	return cnt;
}

void solve(int kase){
	scanf("%d %d\n", &n, &m);
    scanf("%s\n", a);
    int l = 0, r = n, mid;
    while(l < r) {
    	mid = (l+r) / 2;
    	if(check(mid) <= m) {
    		r = mid;
    	} else {
    		l = mid + 1;
    	}
    }
	printf("Case #%d: %d\n", kase, l);
}

int main(int argc, char *argv[]){
	freopen("Baidu03.in", "r", stdin);    
    int kase;
    scanf("%d\n", &kase);
    for(int i=1; i<=kase; i+=1){
        solve(i);    
    }
    return 0;
}


