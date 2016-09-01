#include <stdio.h>
#include <string.h>
#include <string>
#include <unordered_map>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define MAX_LINE 100

int readline(char * a){
	fgets(a, MAX_LINE, stdin);
	int len = strlen(a);
	if(a[len-1] == '\n'){
		a[len-1] = 0;
		len -= 1;
	}
	return len;
}

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

