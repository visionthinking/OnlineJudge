#include <iostream>
#include <stdio.h>
#include <string.h>
#include <string>

using namespace std;

struct matrix {
	int h, w;
};

const int MAX = 26;
const int STACK_MAX = 100000;
struct matrix a[MAX];
int def[MAX];

struct matrix s[STACK_MAX];
int slen;

void calc(const string & line){
	slen = 0;
	int len = line.length();
	long long an = 0;
	
	for(int i=0;i<len;i++){
		if(line[i] == '('){
				
		}else if(line[i] == ')'){
			const struct matrix &m2 = s[--slen];
			const struct matrix &m1 = s[--slen];
			//printf("m1 = (%d,%d) m2 = (%d,%d)\n", m1.h, m1.w, m2.h, m2.w);
			if(m1.w == m2.h){
				an += m1.h * m2.w * m1.w;
				s[slen].h = m1.h;
				s[slen].w = m2.w;
				slen += 1;
			}else{
				printf("error\n");
				return;	
			}
		}else if(line[i] >= 'A' && line[i] <= 'Z'){
			if(def[line[i]-'A']){
				s[slen].w = a[line[i]-'A'].w;
				s[slen].h = a[line[i]-'A'].h;
				slen += 1;
			}else{
				printf("error\n");
				return;	
			}
		}
	}
	printf("%lld\n", an);
}

void solve(){
	memset(def, 0, sizeof(def));
	int n, i;
	char c;
	cin >> n;
	for(i=0;i<n;i++){
		cin >> c;
		cin >> a[c - 'A'].h >> a[c - 'A'].w;
		cin.get();
		def[c - 'A'] = 1;
	}
	
	string line;
	while(getline(cin, line)){
		calc(line);
	}
}

int main(void){
	freopen("uva442.in", "r", stdin);
	ios::sync_with_stdio(false);
	
	solve();
	
	return 0;
}

