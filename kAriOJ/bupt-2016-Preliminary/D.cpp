#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;
 
const int MAX = 100005;
int a[MAX];
int label[MAX];
int n;

inline
int max(int a, int b){
	return a > b ? a : b;
}

void init(){
}
 
void input(){
    scanf("%d", &n);
    for(int i=0;i<n;i+=1){
    	scanf("%d", &a[i]);
    }
}

void print(int * a, int len){
	for(int i=0;i<len;i+=1){
    	printf("%d ", a[i]);
	}
	printf("\n");
}

void solve(){
    memset(label, -1, sizeof(label));
    int m = 1, result = 1;
    int start = 0;
    label[a[0]] = 0;
    for(int i=1;i<n;i+=1){
    	int curr = a[i];
    	if(label[curr] == -1){
    		label[curr] = i;
    		m += 1;
    		result = max(result, m);
//    		printf("[%d] result: %d\n", i, result);
//    		printf("label: ");
//    		print(label, n);
    	}else{
    		int to = label[curr];
    		for(int j=start; j<=to; j+=1){
    			label[a[j]] = -1;
    		}
    		start = to + 1;
    		m = (i - start) + 1;
    		label[curr] = i;
    		result = max(result, m);
    	}
    }
	
    printf("%d\n", result);
}
 
int main(void){
    freopen("D.in", "r", stdin);
	
    int kase;
    while(scanf("%d", &kase) != EOF){
        for(int i=1; i<=kase; i+=1){
            input();
            solve();
        }
    }
    return 0;
}
