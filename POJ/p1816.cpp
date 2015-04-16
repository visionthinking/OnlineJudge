#include <stdio.h>
#include <string.h>
#include <algorithm>

const int MAX = 100000;

struct node {
	int next[28];
	int leaf;
	int id;	
};

struct node q[MAX];
int len = 1;

int result[MAX];
int res_len = 0;

int union_set[MAX];

//模拟malloc 
int alloc(){
	memset(&q[len], 0, sizeof(struct node));
	q[len].id = -1;
	len += 1;
	return len-1;
}

//插入一个结果，对结果去重 
void insert_result(int n){
	for(int i=0;i<res_len;i++){
		if(result[i] == n){
			return;
		}
	}
	result[res_len] = n;
	res_len += 1;
}

//输出结果 
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

//建立字典树 
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
		q[p].leaf = 0;
		p = q[p].next[k];
	}
	q[p].leaf = 1;
	union_set[id] = q[p].id;
	q[p].id = id;
}

//把同一个集合里的加入到结果中 
void union_insert(int i){
	while(i != -1){
		insert_result(i);
		i = union_set[i];
	}
}

void find(int p, char * str, int len, char x){
	//printf("%d,%s,%d,%d\n", p, str, len, x); 	
	
	// 同时被消耗完
	if(q[p].id != -1 && len == 0){
		union_insert(q[p].id);
	}
	
	if(len > 0){
		char k = str[0] - 'a';
		if(q[p].next[k] != 0){
			find(q[p].next[k], str+1, len-1, k);
		}
		if(q[p].next[26] != 0){
			find(q[p].next[26], str+1, len-1, 26);
		}
	}
	if(q[p].next[27] != 0){
		for(int i=0;i<=len;i++){
			find(q[p].next[27], str+i, len-i, 27);
		}
	}
}

void debug(int n){
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
	memset(union_set, -1, sizeof(union_set));
	len = 1;
	
	for(i=0;i<n;i++){
		scanf("%s", str);
		insert(str, i);
	}
	
	for(i=0;i<m;i++){
		scanf("%s", str);
		res_len = 0;
		find(0, str, strlen(str), -1);
		print_result();
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

