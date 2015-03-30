#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    /*
    string convertToTitle(int n) {
        string str;
        int a, b;
        b = n;
        do{
            a = b % 26;
            b = b / 26;
            if(a == 0){
                b -= 1;
                str.push_back('Z');
            }else{
                str.push_back('A' - 1 + a);
            }
        }while(b);
        reverse(str.begin(), str.end());
        return str;
    }
    */
    string convertToTitle(int n) {
        string str;
        while(n > 0){
            n -= 1;
            str.insert(0, 1, 'A' + (n % 26));
            n /= 26;
        }
        return str;
    }
};

int main(void){
    Solution s;
    printf("%s\n", s.convertToTitle(18278).c_str());
    system("pause");  
    return 0;
}
