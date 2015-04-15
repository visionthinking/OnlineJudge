#include <stdio.h>
#include <string.h>
#include <algorithm>

#define MAX 100000

inline int max(int a, int b) { return a>b?a:b; }

struct node {
	int next[28];
	int leaf;
	int id;	
};

struct node q[MAX];
int len = 1;

int result[MAX];
int res_len = 0;

int alloc(){
	memset(&q[len], 0, sizeof(struct node));
	q[len].id = -1;
	len += 1;
	return len-1;
}

void insert_result(int n){
	for(int i=0;i<res_len;i++){
		if(result[i] == n){
			return;
		}
	}
	result[res_len] = n;
	res_len += 1;
}

void print_result(){
	if(res_len == 0){
		printf("Not match\n");
	}else{
		std::sort(result, result+res_len);
		for(int i=0;i<res_len;i++){
			printf("%d ", result[i]);
		}
		printf("\n");
	}
	res_len = 0;
}

void insert(char * str, int id){
	int p = 0;
	for(int i=0;str[i];i++){
		char k;
		if(str[i] == '*'){
			k = 27;
		}else if(str[i] == '?'){
			k = 26;
		}else{
			k = str[i] - 'a';	
		}
		if(q[p].next[k] == 0){
			q[p].next[k] = alloc();
		}
		p = q[p].next[k];
	}
	q[p].id = id;
	//printf("id=%d\n", id);
	q[p].leaf = 1;
}

void find(int p, char * str, int len, char x){
	//printf("%d,%s,%d,%d\n", p, str, len, x);
	if(q[p].leaf && len == 0){
		//printf("%d ", q[p].id);
		insert_result(q[p].id);
		return;	
	}
	if(q[p].leaf && x == 27){
		//printf("%d ", q[p].id);
		insert_result(q[p].id);
		return;	
	}
	/*if(q[p].leaf){
		if(x == 27){
			printf("%d ", q[p].id);
		}else if(len == 1){
			if(x == 26 || (x<26 && x == str[0] - 'a')){
				printf("%d ", q[p].id);
			}
		}
		return;
	}*/
	char k;
	k = str[0] - 'a';
	if(q[p].next[k] != 0){
		find(q[p].next[k], str+1, len-1, k);
	}
	if(q[p].next[26] != 0){
		find(q[p].next[26], str+1, len-1, 26);
	}
	if(q[p].next[27] != 0){
		for(int i=0;i<len;i++){
			find(q[p].next[27], str+i, len-i, 27);
		}
	}
}

void debug(int n){
	if(q[n].leaf) return;
	int i;
	for(i=0;i<28;i++){
		if(q[n].next[i]){
			printf("%d\t%c\t%d\tleaf:%d\n", q[n].next[i], (i<26)? i+'a':((i==26)?'?':'*'), q[q[n].next[i]].id, q[q[n].next[i]].leaf);
			debug(q[n].next[i]);
		}
	}
}

void solution(int n, int m){
	char str[25];
	int i;
	memset(&q[0], 0, sizeof(struct node));
	len = 1;
	//printf("INSERT:\n");
	for(i=0;i<n;i++){
		scanf("%s", str);
		//printf("%d: %s\n", i, str);
		insert(str, i);
	}
	//debug(0);
	//printf("\nFIND:\n");
	for(i=0;i<m;i++){
		scanf("%s", str);
		//printf("%s\n", str);
		res_len = 0;
		find(0, str, strlen(str), -1);
		print_result();
		//printf("\n");
	}
}

int main(void){
	freopen("p1816.in", "r", stdin);
	int n,m;
	while(scanf("%d %d", &n, &m) != EOF){
		solution(n, m);
	}
	return 0;
}

