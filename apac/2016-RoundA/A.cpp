#include <stdio.h>
#include <string.h>
#include <string>
#include <unordered_map>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef unsigned long long LL;

LL near(LL n) {
	return 1ull << (63ull - __builtin_clzll(n));
}

void solve(int kase) {
	LL n, m;
	int c = 0;
	scanf("%llu", &n);
	while(n != 1 && n != (m = near(n))) {
		c += 1;
		n = - n + m + m;
	}
	printf("Case #%d: %d\n", kase, c & 1);
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

