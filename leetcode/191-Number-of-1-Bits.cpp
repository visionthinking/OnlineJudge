#include <iostream>
using namespace std;

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int cnt = 0;
        for(; n != 0; n >>= 1) {
            if(n & 1) cnt += 1;
        }
        return cnt;
    }
};

int main(void) {
	Solution s;
	cout << s.hammingWeight(0) << endl;
	cout << s.hammingWeight(1 << 1) << endl;
	cout << s.hammingWeight((uint32_t) (1 << 31)) << endl;
	cout << s.hammingWeight(2147483648) << endl;
	return 0;
}
