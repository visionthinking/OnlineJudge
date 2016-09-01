#include <stdio.h>
#include <string.h>
#include <string>
#include <set>

using namespace std;

#define MAX_LINE 100

int n;
char curr[MAX_LINE];
char top[MAX_LINE];

int readline(char * a){
	fgets(a, MAX_LINE, stdin);
	int len = strlen(a);
	if(a[len-1] == '\n'){
		a[len-1] = 0;
		len -= 1;
	}
	return len;
}

void solve(int kase){
	scanf("%d\n", &n);
	int topn = 0;
	for(int i=0; i<n; i+=1){
		int len = readline(curr);
		set<char> cs;
		for(int j=0; j<len; j+=1){
			if(curr[j] >= 'A' && curr[j] <= 'Z'){
				cs.insert(curr[j]);
			}
		}
		int size = cs.size();
		if(size > topn){
			topn = size;
			strcpy(top, curr);
		}else if(size == topn){
			if(strcmp(top, curr) > 0){
				topn = size;
				strcpy(top, curr);
			}
		}
		// printf("%s\n", curr);
	}
	printf("Case #%d: %s\n", kase, top);
}

int main(void){
	freopen("A-large-practice.in", "r", stdin);
	int kase;
	scanf("%d\n", &kase);
	for(int i=1; i<=kase; i+=1){
		solve(i);	
	}
	return 0;
}
