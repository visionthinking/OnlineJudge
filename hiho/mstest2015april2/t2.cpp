#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <limits.h>
using namespace std;

const int MAX = 10000;
int a[MAX];
int n;

void input(){
	scanf("%d", &n);
	int min_num = INT_MAX;
	for(int i=0; i<n; i+=1){
		scanf("%d", &a[i]);
		min_num = min(min_num, a[i]);
	}
	
	for(int i=1; i<n; i+=1){
		if(a[i] > ){
				
		}
	}
}

void solve(){
	
}

int main(void){
	freopen("t2.in", "r", stdin);
	int kase = 0;
	while(scanf("%d", &kase) != EOF){
		for(int i=1;i<=kase;i+=1){
			input();
			solve();
		}
	}
	return 0;	
}
