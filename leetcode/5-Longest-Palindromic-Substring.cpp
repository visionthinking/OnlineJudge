#include <stdio.h>
#include <iostream>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int len = s.length();
        int rlen = 0, rbegin;
        string res = "";
        for(int i = 0; i<len; i+=1) {
            char c = s[i];
            for(int j=i; j<len; j+=1) {
                int k = 2*i - j;
                // printf("(%d %d %d)\n", i, j, k);
				if(k >= 0 && s[k] == s[j]) {
                    if( res.length() < 1 + 2*(j-i)) {
                        res = s.substr(k, 1 + 2*(j-i));
                        // cout << "res=" << res << endl;
                    }
                }else{
                	break;	
                }
            }
            if(i > 0 && s[i] == s[i-1]) {
                for(int j=i; j<len; j+=1) {
                    int k = 2*i - j - 1;
                    if(k >= 0 && s[k] == s[j]) {
                        if (res.length() < 2*(1+j-i)) {
                            res = s.substr(k, 2*(1+j-i));
                        }
                    }else{
		            	break;	
		            }
                }
            }
        }
        return res;
    }
};

int main(void){
	Solution s;
	cout << s.longestPalindrome("abbxa") << endl;
	cout << s.longestPalindrome("a") << endl;
	cout << s.longestPalindrome("aa") << endl;
	cout << s.longestPalindrome("aaaabbbbaa") << endl;
	return 0;	
}
