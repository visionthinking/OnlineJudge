#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>
#include <deque>
#include <queue>
#include <string>
#include <iostream>
using namespace std;

const int MAX_PRG = 1024;
const int MAX_LINES = 50;

struct code {
	int type;
	int v;
	int value;
};

struct program {
	int id;
	struct code c[MAX_LINES];
	int run;
	int lines;
};

int n, m;
struct program prg[MAX_PRG];
int t[5];
deque<struct program *> dq;
int v[26];

void read(){
	dq.clear();
	memset(v, 0, sizeof(v));
	
	cin >> n;
	for(int i=0;i<5;i++){
		cin >> t[i];
	}
	cin >> m;
	cin.get();
	
	int i, j;
	char op;
	for(i=0;i<n;i++){
		prg[i].lines = 0;
		prg[i].id = i+1;
		prg[i].run = 0;
		dq.push_back(&prg[i]);
		
		string line;
		while(getline(cin, line)){
			struct code & c = prg[i].c[prg[i].lines];
			if(line.length() >= 3){
				op = line[2];
				if(op == '='){
					//v = value	
					c.type = 1;
					c.v = line[0] - 'a';
					sscanf(line.c_str() + 4, "%d", &c.value);
					prg[i].lines += 1;
				}else if(op == 'i'){
					//print v
					c.type = 2;
					c.v = line[6] - 'a';
					prg[i].lines += 1;
				}else if(op == 'c'){
					//lock
					c.type = 3;
					prg[i].lines += 1;
				}else if(op == 'l'){
					//unlock
					c.type = 4;
					prg[i].lines += 1;
				}else if(op == 'd'){
					//end
					c.type = 5;
					prg[i].lines += 1;
					break;
				}
			}
		}
		//printf("%d line=%d\n", prg[i].id, j);
	}
}
	
void solve(int solve_id){
	read();
	int M;
	bool lock = false;
	bool putback;
	queue<struct program *> q;
	while(!dq.empty()){
		struct program * top = dq.front();
		dq.pop_front();
		M = m;
		putback = true;
		
		while(M > 0){
			struct code & c = top->c[top->run];
			top->run += 1;
			
			if(c.type == 1){
				M -= t[0];
				v[c.v] = c.value;
			}else if(c.type == 2){
				M -= t[1];
				printf("%d: %d\n", top->id, v[c.v]);
			}else if(c.type == 3){
				if(lock){
					top->run -= 1;
					q.push(top);
					putback = false;
					break;
				}else{
					M -= t[2];
					lock = true;
				}	
			}else if(c.type == 4){
				M -= t[3];
				lock = false;
				if(!q.empty()){
					dq.push_front(q.front());
					q.pop();
				}
			}else if(c.type == 5){
				M -= t[4];
				putback = false;
				break;	
			}
		}
		
		if(putback){
			dq.push_back(top);	
		}
		
	}
}

int main(void){
	ios::sync_with_stdio(false);
	freopen("uva210.in", "r", stdin);
	int t, i;
	cin >> t;
	for(i = 1;i <= t; i++){
		solve(i);
		if(i < t){
			printf("\n");
		}
	}
	
	return 0;
}
