#include <stdio.h>
#include <string.h>

inline int min(int a, int b) { return a < b ? a : b; };

const int MAX = 100000;
const int MAX_SEG = MAX * 4 + 10;
const int MAX_INT = 1 << 30;
struct node {
	int left, right;
	int value;
};

struct node seg[MAX_SEG] = {0};
int a[MAX];
int len;

//向上更新
inline void updateUp(int n){
	seg[n].value = min(seg[n*2].value, seg[n*2+1].value);
}

void build(int n, int l, int r){
	seg[n].left = l;
	seg[n].right = r;
	if(l == r){
		seg[n].value = a[l];
		return;
	}
	build(n*2, l, (l+r)/2);
	build(n*2+1, (l+r)/2+1, r);
	updateUp(n);
}

//区间更新
void update(int n, int l, int r, int value){
	if(seg[n].left == seg[n].right && l <= seg[n].left && seg[n].right <= r){
		seg[n].value = value;
		return;
	}
	int mid = (seg[n].left+seg[n].right)/2;
	if(l <= mid) update(n*2, l, r, value);
	if(r > mid)  update(n*2+1, l, r, value);	
	updateUp(n);
}

int query(int n, int l, int r){
	if(seg[n].left > r || seg[n].right < l){
		return MAX_INT;	//求最小值trick 
	}
	
	if(l <= seg[n].left && seg[n].right <= r){
		return seg[n].value;
	}
	int v1, v2;
	v1 = query(n*2, l, r);
	v2 = query(n*2+1, l, r);
	return min(v1, v2);
}


void debug(int n){
	printf("%d\t[%d-%d] value=%d\n", n, seg[n].left, seg[n].right, seg[n].value);
	if(seg[n].left == seg[n].right){
		return;
	}
	debug(n*2);
	debug(n*2+1);
}

int main(void){
	freopen("SegmentTree.in", "r", stdin);
	
	scanf("%d", &len);
	for(int i=0;i<len;i++){
		scanf("%d", &a[i]);
	}
	
	build(1, 0, len-1);
	
	update(1, 0, 2, 10);
	
	int left = 0;
	int right = 5;
	printf("query(%d, %d)=%d\n", left, right, query(1, left, right));
	
	debug(1);
	
	return 0;
}
