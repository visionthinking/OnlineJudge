#include <string.h>
#include <math.h>
#include <stdio.h>

const int MAX = 100005;
const int BIG_ENOUGH = MAX * 2;
char a[MAX];
int c[10];
int len;

int input(){
	if(scanf("%s", a) == EOF){
		return 0;	
	}
	len = strlen(a);
//	printf("%s  len=%d\n", a, len);
	for(int i=0;i<10;i+=1){
		if(scanf("%d", &c[i]) == EOF){
			return 0;	
		}
	}
	for(int i=0;i<len;i+=1){
		a[i] = a[i] - '0';
	}
	return 1;
}

void solve(){
	int cnt[10];
	int p1 = 0, p2 = -1;
	int enough_cnt = 0;
	memset(cnt, 0, sizeof(cnt));
	
	for(int i=0;i<10;i+=1){
		if(cnt[i] == c[i]){
			enough_cnt += 1;
		}
	}
//	printf("enough_cnt=%d\n", enough_cnt);
	int min = BIG_ENOUGH;
	while(p1 < len && p2 < len){
		char t;
		while(enough_cnt < 10 && p2 < len){
			p2 += 1;
			t = a[p2];
			cnt[t] += 1;
			if(cnt[t] == c[t]){
				enough_cnt += 1;
			}
		}
//		printf("p1=%d p2=%d min=%d\n", p1, p2, min);
		if(p2 >= len){
			break;
		}
		if(min > p2 - p1 + 1){
			min = p2 - p1 + 1;
		}
//		printf("p1=%d p2=%d min=%d\n", p1, p2, min);
		while(p1 <= p2 && enough_cnt >= 10){
			t = a[p1];
			cnt[t] -= 1;
			if(cnt[t]+1 == c[t]){
				enough_cnt -= 1;
			}
			p1 += 1;
		}
		if(min > p2 - p1 + 2){
			min = p2 - p1 + 2;
		}
//		printf("p1=%d p2=%d min=%d\n", p1, p2, min);
	}
	if(BIG_ENOUGH == min){
		printf("No Solution\n");
	}else{
		printf("%d\n", min);	
	}
}

int main(void){
	freopen("G.in", "r", stdin);
	while(input()){
		solve();
	}
	return 0;
}
