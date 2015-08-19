#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

inline 
int min(int a, int b){
	return a < b ? a : b;	
}

string msg;
string word[601];
int d[301], len[601];
int w, l;

void solve(){
	for(int i=0;i<l;i++){
		if(i == 0){
			d[i] = 1;	
		}else{
			d[i] = d[i-1] + 1;
		}
		for(int k=0;k<w;k++){
			if(len[k]>i+1){
				continue;
			}
			int j = i, now = len[k] - 1;
			while(j >= 0 && now >= 0 && len[k] > i+1-j-d[i]){
				if(msg[j] == word[k][now]){
					now -= 1;	
				}
				j -= 1;
			}
			int remove;
			if(now < 0){
				remove = i - j - len[k];
				d[i] = min( d[i], (j<0?0:d[j])+remove );
			}
		}
	}
	cout << d[l-1] << endl;
}

int main(){
	freopen("p3267.in", "r", stdin);
	ios::sync_with_stdio(false);
	cin >> w >> l;
	cin >> msg;
	for(int i=0;i<w;i++){
		cin >> word[i];
		len[i] = word[i].length();
	}
	solve();
	return 0;
}

	
