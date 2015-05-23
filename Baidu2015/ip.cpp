#include <iostream>
#include <stdio.h>
#include <string.h>
#include <string>
#include <algorithm>
using namespace std;

typedef unsigned int uint;

const int MAXIP = 1010;
const int MAXMASK = 100;

uint ip[MAXIP];
uint mask[MAXMASK];

inline
uint convert(int a, int b, int c, int d){
	uint x = 0;
	x |= d;
	x |= c << 8;
	x |= b << 16;
	x |= a << 24;
	return x;
}

void solve(){
	int n, m, a, b, c, d, len, cnt;
	uint s[MAXIP];
	string line;
	
	cin >> n >> m;
	cin.get();
	for(int i=0;i<n;i++){
		do{
			getline(cin, line);
		}while(line.length() == 0);
		sscanf(line.c_str(), "%d.%d.%d.%d\n", &a, &b, &c, &d);
		ip[i] = convert(a, b, c, d);
	}
	
	for(int i=0;i<m;i++){
		do{
			getline(cin, line);
		}while(line.length() == 0);
		sscanf(line.c_str(), "%d.%d.%d.%d\n", &a, &b, &c, &d);
		uint mask = convert(a, b, c, d);
		for(int j=0;j<n;j++){
			s[j] = ip[j] & mask;
		}
		sort(s, s+n);
		cnt = 1;
		for(int j=1;j<n;j++){
			if(s[j] != s[j-1]){
				cnt += 1;	
			}
		}
		printf("%d\n", cnt);
	}
}

int main(void){
	freopen("ip.in", "r", stdin);
	ios::sync_with_stdio(false);
	int t;
	while(cin >> t){
		for(int i=1;i<=t;i++){
			printf("Case #%d:\n", i);
			solve();
		}
	}
	return 0;
}
