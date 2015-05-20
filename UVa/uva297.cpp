#include <stdio.h>
#include <string.h>
#include <string>
#include <iostream>
using namespace std;

string a, b;
int pa, pb;

//'p': grey, 'f': black, 'e': white
int build(int area){
	if(pa >= a.length() || pb >= b.length()){
		return 0;	
	}
	char ca = a[pa];
	char cb = b[pb];
	int result = 0;
	if(ca == 'f' || cb == 'f'){
		if(ca == 'p'){
			//遍历每遇到一个p要pa+=4	
		}else{
			pa += 1;	
		}
		if(cb == 'p'){
				
		}else{
			pb += 1;	
		}
		return area;
	}
	if(ca == cb && ca == 'e'){
		pa += 1;
		pb += 1;
		return 0;
	}
	return result;
}

void solve(){
	getline(cin, a);
	getline(cin, b);
	pa = 0;
	pb = 0;
	printf("There are %d black pixels.\n", build(1024));
}

int main(void){
	freopen("uva297.in", "r", stdin);
	ios::sync_with_stdio(false);
	int t;
	cin >> t;
	cin.get();
	for(int i=0;i<t;i++){
		solve();
	}
	return 0;
}
