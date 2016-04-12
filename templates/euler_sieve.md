### Euler Sieve

```C++
const int MAX = 10000000;
int m[MAX], euler[MAX], prime[MAX], prime_len;
/* m[i] is `i`'s min-prime-divisor */

void fill_euler(){
    memset(m, 0, sizeof(m));
    euler[1] = 1;
    int k;
    for(int i=2;i<MAX;i++) {
        if(m[i] == 0) {
            prime[prime_len++] = m[i] = i;
            euler[i] = i-1;
        }
        for(int j = 0; j < prime_len && (k = prime[j]*i) < MAX; j++) {
            m[k] = prime[j];
            if(m[i] == prime[j]) {
                euler[k] = euler[i] * prime[j];
                break;
            } else {
                euler[k] = euler[i] * (prime[j]-1);
            }
        }
    }
}
```