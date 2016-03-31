/* Minimum Inversion Number */
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

const int MAX = 5005;

int n;
int a[MAX];

void solve(){
	for(int i=0;i<n;i+=1){
		scanf("%d", &a[i]);
	}
	
	int sum = 0, res;
	for(int i=0;i<n;i+=1){
		for(int j=i+1;j<n;j+=1){
			if(a[i] > a[j]){
				sum += 1;
			}
		}
	}
	res = sum;
	for(int i=0;i<n;i+=1){
		sum += (n-1)-a[i]-a[i];
		res = min(res, sum);
	}
	printf("%d\n", res);
}

int main(void){
	freopen("hdu1394.in", "r", stdin);
	while(scanf("%d", &n) != EOF){
		solve();
	}
	return 0;
}
