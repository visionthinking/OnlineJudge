#include <stdio.h>

void quick_sort(int * a, int len) {
	if (len <= 1) return;
	int m = a[0], i = 0, j = len - 1;
	while(i<j){
		while(i < j && a[j] > m) j -= 1;
		a[i] = a[j];
		while(i < j && a[i] < m) i += 1;
		a[j] = a[i];
	}
	a[i] = m;
	quick_sort(a, i+1);
	quick_sort(a+i+1, len-(i+1));
}

int main(void){
	int a[] = {3,4,6,2,5,21,1};
	int len = sizeof(a)/sizeof(a[0]);
	quick_sort(a, len);
	
	for(int i=0;i<len;i+=1){
		printf("%d ", a[i]);
	}
	return 0;
}
