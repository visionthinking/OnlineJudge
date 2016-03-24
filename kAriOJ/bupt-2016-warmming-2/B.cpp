#include <stdio.h>
#include <string.h>

const int MAX = 205;

int n;
char a[MAX][MAX];
int width;

void input(){
	scanf("%d", &n);
}

void draw_row(int row, int col, int len, char c){
	for(int i=col; i<col+len; i+=1){
		a[row][i] = c;
	}
}

void draw_col(int col, int row, int len, char c){
	for(int i=row; i<row+len; i+=1){
		a[i][col] = c;
	}
}

void print(){
	int h = (4*n-3) / 2 + 1;
	for(int i=0;i<h;i+=1){
		for (int j = 0; j<width; j+=1){
			printf("%c", a[i][j]);
		}
		printf("\n");
	}
}

void reverse_print(){
	int h = (4*n-3) / 2;
	for(int i=h-1;i>=0;i-=1){
		for (int j = 0;j<width;j+=1){
			printf("%c", a[i][j]);
		}
		printf("\n");
	}
}

void solve(){
	memset(a, 0, sizeof(a));
	
	width = 4*n-3;
	int rows = width/2+1;
	char ci = 'A';
	int w = width;
	for(int i=0;i<rows;i+=1){
		char c;
		if(i & 1){
			c = 'Z';
		}else{
			c = ci;
			ci += 1;
		}
		draw_row(i, i, w, c);
		draw_col(i, i, w/2+1, c);
		draw_col(i+w-1, i, w/2+1, c);
		w -= 2;
	}
	print();
	reverse_print();
}

int main(void){
	freopen("B.in", "r", stdin);
	int kase;
	while(scanf("%d", &kase) != EOF){
		for(int i=0;i<kase;i+=1){
			input();
			solve();
		}
	}
	return 0;
}


