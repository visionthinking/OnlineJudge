#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

int my_lower_bound(int * a, int len, int key){
	if(len == 0) return -1;
	
	int l = 0, r = len-1;
	int m, pos = -1;
	
	while(l < r){
		m = l + (r-l) / 2;
		if(a[m] < key){
			l = m + 1;
			pos = l;
		}else{
			r = m;
			pos = r;	
		}
	}
	return pos;
}

int main(void){
	int a[] = {1, 3, 5, 6, 8, 10};
	printf("%d\n", my_lower_bound(a, 6, 5));
	return 0;
}
