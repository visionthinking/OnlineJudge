#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())
#define MOD 1000000007ll

using namespace std;

typedef long long ll;

ll pw(ll a, ll b, ll md) {
    ll r = 1 % md;
    while (b) {
        if (b&1) r = r*a % md;
        a = a*a % md;
        b /= 2;
    }
    return r;
}

ll n;
int k, a, b;
ll ca[100005], cb[100005];

int main() {
    int t; scanf("%d", &t);
    FO(z,0,t) {
        scanf("%d %d %lld %d", &a, &b, &n, &k);
        FO(i,0,k) ca[i] = cb[i] = 0;
        ll res = 0;
        FO(i,1,k+1) if (i <= n) {
            ll v1 = pw(i, a, k);
            ll r = (n-i)/k + 1;
            ca[v1] = (ca[v1] + r) % MOD;

            ll v2 = pw(i, b, k);
            r = (n-i)/k + 1;
            cb[v2] = (cb[v2] + r) % MOD;

            if ((v1+v2)%k == 0) {
                res = ((res - r) % MOD + MOD) % MOD;
            }
        }
        FO(i,0,k) res = (res + ca[i] * cb[(k-i)%k]) % MOD;
        printf("Case #%d: %lld\n", z+1, res);
        fflush(stdout);
    }
}

