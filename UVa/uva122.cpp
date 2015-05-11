#include <stdio.h>
#include <string.h>
#include <string>
#include <iostream>
#include <algorithm>
#include <sstream>
#include <vector>

using namespace std;

struct node {
	int data;
	int left, right;	
};

const int MAX = 1000;
struct node tree[MAX];
int len;

int alloc(){
	return len++;
}

void debug(int n){
	printf("n=%d %d\n", n, tree[n].data);
	if(tree[n].left != -1){
		debug(tree[n].left);
	}else if(tree[n].right != -1){
		debug(tree[n].right);
	}
}

void solve(bool wtf){
	if(wtf){
		printf("not complete\n");
		return;
	}
	int q[MAX];
	vector<int> output;
	int i, j, qlen, p, is_root, is_legal;
	output.reserve(MAX);
	qlen = 1;
	q[0] = 0;
	p = 0;
	is_legal = true;
	while(p < qlen){
		int index = q[p];
		if(tree[index].data == -1){
			is_legal = false;
			break;
		}else{
			output.push_back(tree[index].data);
		}
		if(tree[index].left != -1){
			q[qlen] = tree[index].left;
			qlen += 1;
		}
		if(tree[index].right != -1){
			q[qlen] = tree[index].right;
			qlen += 1;
		}
		p += 1;
	}
	if(is_legal){
		for(i=0;i<output.size();i++){
			if(i > 0){
				printf(" ");	
			}
			printf("%d", output[i]);
		}
	
	}else{
		printf("not complete");	
	}
	printf("\n");
}

int main(void){
	freopen("uva122.in", "r", stdin);
	
	char c;
	bool left, right;
	int cc, num, p;
	bool wtf = false;
	memset(tree, -1, sizeof(tree));
	len = 1;
	p = 0;
	
	while(scanf("%c", &c) != EOF){
		if(c == '('){
			left = true;
			right = false;
			num = 0;
			cc = 0;
			p = 0;
		}else if(c == ')'){
			if(cc == 0){
				solve(wtf);
				memset(tree, -1, sizeof(tree));
				len = 1;
				wtf = false;
			}else if(right){
				if(tree[p].data != -1){
					wtf = true;	
				}
				tree[p].data = num;
			}
			left = false;
		}else if(c == ','){
			right = true;
			cc += 1;
		}else if('0' <= c && c <= '9'){
			num = num * 10 + c - '0';
			cc += 1;
		}else if(c == 'L'){
			if(tree[p].left == -1){
				tree[p].left = alloc();
			}
			p = tree[p].left;
			cc += 1;
		}else if(c == 'R'){
			if(tree[p].right == -1){
				tree[p].right = alloc();
			}
			p = tree[p].right;
			cc += 1;	
		}
	}
	
	return 0;
}
