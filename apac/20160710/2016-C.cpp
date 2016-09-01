#include <stdio.h>
#include <string.h>
#include <string>
#include <algorithm>
#include <math.h>

using namespace std;

#define PREC 1e-11

int m;
int c[200];

double calc(double r){
	double _res = 0.0;
	double _t = 1.0;
	for(int i=m; i>=0; i-=1){
		_res += c[i] * _t;
		_t *= (1+r);
	}
	return _res;
}

void solve(int kase){
	scanf("%d", &m);
	for(int i=0; i<=m; i+=1){
		scanf("%d", &c[i]);
	}
	c[0] = -c[0];
	double a = -1.0, b = 1.0, m = 0.0;
	double r0, r1, r2;
	
	while(1){
		m = (a + b) * 0.5;
		r0 = calc(a);
		r1 = calc(m);
		if(r0 * r1 <= 0.0){
			b = m;	
		}else{
			a = m;	
		}
		if((b - a) < PREC){
			break;	
		}
	}
	printf("Case #%d: %.12f\n", kase, m);
}

int main(void){
	freopen("C-large.in", "r", stdin);
	int kase;
	scanf("%d", &kase);
	for(int i=1; i<=kase; i+=1){
		solve(i);	
	}
	return 0;
}
