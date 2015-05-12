#include <string.h>
#include <stdio.h>
#include <string>
#include <iostream>
#include <sstream>

using namespace std;

struct node {
	int data;
	int left, right;	
};
const int MAX = 20000;
struct node tree[MAX];
int tlen;
stringstream stream;
int a[MAX];
int b[MAX];

int alloc(){
	tree[tlen].left = tree[tlen].right = -1;
	return tlen++;	
}

void build(int n, int al, int bl, int len){
	if(len <= 0) return;
	int x, i;
	if(len == 1){
		tree[n].data = a[al];
	}
	x = b[bl+len-1];
	for(i=0;i<len;i++){
		if(a[al+i] == x){
			break;	
		}
	}
	
	int llen, rlen;
	llen = i;
	rlen = len - llen - 1;
	if(llen > 0){
		tree[n].left = alloc();
	}
	if(rlen > 0){
		tree[n].right = alloc();
	}
}

void solve(const string & inorder, const string & postorder){
	int len, i, j, p, t;
	
	stream.clear();
	stream << inorder;
	i = 0;
	while(stream >> t){
		a[i] = t;
		i += 1;
	}
	
	stream.clear();
	stream << postorder;
	i = 0;
	while(stream >> t){
		b[i] = t;
		i += 1;
	}
	len = i;
	
	tlen = 0;
	alloc();
	//build(0, 0, len-1);
}

int main(void){
	freopen("uva548.in", "r", stdin);
	string a, b;
	while(getline(cin, a)){
		getline(cin, b);
		solve(a, b);
	}
	return 0;
}
