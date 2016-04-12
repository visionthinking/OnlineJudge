```C++
#include <math.h>

const int MAX = 1000;
bool prime[MAX];

void fill_prime(const int max){
  int sqrt_max = sqrt(max);
  memset(prime, true, sizeof(prime));
  prime[0] = false;
  prime[1] = false;
  for (int i=2; i <= sqrt_max; i++) {
    if (prime[i]) {
      for (int k=i*i; k < max; k+=i) {
        prime[k] = false;
      }
    }
  }
}
```