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
	
	memset(prg, 0, sizeof(prg));
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
		while(1){
			fgets(prg[i].s[j], MAX_LINE, stdin);
			int len = strlen(prg[i].s[j]);
			prg[i].s[j][len-1] = 0;
			//printf("%s len=%d\n", prg[i].s[j], len);
			j += 1;
			if(memcmp("end", prg[i].s[j-1], 3) == 0){
				break;
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
			op = 
			if(top->s[run][2] == '='){
				M -= t[0];
				int value;
				sscanf(top->s[run] + 4, "%d", &value);
				v[top->s[run][0] - 'a'] = value;
			}else if(memcmp("print", top->s[run], 5)==0){
				M -= t[1];
				printf("%d: %d\n", top->id, v[top->s[run][6] - 'a']);
			}else if(memcmp("lock", top->s[run], 4)==0){
				M -= t[2];
				if(lock){
					top->run -= 1;
					q.push(top);
					putback = false;
					break;
				}else{
					lock = true;
				}
			}else if(memcmp("unlock", top->s[run], 6)==0){
				M -= t[3];
				lock = false;
				if(!q.empty()){
					dq.push_front(q.front());
					q.pop();
				}
			}else if(memcmp("end", top->s[run], 3)==0){
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
	while(scanf("%d", &t) != EOF){
		for(i = 1;i <= t; i++){
			solve(i);
			printf("\n");
		}
	}
	return 0;
}
