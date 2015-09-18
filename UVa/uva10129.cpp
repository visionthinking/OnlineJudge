#include <iostream>
#include <string>
#include <stdio.h>
#include <string.h>

using namespace std;

struct vertex {
	int in, out;
};
const int MAX = 26;
struct vertex v[MAX];
int parent[MAX];
int n;

void union_init(){
	for(int i=0;i<MAX;i++){
		parent[i] = i;
	}
}

int union_find(int v){
	if(parent[v] == v)
		return v;	
	return parent[v] = union_find(parent[v]);
}

void union_merge(int v1, int v2){
	parent[union_find(v1)] = union_find(v2);	
}

void solve(){
	int x = -1;
	int head_count = 0;
	int last_count = 0;
	for(int i=0;i<MAX;i++){
		if(v[i].in | v[i].out){
			if(x == -1){
				x = union_find(i);	
			}else if(x != union_find(i)){
				printf("The door cannot be opened.\n");
				return;
			}
			if(v[i].out == v[i].in + 1){
				head_count += 1;
			}else if(v[i].in == v[i].out + 1){
				last_count += 1;
			}else if(v[i].in != v[i].out){
				printf("The door cannot be opened.\n");
				return;
			}
		}
	}
	if(head_count > 1 || last_count > 1){
		printf("The door cannot be opened.\n");
	}else{
		printf("Ordering is possible.\n");
	}
}

int main(void){
	freopen("uva10129.in", "r", stdin);
	ios::sync_with_stdio(false);
	int t;
	string str;
	cin >> t;
	while(t--){
		cin	>> n;
		cin.get();
		memset(v, 0, sizeof(v));
		union_init();
		for(int i=0;i<n;i++){
			getline(cin, str);
			int head = str[0] - 'a';
			int last = str[str.length()-1] - 'a';
			v[head].out += 1;
			v[last].in += 1;
			union_merge(head, last);
		}
		solve();
	}
	return 0;
}
