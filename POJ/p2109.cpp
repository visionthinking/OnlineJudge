#include <stdio.h>
#include <string.h>

const int MAX = 205;

struct num {
	char n[MAX];
	int len;	
};

void print(struct num & a){
	for(int i=a.len -1 ;i >=0; i--){
		printf("%d", a.n[i]);
	}
	printf("\n");
}

void reverse(num & a){
	for(int i = 0;i<a.len/2;i++){
		char t = a.n[i];
		a.n[i] = a.n[a.len-1-i];
		a.n[a.len-1-i] = t;
	}
}

void read(struct num & a){
	memset(a.n,0,sizeof(char)*MAX);
	int len = 0;
	char c;
	do{
		if(scanf("%c", &c) == EOF || c=='\n'){
			a.len = len;
			reverse(a);
			break;
		}else if(c == ' ') {
			continue;	
		}
		a.n[len++] = c - '0';
	}while(1);
}

int cmp(struct num *a,struct num *b){
	int len = a->len > b->len ? a->len : b->len;
	for(int i=0;i<len;i++){
		if(a->n[i] != b->n[i]) return a->n[i] - b->n[i];
	}
	return 0;
}

void add(struct num & a, struct num & b){
	int c=0;
	int d=0;
	int len = a.len > b.len ? a.len:b.len;
	struct num res;
	for(int i=0;i<len;i++){
		res.n[i] = (a.n[i] + b.n[i] + c) % 10;
		c = (a.n[i] + b.n[i] + c) /10;
	}
	if(c >0) res.n[len++] = c;
	memcpy(a.n,res.n,sizeof(char)*MAX);
	a.len = len;
}

void mul(struct num * a, struct num * b, struct num * res){
	if(a->len > b->len){
		struct num * temp = a;
		a = b;
		b = temp;
	}
	res->len = 0;
	memset(res->n,0,sizeof(char)*MAX);
	for(int i=0;i<a->len;i++){
		int c = 0;
		struct num s;
		memset(s.n,0,sizeof(char)*MAX);
		s.len = i;
		for(int j=0;j<b->len;j++){
			s.n[j+i] = (a->n[i] * b->n[j] + c) %10;
			c = (a->n[i] * b->n[j] + c) /10;
			s.len ++;
		}
		if(c>0) s.n[s.len++] = c;
		add(*res,s);
	}
}

void solution(int n){
	struct num p;
	printf("%d\n", n);
	read(p);
	
	print(p);
	struct num c;
	mul(&p,&p,&c);
	print(c);
	
	for(int i=0;i<n;i++){
		
	}
}

int main(void){
	freopen("p2109.in", "r", stdin);
	int n;
	while(scanf("%d", &n) != EOF){
		solution(n);
	}
	return 0;
}
