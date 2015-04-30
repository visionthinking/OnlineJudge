#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>
#include <deque>
#include <queue>
using namespace std;

const int MAX = 1024;
const int MAX_LINE = 1024;

struct program {
	int id;
	char s[50][MAX_LINE];
	int run;
	int lines;	
};

int n, m;
struct program prg[MAX];
int t[5];
deque<struct program *> dq;

int v[26];

void read(){
	dq.clear();
	
	memset(v, 0, sizeof(v));
	
	scanf("%d", &n);
	for(int i=0;i<5;i++){
		scanf("%d", &t[i]);
	}
	scanf("%d\n", &m);
	
	int i, j;
	bool flag = false;
	for(i=0;i<n;i++){
		j = 0;
		while(fgets(prg[i].s[j], MAX_LINE, stdin)){
			int len = strlen(prg[i].s[j]);
			if(prg[i].s[j][len-1] == '\n'){
				prg[i].s[j][len-1] = 0;
				len -= 1;
			}
			if(len > 0){
				j += 1;
				if(prg[i].s[j-1][2] == 'd'){
					break;
				}
			}
		}
		prg[i].id = i+1;
		prg[i].lines = j;
		prg[i].run = 0;
		//printf("%d line=%d\n", prg[i].id, j);
		dq.push_back(&prg[i]);
	}
}
	
void solve(int solve_id){
	read();
	int M, run;
	bool lock = false;
	bool putback;
	char op;
	queue<struct program *> q;
	while(!dq.empty()){
		struct program * top = dq.front();
		dq.pop_front();
		M = m;
		putback = true;
		while(M > 0){
			run = top->run;
			top->run += 1;
			op = top->s[run][2];
			if(op == '='){
				M -= t[0];
				int value;
				sscanf(top->s[run] + 4, "%d", &value);
				v[top->s[run][0] - 'a'] = value;
			}else if(op == 'i'){
				M -= t[1];
				printf("%d: %d\n", top->id, v[top->s[run][6] - 'a']);
			}else if(op == 'c'){
				M -= t[2];
				if(lock){
					top->run -= 1;
					q.push(top);
					putback = false;
					break;
				}else{
					lock = true;
				}
			}else if(op == 'l'){
				M -= t[3];
				lock = false;
				if(!q.empty()){
					dq.push_front(q.front());
					q.pop();
				}
			}else if(op == 'd'){
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
	freopen("uva210.in", "r", stdin);
	int t, i;
	scanf("%d", &t);
	for(i = 1;i <= t; i++){
		solve(i);
		if(i < t){
			printf("\n");
		}
	}
	
	return 0;
}
