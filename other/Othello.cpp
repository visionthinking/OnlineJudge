#include <stdio.h>
#include <string.h>
#include <string>
#include <unordered_map>
#include <map>
#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>

using namespace std;

const int N = 8;
char a[10][10];
int D[8][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}, 
			   {1, 1}, {-1, -1}, {1, -1}, {-1, 1}};


void print() {
	for(int i=0; i<N; i+=1) {
		printf("%s\n", a[i]);
	}
	printf("\n");
}

void count_res() {
	int B = 0, W = 0;
	for(int i=0; i<N; i+=1) {
		for(int j=0; j<N; j+=1) {
			if(a[i][j] == '*') {
				B += 1;
			} else if(a[i][j] == 'o') {
				W += 1;
			}
		}
	}
	printf("%d %d\n", B, W);
}

inline 
bool inside(int tr, int tc) {
	return tr >= 0 && tc >= 0 && tr < N && tc < N;
}

void solve(int kase){
	for(int i=0; i<N; i+=1) {
		scanf("%s\n", a[i]);
	}
	int S, r, c, t;
	vector<pair<int, int>> rev;
	scanf("%d", &S);
	while(S--) {
		scanf("%d%d%d\n", &r, &c, &t);
		char x = (t == 0 ? '*' : 'o');
		int cnt = 0;
		for(int i=0; i<8; i+=1) {
			rev.clear();
			int tr = D[i][0] + r, tc = D[i][1] + c;
			while(inside(tr, tc)) {
				if(a[tr][tc] == x) break;
				if(a[tr][tc] == '.') {
					rev.clear(); break;	
				}
				rev.push_back({tr, tc});
				tr += D[i][0]; tc += D[i][1];
			}
			if(!inside(tr, tc)) rev.clear();
			for(auto& pos : rev) {
				a[pos.first][pos.second] = x;
			}
			cnt += rev.size();
		}
		if(cnt > 0) {
			a[r][c] = x;
		}
//		print();
	}
	count_res();
}

int main(int argc, char *argv[]){
	if(argc >= 2) {
		freopen(argv[1], "r", stdin);
	}else{
		freopen("Othello.in", "r", stdin);	
	}
	int kase;
	scanf("%d\n", &kase);
	for(int i=1; i<=kase; i+=1){
		solve(i);	
	}
	return 0;
}
