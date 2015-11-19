#include<stdio.h>
#include<stdlib.h>
#include<time.h>

// [a, b)
int rand_int(int a, int b){
	return a + (rand()%(b-a));
}

int main(){
	int n, m, i, j, k;
	srand((int)time(0));
	n = 100;
	printf("%d\n", n);
	for(i=0;i<n;i++){
		m = rand_int(1, 50);
		printf("%d\n", m);
		for(j=0;j<m;j++){
			printf("%d %d %d %d %d %d\n", rand_int(0, 1001), rand_int(0, 1001), rand_int(0, 1001), rand_int(0, 1001), rand_int(0, 501), rand_int(0, 501));
		}
	}
	return 0;
}
