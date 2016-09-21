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

typedef long double LD;

LD sum[1005];

void solve(int kase) {
	int n, m, a;
	cin >> n >> m;
	
	sum[0] = 0.L;
	for(int i=0; i<n; i+=1) {
		cin >> a;
		sum[i+1] = log10((LD) a) + sum[i];
	}
	
	cout << "Case #" << kase << ":\n";
	
	for(int i=0; i<m; i+=1) {
		int L, R;
		cin >> L >> R;
		LD d = R-L+1;
		cout << setprecision(10) << fixed << pow(10.L, (sum[R+1] - sum[L]) / d) << endl;
	}
}

int main(int argc, char *argv[]){
	ios::sync_with_stdio(false);
	if(argc >= 2) {
		freopen(argv[1], "r", stdin);
	}else{
		freopen("B.in", "r", stdin);	
	}
	int kase;
	cin >> kase;
	for(int i=1; i<=kase; i+=1){
		solve(i);	
	}
	return 0;
}

