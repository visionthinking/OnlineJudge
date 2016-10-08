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

using namespace std;

int N, L;
int a[1005];
unordered_set<int> x;

bool put(int i) {
	if(x.count(i) > 0) {
		return false;	
	}
	x.insert(i);
	return true;
}

bool put_range(int start, int len) {
	x.clear();
	for(int i=0; i<len; i+=1) {
		int pos = start + i;
		if(pos >= 0 && pos < L) {
			if(!put(a[pos])) {
				return false;	
			}
		}
	}
	return true;
}

bool check(int n) {
	if(put_range(0, n) == false) return false;
	// printf("[%d, %d] ", 0, n);
	for(int j=1; j<=L/N; j+=1) {
		// printf("[%d, %d] ", n + (j-1) * N, n + j * N);
		if(put_range(n + (j-1) * N, N) == false) {
			return false;
		}
	}
	// printf("\n");
	return true;
}

void solve(int kase){
	scanf("%d%d", &N, &L);
	bool A = false; // shuffle
	for(int i=0; i<L; i+=1) {
		scanf("%d", &a[i]);
	}
	for(int i=1; i <= N; i+=1) {
		if(check(i)){
			A = true;
			break;	
		}
	}
	
	if(A) {
		printf("CANT'T DECIDE\n");
	} else {
		printf("B\n");
	}
}

int main(int argc, char *argv[]){
	if(argc >= 2) {
		freopen(argv[1], "r", stdin);
	}else{
		freopen("Award.in", "r", stdin);	
	}
	int kase;
	scanf("%d\n", &kase);
	for(int i=1; i<=kase; i+=1){
		solve(i);	
	}
	return 0;
}
