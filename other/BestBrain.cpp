#include <stdio.h>
#include <string.h>
#include <string>
#include <unordered_map>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <iomanip>

using namespace std;

string a, x1, x2;

void solve() {
	bool forward = false, backward = false;
	size_t p1, p2;
	
	p1 = a.find(x1);
	if(p1 != string::npos) {
		p2 = a.find(x2, p1 + x1.length());
		if(p2 != string::npos) {
			forward = true;	
		}
	}
	
	reverse(a.begin(), a.end());
	p1 = a.find(x1);
	if(p1 != string::npos) {
		p2 = a.find(x2, p1 + x1.length());
		if(p2 != string::npos) {
			backward = true;	
		}
	}
	
	if(forward && backward) {
		cout << "both\n";
	} else if(forward){
		cout << "forward\n";
	} else if(backward){
		cout << "backward\n";
	} else {
		cout << "invalid\n";
	}
}

int main(void) {
	ios::sync_with_stdio(false);
	freopen("BestBrain.in", "r", stdin);
	while(cin >> a) {
		cin >> x1 >> x2;
		solve();
	}
	return 0; 
} 
