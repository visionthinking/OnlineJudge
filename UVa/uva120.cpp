#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include <algorithm>
#include <sstream>

using namespace std;

const int MAX = 100;
int a[MAX];
int s[MAX];
stringstream stream;

void printA(int len){
	printf("Debug: ");
	for(int i=0;i<len;i++){
		printf("%d ", a[i]);
	}
	printf("\n");
}

void solve(const string & str){
	printf("%s\n", str.c_str());
	int n = 0;
	int t, low;
	stream.clear();
	stream << str;
	while(stream >> t){
		a[n] = t;
		s[n] = t;
		n += 1;
	}
	sort(s, s+n);
	
	for(int i=n-1;i>0;i--){
		if(s[i] != a[i]){
			for(int j=0;j<n;j++){
				if(a[j] == s[i]){
					low = j;
					break;
				}
			}
			if(low == 0){
				reverse(a, a + i + 1);
				printf("%d ", n - i);
			}else{
				reverse(a, a + low + 1);
				printf("%d ", n - low);
				reverse(a, a + i + 1);
				printf("%d ", n - i);
			}
		}
	}
	printf("0\n");
}

int main(void){
	freopen("uva120.in", "r", stdin);
	ios::sync_with_stdio(false);
	
	string str;
	while(getline(cin, str)){
		solve(str);
	}
	
	return 0;
}
