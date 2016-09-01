#include <stdio.h>
#include <string.h>
#include <string>
#include <unordered_map>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define MOD 1000000007
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

LL acnt[100005], bcnt[100005];

void solve(int kase){
	LL res = 0, a, b, n, k, pa, pb, drop = 0;
	memset(acnt, 0, sizeof(acnt));
	memset(bcnt, 0, sizeof(bcnt));
	
	scanf("%lld %lld %lld %lld", &a, &b, &n, &k);
	for(LL i=1; i<=k; i+=1) {
		if(i <= n) {
			LL cnt = (n-i)/k + 1;
			pa = fast_pow(i, a, k);
			pb = fast_pow(i, b, k);
			acnt[pa] = (acnt[pa] + cnt) % MOD;
			bcnt[pb] = (bcnt[pb] + cnt) % MOD;
			
			if((pa + pb) % k == 0) {
				drop = (drop + cnt) % MOD;
			}
		}
	}
	for(LL i=0; i<k; i+=1) {
		res = (res + acnt[i] * bcnt[(k-i)%k] % MOD) % MOD;
	}
	res = (res - drop + MOD) % MOD;
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

