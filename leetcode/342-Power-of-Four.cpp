#include <iostream>
#include <math.h>
using namespace std;

class Solution {
public:
    bool isPowerOfTwo(int n) {
        return n > 0 && 1073741824 % n == 0;
    }
    
    bool isPowerOfFour(int num) {
    	if(num <= 0) return false;
        int sq = sqrt(num);
		return sq * sq == num && isPowerOfTwo(sq);
    }
};

int main(void) {
	Solution s;
	cout << s.isPowerOfFour(1) << endl;
	cout << s.isPowerOfFour(2) << endl;
	cout << s.isPowerOfFour(3) << endl;
	cout << s.isPowerOfFour(4) << endl;
	cout << s.isPowerOfFour(8) << endl;
	cout << s.isPowerOfFour(16) << endl;
	return 0;
}
