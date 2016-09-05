/*
http://www.practice.geeksforgeeks.org/problem-page.php?pid=171
Maximum Rectangular Area in a Histogram
use a stack
*/

#include <stdio.h>
#include <string.h>
#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <stack>
#include <algorithm>

using namespace std;


int a[105];

void solve() {
	int n, res;
	stack<int> s;
	
	scanf("%d", &n);
	for(int i=0; i<n; i+=1) {
		scanf("%d", &a[i]);
	}
	
	res = 0;
	for(int i=0; i<n; i+=1) {
		if(s.empty() || a[s.top()] <= a[i]) {
			s.push(i);
		} else {
			while(!s.empty() && a[s.top()] > a[i]) {
				int index = s.top();
				s.pop();
				int width = i - (s.empty() ? 0 : s.top() + 1);
				// printf("%d: %d*%d\n", index, a[index], width);
				res = max(res, a[index] * width);
			}
			s.push(i);
		}
	}
	while(!s.empty()) {
		int index = s.top();
		s.pop();
		int width = n - (s.empty() ? 0 : s.top() + 1);
		// printf("%d: %d*%d\n", index, a[index], width);
		res = max(res, a[index] * width);
	}
	
	printf("%d\n", res);
}

int main(void) {
	freopen("Maximum-Rectangular-Area-in-a-Histogram.in", "r", stdin);
	int kase;
	scanf("%d", &kase);
	for(int i=1; i<=kase; i+=1) {
		solve();
	}
	return 0;	
}
