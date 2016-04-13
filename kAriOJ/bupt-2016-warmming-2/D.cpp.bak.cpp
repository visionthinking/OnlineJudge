#include <stdio.h>
#include <string.h>
#include <math.h>

const int MAX = 2001;

int numlen(long long x){
	char t[20];
	sprintf(t, "%lld", x);
	return strlen(t);
}

void num2str(long long x, char * c){
	sprintf(c, "%010lld", x);
	int len = strlen(c);
	for(int i=0;i<len;i+=1){
		c[i] -= '0';
	}
}

inline
int calc_diff(char * a, char * b, int len){
	int cnt = 0;
	for(int i=0;i<len;i+=1){
		if(a[i] != b[i]){
			cnt += 1;
		}
	}
	return cnt;
}

void print(char * x, int len){
	for(int i=0;i<len;i+=1){
		printf("%d", x[i]);
	}
	printf("\n");
}

int update_cs(char * as, char * cs, int p){
	if(p < 0) return 0;
	int delta_diff = 0;
	cs[p] += 1;
	if(cs[p] >= 10){
		cs[p] = 0;
		delta_diff += update_cs(as, cs, p-1);	
	}
	if(cs[p] == as[p]){
		delta_diff -= 1;	
	}else if(cs[p]-1 == as[p]){
		delta_diff += 1;
	}
	return delta_diff;
}

void solve(){
	long long a, b;
	int la, lb;
	char as[20], bs[20];
	
	scanf("%lld %lld", &a, &b);
	la = numlen(a);
	lb = numlen(b);
	if(la < lb){
		printf("-1\n");
		return;	
	}
	
	num2str(a, as);
	num2str(b, bs);
	
	if(b < 100000){
			
	}else{
		char cs[20];
		int diff, change[100005];
		
		num2str((long long) 0, cs);
		print(as, 10);
		print(bs, 10);
		print(cs, 10);
		
		// right side
		printf("right side\n");
		diff = calc_diff(cs+5, as+5, 5);
		printf("diff: %d\n", diff);
		change[0] = diff;
		for(int i=1;i<100000;i+=1){
			diff += update_cs(as+5, cs+5, 4);
			change[i] = diff;
			if(i < 20) {
				printf("change[%d]: %d\n", i, change[i]);
				print(cs, 10);
			}
		}
		
		// left side
		printf("left side\n");
		int min_diff, two_diff, left_num;
		
		num2str((long long) 0, cs);
		min_diff = calc_diff(as, bs, 10);
		left_num = (a / 100000) * 100000;
		
		diff = calc_diff(cs, as, 5);
		printf("left_num: %d\n", left_num);
		printf("min_diff: %d\n", min_diff);
		printf("diff: %d\n", diff);
		int i_max = (int) pow(10.0, la - 5);
		for(int i=1;i<i_max;i+=1){
			diff += update_cs(as, cs, 4);
			two_diff = diff + change[b - (left_num % b)];
			if(two_diff < min_diff){
				min_diff = two_diff;
			}
		}
		printf("%d\n", min_diff);
	}
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


