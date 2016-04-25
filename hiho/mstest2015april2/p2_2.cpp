#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

const int MAX = 1000;
char a[MAX], b[MAX];
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
//	printf("Case: %s\n", a);
	len = strlen(a);
	strcpy(b, a);
	for(int i=0; i<len; i+=1){
		b[i] -= '0';
	}	
}

char s[MAX];
void solve(){
	if(len == 1) {
		print(b, len);
		return;
	}
	
	int p = 1;
	s[0] = b[0];
	s[1] = b[1];
	bool back = false;
	while(p >= 0 && p < len){
//		print(s, p+1);
		if(p == 0){
			p += 1;
			s[p] = 9;
		}
		if(num[s[p-1]][s[p]]){
			p += 1;
			if(back){
				s[p] = 9;
			}else{
				s[p] = b[p];
			}
		}else{
			char next = find(s[p-1], s[p]-1);
			if(next == -1){
				p -= 1;
				s[p] -= 1;
			}else{
				s[p] = next;	
			}
			back = true;
		}
	}
	print(s, len);
}

int main(void){
	freopen("p2.in", "r", stdin);
	int kase;
	while(scanf("%d\n", &kase) != EOF){
		for(int i=1; i <= kase; i+=1){
			input();
			solve();
		}
	}
	return 0;
}
