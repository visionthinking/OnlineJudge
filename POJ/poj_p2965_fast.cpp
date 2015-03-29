#include <stdio.h>
#include <string.h>

#define MAX 65536

//speed up: op(), consider remove hash/unhash, and use bit operator instead
int FLIP[16] = {4383, 8751, 17487, 34959, 4593, 8946, 17652, 35064, 7953, 12066, 20292, 36744, 61713, 61986, 62532, 63624};

inline int hash(char * b){
	int h = 0;
	for(int i=0;i<16;i++){
		if(b[i]){
			h |= (1 << i);
		}
	}
	return h;
}

inline void unhash(char * b, int n){
	for(int i=0;i<16;i++){
		if(n & (1<<i)){
			b[i] = 1;
		}else{
			b[i] = 0;	
		}
	}
}

inline void flip(char & c){ c = 1-c; }

inline void op(char * b, int n){
	int x = n / 4;
	int y = n % 4;
	x *= 4;
	
	flip(b[n]);
	
	flip(b[x+0]);
	flip(b[x+1]);
	flip(b[x+2]);
	flip(b[x+3]);
	
	flip(b[0+y]);
	flip(b[4+y]);
	flip(b[8+y]);
	flip(b[12+y]);
}

inline int op_fast(int hash, int n){
	return hash ^ FLIP[n];
}

void print(char * b){
	for(int i=0;i<4;i++){
		for(int j=0;j<4;j++){
			printf("%d", b[i*4+j]);
		}
		printf("\n");
	}
	printf("\n");
}

struct node {
	int hash;
	int step;
	int parent;
	int pos;
};

void solution(){
	int i;
	char ch;
	char b[16];
	
	while(i<16){
		scanf("%c", &ch);
		if(ch != '\n'){
			b[i] = (ch == '+') ? 1 : 0;
			i += 1;	
		}
	}
	
	/*
	unhash(b, hash(b));
	print(b);
	op(b, 5);
	print(b);
	*/
	
	int start = hash(b);
	int flag[MAX];
	struct node q[MAX];
	int qp, qlen, h;
	
	memset(flag, 0, sizeof(flag));
	memset(q, 0, sizeof(q));
	
	q[0].hash = start;
	q[0].step = 0;
	qlen = 1;
	qp = 0;
	
	while(qp < qlen){
		for(int i=0;i<16;i++){
			h = op_fast(q[qp].hash, i);
			
			if(flag[h] == 0){
				flag[h] = 1;
				q[qlen].hash = h;
				q[qlen].parent = qp;
				q[qlen].step = q[qp].step + 1;
				q[qlen].pos = i;
				qlen += 1;
			}
			
			if(h == 0){
				//Found
				printf("%d\n", q[qp].step + 1);
				int n = qlen-1;
				while(n != 0){
					int x = q[n].pos / 4;
					int y = q[n].pos % 4;
					printf("%d %d\n", x+1, y+1);
					n = q[n].parent;
				}
				return;
			}
		}
		qp += 1;
	}
}

int main(void){
	freopen("p2965.in", "r", stdin);
	
	/*
	for(int i=0;i<16;i++){
		char a[16];
		memset(a, 0, sizeof(a));
		op(a, i);
		printf("%d,\n", hash(a));
	}
	*/
	solution();
	return 0;
}
