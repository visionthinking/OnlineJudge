#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

class Solution {
public:
    double select(int k, vector<int>& a, vector<int>& b) {
    	int beg = 0, end = a.size() - 1;
        while(beg <= end) {
            int mid = (beg + end) / 2;
            int lb = lower_bound(b.begin(), b.end(), a[mid]) - b.begin();
            int _k = mid + lb;
            if(_k == k) {
                return a[mid];
            }else if(_k < k) {
                beg = mid + 1;
            }else{
                end = mid - 1;
            }
        }
        return b[k - beg];
    }
    
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int size = nums1.size() + nums2.size(); 
        if(size % 2 == 0) {
            return (select(size / 2, nums1, nums2) + select(size / 2 - 1, nums1, nums2)) / 2;
        } else {
            return select(size / 2, nums1, nums2);
        }
    }
};

int main(void){
	ios::sync_with_stdio(false);
	vector<int> a({1, 4, 10});
	vector<int> b({2, 3, 6, 8, 10});
	Solution s;
	for(int i=0; i<7; i+=1)
		cout << s.select(i, a, b) << endl;
	// cout << s.findMedianSortedArrays(a, b) << endl;
	return 0;
}
