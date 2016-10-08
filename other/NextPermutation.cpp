#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        for(int i=nums.size()-2; i>=0; i-- ) {
            if(nums[i] < nums[i+1]) {
                reverse(nums.begin()+i+1, end(nums));
                swap(nums[i], *upper_bound(nums.begin()+i+1, nums.end(), nums[i]));
                return;
            }
        }
        reverse(nums.begin(), nums.end());
    }
};

int main(void) {
	vector<int> a({1,4,3,2});
	Solution s;
	s.nextPermutation(a);
	auto it = a.begin() + 5;
	return 0;	
}
