#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <ext/hash_map>
using namespace std;
using __gnu_cxx::hash_map;
#define uint unsigned int

const int MAX = 100005 * 32;

int n, m;
hash_map<uint, int> rules[33];

struct rule {
	uint ip;
	int allow, mask;
};
struct rule a[100005];

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
	int i = 32 - mask;
	uint v = i==32 ? 0:(ip >> i);
	if(rules[mask].count(v) == 0){
		rules[mask][v] = index;
	}
}

int query(uint ip){
	int min_index = MAX, min_allow = -1;
	for(int i=0; i<=32; i+=1){
		uint v = i==0 ? 0:(ip >> (32-i));
		if(rules[i].count(v) > 0){
			int idx = rules[i][v];
			if(idx < min_index){
				min_index = idx;
				min_allow = a[idx].allow;
			}
		}
	}
	return min_allow;
}

void input(){
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
		a[i].allow = allow;
		a[i].ip = ip;
		a[i].mask = mask;
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
