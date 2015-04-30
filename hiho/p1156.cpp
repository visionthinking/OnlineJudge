#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <vector>
using namespace std;
const int MAX = 110000;

struct node {
	int color;
	vector<int> v;
};

struct node a[MAX];
long long _count;
int n;

void change(int x, int color){
	if(a[x].color == color){
		return;
	}
	int old = a[x].color;
	int len = a[x].v.size();
	int other;
	a[x].color = color;
	for(int i=0;i<len;i++){
		other = a[x].v[i];
		if(a[other].color == color){
			_count -= 1;
		}else if(a[other].color == old){
			_count += 1;
		}
	}
}

void solution(){
	int x, y, q, j, i, op;
	_count = 1;
	//memset(a, 0, sizeof(a));
	
	scanf("%d", &n);
	for(i=1;i<n;i++){
		a[i].color = 0;
		a[i].v.clear();
		a[i].v.reserve(100);
	}
	
	for(i=1;i<n;i++){
		scanf("%d %d", &x, &y);
		a[x].v.push_back(y);
		a[y].v.push_back(x);
	}
	
	scanf("%d", &q);
	for(i=0;i<q;i++){
		scanf("%d", &op);
		if(op == 1){
			printf("%lld\n", _count);	
		}else if(op == 2){
			scanf("%d %d", &x, &y);
			change(x, y);
		}
	}
}

int main(void){
	freopen("p1156.in", "r", stdin);
	int t, i;
	while(scanf("%d", &t)!=EOF){
		for(i=1;i<=t;i++){
			printf("Case #%d:\n", i);
			solution();
		}
	}
	return 0;
}
