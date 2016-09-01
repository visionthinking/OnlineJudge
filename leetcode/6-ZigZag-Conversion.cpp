#include <stdio.h>
#include <iostream>
using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows <= 1) return s;
		string r;
        int padding = 2 * numRows - 2;
        for(int row = 1; row <= numRows; row += 1) {
            int start = row - 1;
            int step = (numRows - row) * 2;
            for(int i=start; i<s.length(); i+=padding) {
                r += s[i];
               	if(step > 0 && padding - step != 0) {
                    if(i+step < s.length()) r += s[i+step];
                    else break;
                }
            }
        }
        return r;
    }
};

int main(void){
	Solution s;
	cout << s.convert("PAYPALISHIRING", 4) << endl;
	cout << s.convert("PAYPALISHIRING", 3) << endl;
	cout << s.convert("PAYPALISHIRING", 0) << endl;
	cout << s.convert("A", 1) << endl;
	return 0;	
}
