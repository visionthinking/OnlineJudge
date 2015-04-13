#include <stdio.h>
#include <string.h>

inline int min(int a, int b) { return a < b ? a : b; };

const int MAX = 100000;
const int MAX_SEG = MAX << 2 | 10;
const int MAX_INT = 1 << 30;
struct node {
	int left, right;
	int value;
};

struct node seg[MAX_SEG] = {0};
int a[MAX];
int len;

void build(int n, int l, int r){
	seg[n].left = l;
	seg[n].right = r;
	if(l == r){
		seg[n].value = a[l];
	}else{
		build(n*2, l, (l+r)/2);
		build(n*2+1, (l+r)/2+1, r);
		
		seg[n].value = min(seg[n*2].value, seg[n*2+1].value);
	}
}

int query(int n, int l, int r){
	if(seg[n].left > r || seg[n].right < l){
		//由于是求最小值，使用一个trick 
		return MAX_INT;	
	}
	
	if(l <= seg[n].left && seg[n].right <= r){
		//如果是叶子节点，直接返回，减少更新的麻烦 
		return (seg[n].left == seg[n].right) ? a[seg[n].left] : seg[n].value;
	}
	int v1, v2;
	v1 = query(n*2, l, r);
	v2 = query(n*2+1, l, r);
	return min(v1, v2);
}

//单点向上更新 (不会越界，因为每一个非叶子节点都会有两个孩子)
void updateUp(int n){
	if(n == 1) {
		return;
	}
	int p = n / 2;
	seg[p].value = min(seg[p*2].value, seg[p*2+1].value);
	updateUp(p);
}


//区间更新(use 'Dirty' mark) 
void update(int n, int l, int r){
	if(l <= seg[n].left && seg[n].right <= r){
		if(seg[n].left == seg[n].right){
			seg[n].value = a[seg[n].left]; 
		}else{
			seg[n].value = min(seg[n*2].value, seg[n*2+1].value);
		}
		return;
	}
}

int main(void){
	freopen("SegmentTree.in", "r", stdin);
	
	scanf("%d", &len);
	for(int i=0;i<len;i++){
		scanf("%d", &a[i]);
	}
	
	build(1, 0, len);
	
	int left = 3;
	int right = 5;
	printf("query(%d, %d)=%d\n", left, right, query(1, left, right));
	
	return 0;
}
