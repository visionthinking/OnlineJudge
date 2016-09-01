#include <algorithm>
#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

/*
 最后把pivot交换到i的位置，返回i。即，i左边都是<=a[i]
 */
int partition(int * a, int left, int right) {
    int pivot = a[left], i = left;
    for(int j = left + 1; j <= right; j += 1)
        if(a[j] <= pivot) swap(a[++i], a[j]);
    swap(a[left], a[i]);
    return i;
}

int quick_select(int * a, int left, int right, int k) {
	if(left >= right) return left;
	int p = partition(a, left, right);
	if(p < k) return quick_select(a, p+1, right, k-p);
	else if(p > k) return quick_select(a, left, p-1, k);
	return p;
}

void print(int * a, int len){
	for(int i=0; i<len; i+=1){
		printf("%d ", a[i]);	
	}
	printf("\n");
}

void test_partition(int * a, int len){
	printf("partition:     ");
	int bound = partition(a, 0, len-1);
	print(a, len);
	printf("bound = %d\n", bound);
}

void test_quick_select(int * a, int len, int k){
	printf("quick_select:  ");
	quick_select(a, 0, len-1, k);
	print(a, k);
}

void test(){
	{
		int a[] = {1, 2, 3, 4, 5, 6, 7};
		int len = (sizeof(a) / sizeof(int));
		print(a, len);
		test_partition(a, len);
		test_quick_select(a, len, 3);
		putchar('\n');
	}
	{
		int a[] = {4, 3, 2, 1};
		int len = (sizeof(a) / sizeof(int));
		print(a, len);
		test_partition(a, len);
		test_quick_select(a, len, 2);
		putchar('\n');
	}
	{
		int a[] = {3, 2, 5, 8, 1, 10};
		int len = (sizeof(a) / sizeof(int));
		print(a, len);
		test_partition(a, len);
		test_quick_select(a, len, 4);
		putchar('\n');
	}
}

int main(void){
	test();
	return 0;
}
