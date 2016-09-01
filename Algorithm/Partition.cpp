#include <algorithm>
#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

#define PRED(x) (x > pivot)
int _partition(int * a, int left, int right) {
	int pivot = a[0];
	while (left != right) {
		while (PRED(a[left])) {
			left += 1;
			if (left == right) return left;
		}
		do {
			right -= 1;
			if (left == right) return left;
		} while (!PRED(a[right]));
		swap(a[left], a[right]);
		left += 1;
	}
	return left;
}

int partition(int * a, int beg, int end) {
	int pivot = a[0];
	swap(a[0], a[end]);
	
	int i = beg - 1;
	for (int j = beg; j < end; j++) {
		if (PRED(a[j])) {
			swap(a[++i], a[j]);	
		}	
	}
	
	swap(a[i+1], a[end]);
	return i+1;
}

int top_k(int * a, int left, int right, int k) {
	int p = partition(a, left, right);
	int current_len = p - left + 1;
	if(current_len > k) return top_k(a, left, p, k);
	else if(current_len < k) return top_k(a, p+1, right, k-current_len);
	return p;
}

void test_partition(){
	int a[] = {1, 2, 3, 4};
	int len = sizeof(a) / sizeof(int);
	int bound = partition(a, 0, len-1);
	printf("bound = %d\n", bound);
	for(int i=0; i<len; i+=1){
		printf("%d ", a[i]);	
	}
	printf("\n");
}

void test_top_k() {
	int a[] = {3, 2, 5, 8, 1, 10};
	int len = sizeof(a) / sizeof(int);
	top_k(a, 0, len-1, 3);
	
	for(int i=0; i<len; i+=1){
		printf("%d ", a[i]);	
	}
	printf("\n");
}

int main(void){
	test_partition();
	test_top_k();
	return 0;
}


