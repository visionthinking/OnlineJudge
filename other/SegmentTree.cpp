#include <bits/stdc++.h>
using namespace std;

#define lchild rt << 1, l, m
#define rchild rt << 1 | 1, m + 1, r

class NumArray {
public:
    vector<int> tree;
    vector<int> nums;
    NumArray(vector<int> &_nums): tree(nums.size() * 4 + 10), nums(_nums) {
        build(1, 1, nums.size());
    }
    
    void push_up(int rt) {
        tree[rt] = tree[rt << 1] + tree[rt << 1 | 1];
    }
    
    void build(int rt, int l, int r) {
        if (l == r) { tree[rt] = nums[l-1]; return; }
        int m = (l + r) >> 1;
        build(lchild); build(rchild);
        push_up(rt);
    }

    void _update(int p, int val, int rt, int l, int r) {
        if (l == r) {
            tree[rt] = val;
            return;
        }
        int m = (l + r) >> 1;
        if (p <= m) _update(p, val, lchild);
        else _update(p, val, rchild);
        push_up(rt);
    }

    int query(int L, int R, int rt, int l, int r) {
        if (L <= l && r <= R) return tree[rt];
        int m = (l + r) >> 1, ret = 0;
        if (L <= m) ret += query(L, R, lchild);
        if (R > m)  ret += query(L, R, rchild);
        return ret;
    }
    
    void update(int i, int val) {
        _update(i+1, val, 1, 1, nums.size());
    }
    
    int sumRange(int i, int j) {
        return query(i+1, j+1, 1, 1, nums.size());
    }
};


int main(void) {
	vector<int> nums({1, 3, 5, 7});
	NumArray numArray(nums);
	cout << numArray.sumRange(0, 0) << endl;
	cout << numArray.sumRange(1, 1) << endl;
	cout << numArray.sumRange(2, 2) << endl;
	numArray.update(1, 2);
	cout << numArray.sumRange(0, 2) << endl;
	return 0;	
}


