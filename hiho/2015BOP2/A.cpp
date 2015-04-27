#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <algorithm>
#include <vector>
using namespace std;

const int MAX =  55;
struct node {
	char c[3];	
};
struct node a[MAX];

bool mycmp(const struct node & a, const struct node & b){
	if(a.c[0] == b.c[0]){
		return a.c[1] < b.c[1];
	}
	return a.c[0] < b.c[0];
}

void solution(){
	int n;
	memset(a, 0, sizeof(a));
	scanf("%d ", &n);
	for(int i=0;i<n;i++){
		a[i].c[2] = 0;
		scanf("%c%c ", &a[i].c[0], &a[i].c[1]);
		//printf("%c%c\n", a[i].c[0], a[i].c[1]);
	}
	sort (a, a+n, mycmp);
	
	long long unsigned count = 0;
	do {
		bool flag = true;
		for(int i=1;i<n;i++){
			if(a[i].c[0] == a[i-1].c[0]){
				flag = false;
				break;
			}
		}
		if(flag){
			count += 1;	
		}
		//printf("%c%c %c%c %c%c \n", a[0].c[0], a[0].c[1], a[1].c[0], a[1].c[1],a[2].c[0], a[2].c[1]);
	} while ( next_permutation(a, a+n, mycmp) );
	printf("%lld\n", count);
}

int main(void){
	freopen("A.in", "r", stdin);
	int t, i;
	while(scanf("%d", &t)!=EOF){
		for(i=1;i<=t;i++){
			printf("Case #%d: ", i);
			solution();
		}
	}
	return 0;
}


