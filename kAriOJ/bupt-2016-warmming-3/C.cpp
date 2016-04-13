#include <stdio.h>
#include <string.h>
#include <math.h>
#include <algorithm>
#include <map>
using namespace std;

const int MAX = 100000001;
const int MOD = 23333;
const int SQMAX = 20000;
int k, n;

int gcds[SQMAX];
int gcds_len;
map< long long, long long > euler_values;

long long euler(long long n) {
	long long ans = n;
    for(long long i=2;i*i<=n;i+=1) {
        if(n % i == 0) {
            ans -= ans / i;
            while(n % i == 0) n /= i;
        }
    }
    if(n > 1) ans -= ans / n;
    return ans;
}

long long euler_slow(long long n) {
    long long s=n,i,m;
    m=sqrt(n);
    for(i=2;i<=m;i++){
        if(n%i==0)
            s=s/i*(i-1);
        while(n%i==0)
            n/=i;
    }
    if(n>1)
        s=s/n*(n-1);
    return s;
}

void fill_gcds(int n){
	int sq = (int) sqrt(n);
	gcds_len = 0;
	for(int i=1; i<=sq; i+=1){
		if(n % i == 0){
			gcds[gcds_len++] = i;
		}
	}
}

long long fast(int m){
	long long a = k % MOD;
	long long r = 1;
	while(m){
		if(m & 1){
			m -= 1;
			r = (r * a) % MOD;	
		}
		m >>= 1;
		a = (a * a) % MOD;
	}
	return r % MOD;
}

void solve(){
	scanf("%d %d", &k, &n);
		
	long long sum = 0;
	fill_gcds(n);
	for(int i=0; i<gcds_len; i+=1){
		int gcd = gcds[i];
		sum = (sum + euler(n / gcd) * fast(gcd)) % MOD;
		if(gcd * gcd != n){
			sum = (sum + euler(gcd) * fast(n / gcd)) % MOD;
		}
	}
	printf("%lld\n", sum);
}

int main(void){
	freopen("C.in", "r", stdin);
	int kase;
	scanf("%d", &kase);
	for(int i=1;i<=kase;i+=1){
		solve();
	}
	return 0;
}



