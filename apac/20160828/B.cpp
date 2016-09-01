#include <stdio.h>
#include <string.h>
#include <string>
#include <unordered_map>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define MOD 1000000007L
#define LL long long

LL fast_pow(LL x, LL y, LL k) {
	LL r = 1; x %= k;
	while(y) {
		if(y & 1) r = r * x % k;
		x = x * x % k;
		y >>= 1;
	}
	return r % k;
}

void solve(int kase){
	LL res = 0, a, b, n, k;
	scanf("%lld %lld %lld %lld", &a, &b, &n, &k);
	for(LL i=1; i<=n; i+=1) {
		for(LL j=1; j<=n; j+=1) {
			if(i != j) {
				if((fast_pow(i, a, k) + fast_pow(j, b, k)) % k == 0) {
					res = (res + 1) % MOD;
				}
			}
		}
	}
	printf("Case #%d: %lld\n", kase, res);
}

int main(int argc, char *argv[]){
	if(argc >= 2) {
		freopen(argv[1], "r", stdin);
	}else{
		freopen("B.in", "r", stdin);	
	}
	int kase;
	scanf("%d\n", &kase);
	for(int i=1; i<=kase; i+=1){
		solve(i);	
	}
	return 0;
}

