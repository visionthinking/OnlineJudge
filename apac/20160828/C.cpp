#include <stdio.h>
#include <string.h>
#include <string>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>

typedef long long LL;
using namespace std;

LL x[500005], y[500005];

struct point {
	LL pos;
	int id;
	int start;
	
	void set(LL _pos, int _id, int _start) {
		pos = _pos;
		id = _id;
		start = _start;	
	}
};

inline
bool point_cmp(const struct point & p1, const struct point & p2) {
	if(p1.pos == p2.pos) return p1.start < p2.start;
	return p1.pos < p2.pos;
}

point a[1000010];
int len;

void solve(int kase){
	LL N, L1, R1, A, B, C1, C2, M;
	scanf("%lld %lld %lld %lld %lld %lld %lld %lld", &N, &L1, &R1, &A, &B, &C1, &C2, &M);
	len = 0;
	x[1] = L1, y[1] = R1;
	for(int i = 2; i<=N; i+=1) {
		x[i] = (A * x[i-1] % M + B * y[i-1] % M + C1 % M) % M;
		y[i] = (A * y[i-1] % M + B * x[i-1] % M + C2 % M) % M;
		
	}
	for(int i = 1; i<=N; i+=1) {
		if(x[i] > y[i]) swap(x[i], y[i]);
		a[len++].set(x[i], i, 1);
		a[len++].set(y[i]+1, i, 0);
	}
	sort(a, a + len, point_cmp);
	
	// calculate sum of non-zero area
	LL sum = 0, last = a[0].pos, line = 0;
	for(int i=0; i<len; i+=1) {
		// printf("%lld:%c ", a[i].pos, a[i].start ? 'T' : 'F');
		if(a[i].start) {
			line += 1;
			if(line == 1) last = a[i].pos;
		} else {
			if(line == 1) sum += a[i].pos - last;
			line -= 1;
		}
	}
	// printf("\n");
	
	LL drop = 0, last_pos;
	map<int, LL> one;
	for(int i=0; i<len;) {
		LL pos = a[i].pos;
		if(one.size() == 1) {
			LL t = one.begin()->second += pos - last_pos;
			drop = max(drop, t);
		}
		while(a[i].pos == pos) {
			if(a[i].start) {
				one[a[i].id] = 0;
			} else {
				one.erase(a[i].id);
			}
			i += 1;
		}	
		if(one.size() == 1) {
			last_pos = pos;
		}
	}
	
	printf("Case #%d: %lld\n", kase, sum - drop);
}

int main(int argc, char *argv[]){
	if(argc >= 2) {
		freopen(argv[1], "r", stdin);
	}else{
		freopen("C.in", "r", stdin);
	}
	int kase;
	scanf("%d\n", &kase);
	for(int i=1; i<=kase; i+=1){
		solve(i);	
	}
	return 0;
}


