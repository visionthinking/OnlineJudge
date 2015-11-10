/* For requiring help, please refer to book page 132. */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>

using namespace std;

const int MAX = 200;
struct building {
	int id;
	double x, y, w, d, h;
	double xr;
};

int n;
struct building b[MAX];
int xs[MAX];

bool building_cmp(const struct building & a, const struct building & b){
	return a.x < b.x || (a.x == b.x && a.y < b.y);
}

bool is_visible(int id, double x){
	if(b[id].x <= x && x <= b[id].xr){
		for(int i=0;i<n;i+=1){
			if(b[i].x <= x && x <= b[i].xr && b[i].h >= b[id].h && b[i].y < b[id].y){
				return false;
			}
		}
		return true;
	}
	return false;
}

void solve(){
	sort(xs, xs+n*2);
	int k = unique(xs, xs+n*2) - xs;
	sort(b, b+n, building_cmp);
	printf("%d", b[0].id);
	for(int i=1;i<n;i+=1){		// building must be traversed first, why ?
		for(int j=1;j<k;j+=1){
			double mid = (xs[j-1] + xs[j]) * 0.5;
			if(is_visible(i, mid)){
				printf(" %d", b[i].id);	
				break;
			}
		}
	}
	printf("\n");
}

void input(){
	for(int i=0;i<n;i+=1){
		b[i].id = i+1;
		scanf("%lf %lf %lf %lf %lf", &b[i].x, &b[i].y, &b[i].w, &b[i].d, &b[i].h);
		b[i].xr = b[i].x + b[i].w;
		xs[i*2] = b[i].x;
		xs[i*2+1] = b[i].xr;
	}
}

int main(void){
	freopen("uva221.in", "r", stdin);
	int kase = 0;
	while(scanf("%d", &n) && n > 0){
		kase += 1;
		if(kase > 1) printf("\n");
		printf("For map #%d, the visible buildings are numbered as follows:\n", kase);
		input();
		solve();
	}
	return 0;
}
