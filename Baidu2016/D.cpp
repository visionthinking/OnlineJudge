#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <map>
#include <string>
#include <iostream>
#include <string.h>

using namespace std;

int n;
map<string, int> mark;

void solve(){
	mark.clear();
	char t[50];
	int len;
	for(int i=0; i<n; i+=1){
		cin >> t;
		len = strlen(t);
		sort(t, t+len);
		string s(t);
		if(mark.count(s) == 0){
			mark[s] = 0;	
		}
		cout << mark[s] << endl;
		mark[s] += 1;
	}
}

int main(void){
	ios::sync_with_stdio(false);
	freopen("D.in", "r", stdin);
	while(cin >> n){
		solve();	
	}
	return 0;
}
