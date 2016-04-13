/* 1027. 2016 ICPC - Archer in Archery */
#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <algorithm>

using namespace std;

const int MAX = 10005;
int H[MAX], S[MAX];
int n;

struct node {
	int T, index;
} t[MAX];

bool node_cmp(const struct node & a, const struct node & b){
	return a.T < b.T;
}

bool is_valid(int Hx){
	for(int i=0; i<n; i+=1){
		t[i].T = (Hx - H[i]) / S[i];
		t[i].index = i;
	}
	sort(t, t+n, node_cmp);
	int res = 0;
	for(int i=0; i<n; i+=1){
		int index = t[i].index;
		res = max(res, H[index]+S[index]*i);
	}
	return res <= Hx;
}

int t_cnt[MAX];
bool is_valid_by_BR(int Hx){
	memset(t_cnt, 0, sizeof(t_cnt));
	for(int i=0; i<n; i+=1){
		int v = (Hx - H[i]) / S[i];
		if(v < n){
			t_cnt[v] += 1;	
		}
	}
	int sum = 0;
	for(int i=0; i<n; i+=1){
		sum += t_cnt[i];
		if(i+1 < sum){
			return false;
		}
	}
	return true;
}

void solve(){
	int min_bound = 0, max_bound = 0, min_nsec = INT_MAX;
	
	scanf("%d", &n);
	for(int i=0; i<n; i+=1){
		scanf("%d", &H[i]);
		min_bound = max(min_bound, H[i]);
	}
	
	for(int i=0; i<n; i+=1){
		scanf("%d", &S[i]);
		max_bound = max(max_bound, H[i]+S[i]*(n-1));
		min_nsec = min(min_nsec, H[i]+S[i]*(n-1));
	}
	min_bound = max(min_bound, min_nsec);
	
	// printf("bound: [%d, %d]\n", min_bound, max_bound);
	while(min_bound < max_bound){
		int m = min_bound + (max_bound - min_bound) / 2;
		if(is_valid_by_BR(m)){
			max_bound = m;
		}else{
			min_bound = m+1;	
		}
	}
	printf("%d\n", min_bound);
}

int main(void){
	freopen("p1027.in", "r", stdin);
	int kase;
	while(scanf("%d", &kase) != EOF){
		for(int i=1; i<=kase; i+=1){
			solve();
		}
	}
	return 0;
}
