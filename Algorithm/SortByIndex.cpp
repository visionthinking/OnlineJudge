#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

using namespace std;

int a[] = {2, 6, 5, 1, 3, 4, 0};
int n = sizeof(a) / sizeof(a[0]);

bool mycmp(int v1, int v2){
	return a[v1] < a[v2];
}

int main(void){
	int b[n];
	for(int i=0;i<n;i++){
		b[i] = i;
	}
	
	sort(b, b+n, mycmp);
	
	for(int i=0;i<n;i++){
		printf("%d ", b[i]);
	}
	
	return 0;
}
