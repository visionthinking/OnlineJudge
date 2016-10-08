#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <sstream>
using namespace std;

int x[10000];

int main(void) {
	memset(x, 0, sizeof(x));
	for(int i=0; i<9997; i+=1) {
		int a;
		scanf("%d", &a);
		x[a] = 1;
	}
	stringstream s;
	for(int i=1; i<=10000; i+=1) {
		if(x[i] == 0) {
			s << i;
		}
	}
	long long n;
	s >> n;
	printf("%lld", n % 7ll);
	return 0;
}
