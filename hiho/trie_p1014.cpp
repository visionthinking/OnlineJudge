#include <stdio.h>
#include <math.h>
#include <string.h>
#include <algorithm>
using namespace std;

const int MAX = 50 * 100000;
struct node {
	int child[2];
	int cnt;
} tree[MAX];
int n, m;

int tlen;

void init(){
	tlen = 0;
	new_node();
	memset(tree, -1, sizeof(tree));	
}

void new_node(){
	tree[tlen].cnt = 0;
	return tlen++;
}

int main(void){
	freopen("p1014.in", "r", stdin);
	scanf("%d %d\n", &n, &m);
	for(int i=0;i<n;i+=1){
		scanf("%s", a[i]);
	}
	solve();
	return 0;
}
