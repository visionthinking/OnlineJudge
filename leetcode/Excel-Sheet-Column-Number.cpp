#include <stdio.h>
#include <stdlib.h>
#include <string>

using namespace std;

class Solution {
public:
    int titleToNumber(string s) {
        int len = s.length();
        int total = 0;
        int c = 1;
        for(int i=len-1;i>=0;i--){
            total += (s[i] - 'A' + 1) * c;
            c *= 26;
        }
        return total;
    }
};

int main(void){
    Solution s;
    printf("%d\n", s.titleToNumber("ZZZ"));
    system("pause");  
    return 0;
}
