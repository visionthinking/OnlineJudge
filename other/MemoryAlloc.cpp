#include <stdio.h>
#include <string.h>
#include <string>
#include <unordered_map>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <iomanip>
#include <list>
#include <map>

using namespace std;

int T, m;
struct node {
	int start, len;
	node(int _start, int _end): start(_start), end(_end) {};
	inline bool operator< (const node & x) {
		return start < x.start;
	}
};

char a[10005];
map<int, node> nodes;

void solve() {
	string cmd;
	int idx = 1;
	while(T--) {
		cin >> cmd;
		char c = cmd[2];
		if(c == 'w') {
			// new
			int need;
			cin >> need;
			
		} else if(c == 'l') {
			// del
			int id;
			cin >> id;
			
		} else if(c == 'f') {
			// def
				
		}
	}
}

int main(void) {
	ios::sync_with_stdio(false);
	freopen("MemoryAlloc.in", "r", stdin);
	while(cin >> T >> m) {
		solve();
	}
	return 0; 
} 
