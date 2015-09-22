#include <stdio.h>
#include <string.h>

#define MAX 205

char a[MAX][MAX];
int lines, nodes;

void eatline(){
	char c;
	do{
		scanf("%c", &c);
	}while(c != '\n');
}

inline 
bool is_node(int x, int y){
	char c = a[x][y];
	return c != ' ' && c != '|' && c != '-' && c > 0;
}

void f(int x, int y){
	if(is_node(x, y)){
		printf("%c(", a[x][y]);
		if(a[x+1][y] == '|'){
			int p = y;
			while( a[x+2][p-1] == '-') {
				p -= 1;
			}
			for(int i=p;a[x+2][i]=='-';i++){
				if(is_node(x+3, i)){
					f(x+3, i);	
				}
			}
		}
		printf(")");	
	}
}

void solve(){
	memset(a, 0, sizeof(a));
	int i = 0, j = 0;
	nodes = 0;
	while(1){
		char c;
		scanf("%c", &c);
		if(c == '\n'){
			i += 1;	
			j = 0;
		}else if(c == '#'){
			eatline();
			lines = i;
			break;
		}else{
			a[i][j] = c;
			if(is_node(i, j)){
				nodes += 1;	
			}
			j += 1;
		}
	}
	i = 0;
	while(i < lines){
		j = 0;
		while(a[i][j] && !is_node(i, j)){
			j += 1;
		}
		if(is_node(i, j)){
			break;	
		}
		i += 1;
	}
	//printf("(%d, %d, %d)\n", i, j, a[i][j]);
	printf("(");
	if(nodes > 0){
		f(i, j);
	}
	printf(")\n");
}

int main(void){
	freopen("uva10562.in", "r", stdin);
	int n;
	scanf("%d", &n);
	eatline();
	for(int i=0;i<n;i++){
		solve();	
	}
	return 0;
}


