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
	return len++;
}

//'p': grey, 'f': black, 'e': white
int p;
void build(struct node * tree, const string & str, int k){
	if(p >= str.length()){
		return;
	}
	char c = str[p++];
	tree[k].c = c;
	if(c == 'p'){
		for(int i=0;i<4;i++){
			tree[k].child[i] = alloc(tree);
			build(tree, str, tree[k].child[i]);
		}
	}
}

int f(struct node * tree, int n, int area){
	int res = 0;
	if(tree[n].c == 'p'){
		for(int i=0;i<4;i++){
			res += f(tree, tree[n].child[i], area / 4);
		}
	}else if(tree[n].c == 'f'){
		res += area;
	}
	return res;
}

int calc(int p1, int p2, int area){
	char c1 = tree1[p1].c;
	char c2 = tree2[p2].c;
	int res;
	if(c1 == 'f' || c2 == 'f'){
		res = area;
	}else if(c1 == 'e'){
		if(c2 == 'e'){
			//ee
			res = 0;
		}else{
			//ep
			res = f(tree2, p2, area);
		}
	}else{
		if(c2 == 'e'){
			//pe
			res = f(tree1, p1, area);
		}else{
			//pp
			res = 0;
			for(int i=0;i<4;i++){
				res += calc(tree1[p1].child[i], tree2[p2].child[i], area / 4);
			}
		}
	}
	return res;
}

void solve(){
	string a, b;
	
	getline(cin, a);
	getline(cin, b);
	
	p = 0;
	len = 0;
	build(tree1, a, alloc(tree1));
	
	p = 0;
	len = 0;
	build(tree2, b, alloc(tree2));
	
	printf("There are %d black pixels.\n", calc(0, 0, 1024));
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
