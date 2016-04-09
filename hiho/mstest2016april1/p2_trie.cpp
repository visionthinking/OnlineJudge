#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

#define uint int

const int MAX = 100005 * 32;

struct node {
	int child[2];
	int allow, index;
};
 
struct node tree[MAX];
int tlen = 0, n, m;

int new_node(){
	tlen += 1;
	return tlen - 1;
}

uint read_ip(){
	int ip[4];
	scanf("%d.%d.%d.%d", &ip[0], &ip[1], &ip[2], &ip[3]);
	return (ip[0] << 24) | (ip[1] << 16) | (ip[2] << 8) | (ip[3]); 
}

void print_ip(uint ip, int mask){
	for(int i=31; i>=32 - mask; i-=1){
		printf("%d", ((ip >> i) & 1));
	}
	printf("\n");
}

void insert(uint ip, int mask, int allow, int index){
	if(mask == 0){
		if(tree[0].index == -1){
			tree[0].allow = allow;
			tree[0].index = index;
			return;
		}
	}
	int rt = 0;
	for(int i=31; i>=32-mask; i-=1){
		int v = (ip >> i) & 1;
		if(tree[rt].child[v] == -1){
			tree[rt].child[v] = new_node();
		}
		rt = tree[rt].child[v];
		if(i == 32-mask){
			if(tree[rt].index == -1){
				tree[rt].allow = allow;
				tree[rt].index = index;
			}
		}
	}
}

int query(uint ip){
	int rt = 0, min_index = MAX, min_allow = tree[0].allow;
	for(int i=31; i>=0; i-=1){
		int v = (ip >> i) & 1;
		if(tree[rt].allow != -1){
			if(tree[rt].index != -1 && tree[rt].index < min_index){
				min_index = tree[rt].index;
				min_allow = tree[rt].allow;
			}
		}
		rt = tree[rt].child[v];
		if(rt == -1) break;
	}
	return min_allow;
}

void input(){
	memset(tree, -1, sizeof(tree));
	tlen = 0;
	new_node();
	
	for(int i=0; i<n; i+=1){
		char tmp[10], c;
		uint ip; 
		int mask = 32, allow;
		
		scanf("%s", tmp);
		ip = read_ip();
		scanf("%c", &c);
		if(c == '/'){
			scanf("%d\n", &mask);	
		}
		allow = (strcmp("allow", tmp) == 0) ? 1 : 0;
		
//		printf("ip=%x allow=%d mask=%u\n", ip, allow, mask);
//		print_ip(ip, mask);
		insert(ip, mask, allow, i);
	}
}

void solve(){
	for(int i=0; i<m; i+=1){
		uint ip = read_ip();
//		print_ip(ip, 32);
		if(query(ip) == 0){
			printf("NO\n");
		}else{
			printf("YES\n");
		}
	}
}

int main(void){
	freopen("p2.in", "r", stdin);
	while(scanf("%d %d", &n, &m) != EOF){
		input();
		solve();
	}
	return 0;
}
