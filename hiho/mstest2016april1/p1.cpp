#include <stdio.h>
#include <math.h>
#include <string.h>

const int MAX = 1005;
int n, p, w, h;
double a[MAX];

void solve(){
	int sum_line, max_line;
	for(int s=w; s>=0; s-=1){
		max_line = p * (h / s);
		sum_line = 0;
		for(int j=0; j<n; j+=1){
			sum_line += ceil(a[j] / (w/s));
		}
		if(sum_line <= max_line){
			printf("%d\n", s);
			return;
		}
	}
}

int main(void){
	freopen("p1.in", "r", stdin);
	int kase;
	scanf("%d", &kase);
	for(int i=1; i<=kase; i+=1){
		scanf("%d%d%d%d", &n, &p, &w, &h);
		for(int j=0;j<n;j+=1){
			scanf("%lf", &a[j]);
		}
		solve();
	}
	return 0;	
}
