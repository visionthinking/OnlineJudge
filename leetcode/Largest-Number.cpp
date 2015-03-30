#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <vector>

#include <sstream>
#include <algorithm>

using namespace std;

bool mycmp(int a, int b){
    char x1[40], x2[40];
    sprintf(x1, "%d%d", a, b);
    sprintf(x2, "%d%d", b, a);
    return strcmp(x1, x2) > 0;
}

class Solution {
public:
    string largestNumber(vector<int> &num) {
        sort(num.begin(), num.end(), mycmp);
        if(num.size() > 0 && num[0] == 0){
            return "0";
        }
        ostringstream o;
        for(int i=0;i<num.size();i++){
            o << num[i];
        }
        return o.str();
    }
};

int main(void){
    int t[] = {3, 30, 34, 5, 9};
    vector<int> a(t, t + (sizeof(t)/sizeof(t[0])));
    
    Solution s;
    cout << s.largestNumber(a) << endl;
    
    //cout << strcmp("303", "330") << endl;
    
    system("pause");
    return 0;
}
