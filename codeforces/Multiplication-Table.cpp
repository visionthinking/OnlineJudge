/* http://codeforces.com/contest/448/problem/D */

#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

long long n, m, k;

bool is_valid(long long v){
	long long cnt = 0;
	for(long long i=1; i<=n; i+=1){
		cnt += min(v/i, m);
	}
	return cnt >= k;
}

void solve(){
	long long l = 1, r = n*m;
	while(l < r){
		long long mid = l + (r - l)/2;
		if(is_valid(mid)){
			r = mid;
		}else{
			l = mid + 1;
		}
	}
	printf("%I64d\n", l);
}

int main(void){
	freopen("Multiplication-Table.in", "r", stdin);
	
	while(scanf("%I64d %I64d %I64d", &n, &m, &k) != EOF){
		solve();
	}
	return 0;
}
