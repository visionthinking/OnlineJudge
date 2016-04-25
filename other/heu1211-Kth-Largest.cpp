/* http://202.118.176.37/index.php?act=problem&id=1211 
Binary Answer + Binary Search
*/

#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

const int MAX = 10005;
int n, k;
int a[MAX], b[MAX];

void input(){
	scanf("%d%d", &n, &k);
	for(int i=0; i<n; i+=1){
		scanf("%d", &a[i]);
	}
	for(int i=0; i<n; i+=1){
		scanf("%d", &b[i]);
	}	
}

bool is_valid(int v){
	int cnt = 0;
	for(int i=0; i<n; i+=1){
		int t = v / a[i];
		int bi = upper_bound(b, b+n, t) - b;
		cnt += min(bi, n);
//		printf("a[%d]=%d cnt=%d\n", i, a[i], cnt);
	}
	return cnt >= k;
}

void solve(){
	k = 1+n*n-k;
	sort(a, a+n);
	sort(b, b+n);
	int l = a[0]*b[0], r = a[n-1]*b[n-1];
//	printf("\n[%d, %d] k=%d\n", l, r, k);
	while(l < r){
		int mid = l + (r - l)/2;
//		printf("mid=%d\n", mid);
		if(is_valid(mid)){
			r = mid;
		}else{
			l = mid + 1;
		}
	}
	printf("%d\n", l);
}

int main(void){
	freopen("heu1211-Kth-Largest.in", "r", stdin);
	int kase;
	while(scanf("%d", &kase) != EOF){
		for(int i=1; i<=kase; i+=1){
			input();
			solve();
		}
	}
	return 0;
}
