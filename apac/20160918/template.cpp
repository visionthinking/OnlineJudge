#include <stdio.h>
#include <string.h>
#include <string>
#include <unordered_map>
#include <map>
#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>

using namespace std;

void solve(int kase){
	long long res, L, R;
	scanf("%lld %lld", &L, &R);
	res = min(L, R);
	res = res * (res + 1) / 2;
	printf("Case #%d: %lld\n", kase, res);
}

int main(int argc, char *argv[]){
	if(argc >= 2) {
		freopen(argv[1], "r", stdin);
	}else{
		freopen("A.in", "r", stdin);	
	}
	int kase;
	scanf("%d\n", &kase);
	for(int i=1; i<=kase; i+=1){
		solve(i);	
	}
	return 0;
}

