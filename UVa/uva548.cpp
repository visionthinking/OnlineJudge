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
long long minsum;
long long minval;

inline 
int alloc(){
	tree[tlen].data = -1;
	tree[tlen].left = tree[tlen].right = -1;
	return tlen++;	
}

void debug(int n){
	if(n == -1) return;
	
	printf("debug: %d: %d\n", n, tree[n].data);
	debug(tree[n].left);
	debug(tree[n].right);
}

void build(int n, int al, int bl, int len, long long sum){
	if(len <= 0) return;
	int x, i;
	x = b[bl+len-1];
	tree[n].data = x;
	if(len == 1){
		if(minsum > sum + x){
			minsum = sum + x;
			minval = x;
		}else if(minsum == sum + x && minval > x){
			minval = x;
		}
		return;
	}
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
		build(tree[n].left, al, bl, llen, sum + x);
	}
	if(rlen > 0){
		tree[n].right = alloc();
		build(tree[n].right, al+llen+1, bl+llen, rlen, sum + x);
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
	
	if(len == 0) return; //Prevent a blank line
	
	tlen = 0;
	alloc();
	minsum = 1000000;
	minval = 1000000;
	build(0, 0, 0, len, 0);
	
	printf("%lld\n", minval);
}

int main(void){
	freopen("uva548.in", "r", stdin);
	ios::sync_with_stdio(false);
	string a, b;
	while(getline(cin, a)){
		getline(cin, b);
		solve(a, b);
	}
	return 0;
}
