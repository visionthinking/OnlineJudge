#include <iostream>
#include <unordered_set>
using namespace std;

class Solution {
private:
    unordered_set<int> loop;
public:
    bool isHappy(int n) {
        while(n != 1) {
            int m = n, cnt = 0;
            while(m != 0) {
                cnt += (m % 10) * (m % 10);
                m /= 10;
            }
            n = cnt;
            if(loop.count(n) > 0) return false;
            loop.insert(n);
        }
        return true;
    }
};


int main(void) {
	Solution s;
	cout << s.isHappy(19) << '\n';
	return 0;
}
