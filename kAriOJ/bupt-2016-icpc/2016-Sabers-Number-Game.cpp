/* 981. 2016 ICPC - Saber's Number Game */
#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <ctype.h>
#include <algorithm>
#include <set>
using namespace std;

const int MAX = 1005;

int parent[MAX];
int union_find(int v){
	if(parent[v] == v)
		return v;
	return parent[v] = union_find(parent[v]);
}

int union_merge(int v1, int v2){
	parent[union_find(v1)] = union_find(v2);	
}

void union_init(){
	for(int i=0; i<MAX; i+=1){
		parent[i] = i;
	}
}

int union_num_count(int v){
	int cnt = 0, s = union_find(v);
	for(char c='0'; c<='9'; c+=1){
		if(s == union_find(c)){
			cnt += 1;
		}
	}
	return cnt;
}

char union_get_num(int s){
	for(char c='0'; c<='9'; c+=1){
		if(s == union_find(c)){
			return c;
		}
	}
	return -1;
}

bool union_has_num(int s){
	for(char c='0'; c<='9'; c+=1){
		if(s == union_find(c)){
			return true;
		}
	}
	return false;
}

int n;
char a[MAX], b[MAX];
void solve(){
	scanf("%d\n", &n);
	scanf("%s", a);
	scanf("%s", b);
	
	union_init();
	for(int i=0; i<n; i+=1){
		union_merge(a[i], b[i]);
	}
	for(int i=0; i<n; i+=1){
		if(union_num_count(a[i]) >= 2 || union_num_count(b[i]) >= 2){
			printf("0\n");
			return;
		}
	}
	
	set<int> x;
	for(int i=0; i<n; i+=1){
		int u = union_find(a[i]);
		if(!union_has_num(u)){
			x.insert(u);
		}
	}
	int first = 9, cnt = x.size();
	int first_set = union_find(a[0]);
	if(union_get_num(first_set) == '0'){
		// if a[0] will be '0', it's illegal.
		printf("0\n");
		return;
	}
	if(union_has_num(first_set)){
		first = 1;
	}else{
		cnt -= 1;	
	}
	printf("%d", first);
	for(int i=0; i<cnt; i+=1){
		printf("0");
	}
	printf("\n");
}

int main(void){
	freopen("p981.in", "r", stdin);
	int kase;
	while(scanf("%d\n", &kase) != EOF){
		for(int i=1; i<=kase; i+=1){
			solve();
		}
	}
	return 0;
}
