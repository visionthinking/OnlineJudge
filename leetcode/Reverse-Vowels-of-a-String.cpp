#include <stdio.h>
#include <string.h>
#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <stack>
#include <algorithm>

using namespace std;


class Solution {
public:
    bool isVowel(char c) {
        switch(tolower(c)) {
            case 'a':
            case 'e':
            case 'i':
            case 'o':
            case 'u':
                return true;
        }
        return false;
    }
    
    string reverseVowels(string s) {
        int i=0, j=s.length()-1;
        while(i < j) {
            cout << i << " " << j << endl;
            if(!isVowel(s[i])) { 
                ++i;
                continue;
            }
            if(!isVowel(s[j])) {
                --j;
                continue;
            }
            swap(s[i], s[j]);
        }
        return s;
    }
};

int main(void) {
	Solution s;
	cout << s.reverseVowels("hello") << endl;
	return 0;
}
