#include <stdio.h>
#include <string.h>
#include <math.h>

inline
int min(int a, int b){
	return a < b ? a : b;	
}

int numlen(long long x){
	char t[20];
	sprintf(t, "%lld", x);
	return strlen(t);
}

inline
int calc_num_diff(long long a, long long b){
	int cnt = 0;
	while(a != 0 || b != 0){
		if(a % 10 != b % 10){
			cnt += 1;
		}
		a /= 10;
		b /= 10;
	}
	return cnt;
}

void solve(){
	long long a, b, c;
	int la, lb;
	int diff, min_diff;
	
	scanf("%lld %lld", &a, &b);
//	printf("\ncase: %lld %lld\n", a, b);
	la = numlen(a);
	lb = numlen(b);
	if(la < lb){
		printf("-1\n");
		return;	
	}
	
	long long amax = (long long) pow(10, numlen(a));
	
	if(b < 100000){
		int change[100005];
		
		// right
		for(int i=0;i<=b;i+=1){
			change[i] = 2000;
		}
		diff = calc_num_diff(0, b);
		long long imax = 100000 < amax ? 100000 : amax;
		for(long long i=0;i<imax;i+=1){
			diff = calc_num_diff(i, a);
			int m = i % b;
			change[m] = min(change[m], diff);
//			printf("i=%2d change[%d]=%d\n", i, i % b, change[i % b]);
		}
		
		// left
		min_diff = a < 100000 ? change[0] : calc_num_diff(a, b);
		for(long long c=100000;c<amax;c+=1){
			min_diff = min(change[b - (c % b)], min_diff);
		}
		
	}else{
		c = b;
		min_diff = 10;
		while(c < amax){
			diff = calc_num_diff(c, a);
			min_diff = min(min_diff, diff);
			c += b;	
		}
	}
	printf("%d\n", min_diff);
}

int main(void){
	freopen("D.in", "r", stdin);
	int kase, n;
	while(scanf("%d", &kase) != EOF){
		for(int i=0;i<kase;i+=1){
			solve();
		}
	}
	return 0;
}


