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
	printf("Case #%d: %s\n", kase);
}

int main(void){
	freopen("A-large-practice.in", "r", stdin);
	int kase;
	scanf("%d\n", &kase);
	for(int i=1; i<=kase; i+=1){
		solve(i);	
	}
	return 0;
}

