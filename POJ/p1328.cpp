#include <stdio.h>
#include <string.h>
#include <math.h>
#include <algorithm>
#include <iostream>

using namespace std;

struct node {
	int x, y;
	double sx, ex;
};

struct node v[1005];

bool mycmp(const struct node & n1, const struct node & n2){
	return n1.sx < n2.sx;
}

void solution(int n, int d){
	int flag = 0;
	double tx;
	for(int i=0;i<n;i++){
		scanf("%d %d", &v[i].x, &v[i].y);
		if(v[i].y > d){
			flag = 1;
		}
		tx = sqrt((double)(d*d-v[i].y*v[i].y));
		v[i].sx = v[i].x - tx;
		v[i].ex = v[i].x + tx;
	}
	
	if(flag || d <= 0){
		printf("-1\n");
		return;	
	}
	
	sort(v, v+n, mycmp);
	
	int count, i, j;
	
	count = 0;
	
	for(i=0;i<n;i++){
		if(v[i].y >= 0){
			count += 1;
			for(j=i+1;j<n;j++){
				if(v[i].ex >= v[j].sx && v[j].y >= 0){
					//merge
					v[j].y = -1;
					v[i].sx = v[j].sx;
					v[i].ex = min(v[i].ex, v[j].ex);
				}else{
					break;	
				}
			}
		}
	}
	
	printf("%d\n", count);
}

int main(void){
	
	freopen("p1328.in", "r", stdin);
	
	int n, d, i;
	i = 1;
	do {
		scanf("%d %d", &n, &d);
		if(n == 0 && d == 0){
			break;
		}
		printf("Case %d: ", i);
		i+=1;
		solution(n, d);
		
	}while(1);
	
	return 0;
}
