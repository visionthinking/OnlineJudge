#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <cmath>

using namespace std;
 
const int MAX = 100005;
int n;
long long a[10], b[10];

long long gcd(long long a, long long b){
	if (a < b) swap(a, b);
	return b == 0 ? a : gcd(b, a % b); 
}

long long ngcd(long long *a, long long n) {
//	return (n == 1) ? a[0] : gcd(a[n-1], ngcd(a, n-1));
	if(n == 1) return a[0];
	long long r = gcd(a[0], a[1]);
	for(int i=2;i<n;i+=1){
		r = gcd(r, a[i]);
	}
	return r;
}

long long lcm(long long a, long long b) {
	return a * b / gcd(a, b);
}

long long nlcm(long long *a, long long n) {
//	return (n == 1) ? a[0] : lcm(a[n-1], nlcm(a, n-1));
	if(n == 1) return a[0];
	long long r = lcm(a[0], a[1]);
	for(int i=2;i<n;i+=1){
		r = lcm(r, a[i]);
	}
	return r;
}

void input(){
    for(int i=0;i<n;i+=1){
    	scanf("%lld %lld", &a[i], &b[i]);
    }
}

void solve(){
   	long long x1 = nlcm(a, n);
   	long long x2 = ngcd(b, n);
   	printf("%lld %lld\n", x1, x2);
}
 
int main(void){
    freopen("G.in", "r", stdin);
	
    while(scanf("%d", &n) != EOF){
        input();
        solve();
    }
    return 0;
}
