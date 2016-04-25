#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <ctype.h>
#include <algorithm>
#include <iostream>
#include <string>
#include <map>
#include <vector>

using namespace std;

const int MAXN = 105;
int m, n;
map< string, vector<int> > colors;
int dp[100010];

int f(const vector<int> & v){
	memset(dp, 0, sizeof(dp));
	int sum = 0, len = v.size(), min_bound, max_ele = -1;
	for(int i=0; i<len; i+=1){
		sum += v[i];
		max_ele = max(max_ele, v[i]);
	}
	min_bound = max((sum+1)/2, max_ele);
	for(int i=0; i<len; i+=1){
		for(int j=sum; j>=v[i]; j-=1){
			dp[j] = max(dp[j], dp[j-v[i]] + v[i]);
		}
//		for(int j=0; j<=sum; j+=1){
//			cout << dp[j] << " ";
//		}
//		cout << endl;
	}
	for(int j=min_bound; j<=sum; j+=1){
		if(dp[j] >= min_bound){
			return dp[j];
		}
	}
	return -1;
}

void solve(){
	colors.clear();
	for(int i=0; i<m; i+=1){
		string color;
		cin >> color;
		colors[color] = vector<int>();
	}
	for(int i=0; i<n; i+=1){
		int cnt;
		string color;
		cin >> cnt >> color;
		colors[color].push_back(cnt);
	}
	
	int sum = 0;
	for(map< string, vector<int> >::iterator it = colors.begin(); it != colors.end(); ++it){
		const vector<int> & v = it->second;
//		for(int j=0; j<v.size(); j+=1){
//			cout << it->first << " " << v[j] << endl;
//		}
		sum += f(v);
	}
	cout << sum << "\n";
}

int main(void){
	freopen("poj3211.in", "r", stdin);
	ios::sync_with_stdio(false);
	while(cin >> m >> n){
		if(m == 0 && n == 0){
			break;	
		}
		
		solve();
	}
	return 0;
}
