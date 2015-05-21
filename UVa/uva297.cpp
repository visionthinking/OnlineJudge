#include <stdio.h>
#include <string.h>
#include <string>
#include <iostream>
using namespace std;

struct node {
	char c;
	int child[4];
};

const int MAX = 10000;
struct node tree1[MAX];
struct node tree2[MAX];
int len;

int alloc(struct node * tree){
	memset(tree[len].child, -1, sizeof(int)*4);
	return len++;
}

//'p': grey, 'f': black, 'e': white
int p;
void build(struct node * tree, const string & str){
	if(p >= str.length()){
		return;
	}
	int k;
	char c = str[p];
	p += 1;
	
	if(c == 'f' || c == 'e'){
		k = alloc(tree);
		tree[k].c = c;
	}else if(c == 'p'){
		k = alloc(tree);
		tree[k].c = c;
		
	}
}

int calc(){

}

void solve(){
	string a, b;
	
	getline(cin, a);
	getline(cin, b);
	len = 0;p = 0;
	build(tree1, a);
	len = 0;p = 0;
	build(tree2, b);
	
	printf("There are %d black pixels.\n", calc());
}

int main(void){
	freopen("uva297.in", "r", stdin);
	ios::sync_with_stdio(false);
	int t;
	cin >> t;
	cin.get();
	for(int i=0;i<t;i++){
		solve();
	}
	return 0;
}
