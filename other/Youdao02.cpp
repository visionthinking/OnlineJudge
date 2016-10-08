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

int n, k, m;
int a[105][105];
int xc, yc;

int distance(int x, int yr, int yl) {
	int sum = 0;
	for(int y=yr; y<=yl; y+=1) {
		sum += abs(x - xc) + abs(y - yc);
	}
	return sum;
}

bool empty_seat(int x, int yr, int yl) {
	for(int y=yr; y<=yl; y+=1) {
		if(a[x][y] != 0) {
			return false;	
		}
	}
	return true;
}

void sit_down(int x, int yr, int yl) {
	for(int y=yr; y<=yl; y+=1) {
		a[x][y] = 1;
	}
}

void print() {
	FOR(i, 1, k+1) {
		FOR(j, 1, k+1) {
			cout << " " << a[i][j];	
		}
		cout << endl;
	}
	cout << endl;
}

void solve(){
	xc = (k+1) / 2;
	yc = (k+1) / 2;
	memset(a, 0, sizeof(a));
    FOR(kase, 0, n) {
		cin >> m;
		if(m > k) {
			cout << -1 << endl;
			continue;
		}
		int min_row = INT_MAX, min_col = INT_MAX, min_d = INT_MAX;
		FOR(row, 1, k+1) {
			for(int col = 1; col <= k - m + 1; col++) {
				if(empty_seat(row, col, col + m - 1)) {
					int d = distance(row, col, col + m - 1);
					if(d < min_d) {
						min_d = d;
						min_row = row; min_col = col;	
					}
				}
			}
		}
		if(min_d != INT_MAX) {
			sit_down(min_row, min_col, min_col + m - 1);
			cout << min_row << " " << min_col << " " << min_col + m - 1 << endl;	
		} else {
			cout << -1 << endl;
		}
	}
}

int main(int argc, char *argv[]){
    ios::sync_with_stdio(false);
    std::cin.tie(0);
    if(argc >= 2) {
        freopen(argv[1], "r", stdin);
    }else{
        freopen("youdao2.in", "r", stdin);    
    }
    while(cin >> n >> k) {
        solve();
    }
    return 0;
}
