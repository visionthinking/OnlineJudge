#include <stdio.h>
#include <string.h>
#include <string>
#include <iostream>
using namespace std;

const int MAX = 101000;
char a[MAX];
int p[MAX];
int len;
int ptail;

void solve(int case_id, const string & line){
	char c;
	int plast = 0;
	len = 1;
	p[0] = -1;
	ptail = 0;
	int line_size = line.size();
	for(int i=0;i<line_size;i++){
		c = line[i];
		if(c == '\n'){
			break;	
		}
		if(c == '['){
			plast = 0;
		}else if(c == ']'){
			plast = ptail;
		}else{
			a[len] = c;
			p[len] = p[plast];
			p[plast] = len;
			if(plast == ptail) ptail = len;
			plast = len;
			len += 1;
		}
	}
	
	for(int i=p[0];i!=-1;i=p[i]){
		printf("%c", a[i]);	
	}
	printf("\n");
}

int main(void){
	freopen("uva11988.in", "r", stdin);
	ios::sync_with_stdio(false);
	int case_id = 0;
	string line;
	while(getline(cin, line)){
		if(line.length() > 0){
			solve(case_id, line);	
			case_id += 1;
		}
	}
	return 0;
}


