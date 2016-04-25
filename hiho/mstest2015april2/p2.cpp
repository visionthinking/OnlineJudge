#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;


const int MAX = 1000;
char a[MAX];
int len;
int num[10][10] = {
//   0  1  2  3  4  5  6  7  8  9
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0}, 
	{1, 1, 1, 1, 1, 1, 1, 1, 1, 1}, 
	{1, 0, 1, 1, 0, 1, 1, 0, 1, 1}, 
	{0, 0, 0, 1, 0, 0, 1, 0, 0, 1}, 
	{1, 0, 0, 0, 1, 1, 1, 1, 1, 1},
	{1, 0, 0, 0, 0, 1, 1, 0, 1, 1},
	{0, 0, 0, 0, 0, 0, 1, 0, 0, 1}, 
	{1, 0, 0, 0, 0, 0, 0, 1, 1, 1}, 
	{1, 0, 0, 0, 0, 0, 0, 0, 1, 1}, 
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 1}
};

/*
1 2 3
4 5 6
7 8 9
  0
  
*/

void print(char * a, int len){
	for(int i=0; i<len; i+=1){
		printf("%d", a[i]);
	}
	printf("\n");
}

char find(char c, char to){
	for(char i=to; i>=0; i-=1){
		if(num[c][i]){
			return i;
		}
	}
	return -1;
}

void input(){
	scanf("%s", a);
	len = strlen(a);
	for(int i=0; i<len; i+=1){
		a[i] -= '0';
	}	
}

void solve(){
	int i = 0, fill = len, fill_num = 9;
	for(; i<len-1; i+=1){
		if(num[a[i]][a[i+1]] == 0){
			break;
		}
	}
	
	if(i+1 >= len || len == 1){
		print(a, len);
		return;	
	}
	
	char next = find(a[i], a[i+1]);
	if(next != -1){
		a[i+1] = next;
		if(next == 0) fill_num = 0;
		fill = i+2;
	}else{
		if(a[i] == 9){
			int j = i;
			while(j >= 0 && a[j] == 9){
				j -= 1;
			}
			if(j == -1){
				a[0] -= 1;
				fill = 1;
			}else{
				a[j+1] = find(a[j], a[j+1]-1);
				if(a[j+1] == 0) fill_num = 0;
				fill = j+2;
			}
		}else{
			if(i == 0){
				a[i] -= 1; 
			}else{
				a[i] = find(a[i-1], a[i] - 1);
			}
			if(a[i] == 0) fill_num = 0;
			fill = i+1;	
		}
	}
	
	for(int i=0; i<fill && i<len; i+=1){
		printf("%d", a[i]);
	}
	for(int i=fill; i<len; i+=1){
		printf("%d", fill_num);
	}
	printf("\n");
}

int main(void){
	freopen("p2.in", "r", stdin);
	int kase;
	while(scanf("%d", &kase) != EOF){
		for(int i=1; i <= kase; i+=1){
			input();
			solve();
		}
	}
	return 0;
}
