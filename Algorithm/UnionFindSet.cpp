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

struct union_set {
	vector<int> parent;
	union_set(int n): parent(vector<int>(n, 0)) {
		while(n--) parent[n] = n;
	};
	int find(int v) {
		if(parent[v] == v) return v;
		return parent[v] = find(parent[v]);
	}
	void merge(int v1, int v2) {
		parent[find(v1)] = find(v2);
	}
};

int main(void) {
	union_set s(5);
	
	FOR(i, 0, 5) cout << s.find(i) << " ";
	cout << endl;
	
	s.merge(0, 1);
	
	FOR(i, 0, 5) cout << s.find(i) << " ";
	cout << endl;
	
	return 0;
}
