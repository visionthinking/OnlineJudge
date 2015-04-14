#include <stdio.h>
#include <string.h>
#include <iostream>

const int MAX = 50005;

struct node {
	int left, right;
	int value;	
};

int a[MAX];
struct node seg[MAX << 2];

inline void updateUp(int n){
	seg[n].value = seg[n*2].value + seg[n*2+1].value;
}

void build(int n, int l, int r){
	seg[n].left = l;
	seg[n].right = r;
	if(l == r){
		seg[n].value = a[l];
		return;
	}
	int mid = (l+r)/2;
	build(n*2, l, mid);
	build(n*2+1, mid+1, r);
	updateUp(n);
}

void update(int n, int x, int value){
	if(seg[n].left == seg[n].right && x == seg[n].left){
		seg[n].value += value;
		if(seg[n].value < 0) seg[n].value = 0;
		return;
	}
	int mid = (seg[n].left + seg[n].right) / 2;
	if(x <= mid) update(n*2, x, value);
	if(x > mid)  update(n*2+1, x, value);
	updateUp(n);
}

void debug(int n){
	printf("%d [%d-%d] value=%d\n", n, seg[n].left, seg[n].right, seg[n].value);
	if(seg[n].left == seg[n].right){
		return;
	}
	debug(n*2);
	debug(n*2+1);
}

int query(int n, int l, int r){
	if(seg[n].left > r || seg[n].right < l){
		return 0;	
	}
	if(l <= seg[n].left && seg[n].right <= r){
		return seg[n].value;
	}
	int q1 = query(n*2, l, r);
	int q2 = query(n*2+1, l, r);
	return q1+q2;
}

void solution(int I){
	int len, i;
	scanf("%d", &len);
	for(i=0;i<len;i++){
		scanf("%d", &a[i]);
	}
	build(1, 0, len-1);
	
	char str[10] = {0};
	int x, y;
	printf("Case %d:\n", I);
	do{	
		str[0] = 0;
		scanf("%s", str);
		if(strcmp(str, "Query") == 0){
			scanf("%d %d", &x, &y);
			x -= 1; y -= 1;
			//debug(1);
			//printf("\n\nquery(%d, %d)=%d\n", x, y, query(1, x, y));
			printf("%d\n", query(1, x, y));
		}else if(strcmp(str, "Add") == 0){
			scanf("%d %d", &x, &y);
			x -= 1;
			update(1, x, y);
		}else if(strcmp(str, "Sub") == 0){
			scanf("%d %d", &x, &y);
			x -= 1;
			update(1, x, -y);
		}
	}while(strcmp(str, "End") != 0);
	
}

int main(void){
	freopen("p1166.in", "r", stdin);
	int t;
	while(scanf("%d", &t) != EOF){
		for(int i=1;i<=t;i++){
			solution(i);
		}
	}
}
