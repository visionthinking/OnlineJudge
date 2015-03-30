#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int majorityElement(vector<int> &num) {
        int p, count;
        p = 0;
        count = 1;
        for(int i = 1; i < num.size(); i++){
            if(num[p] == num[i]){
                count += 1;
            }else{
                count -= 1;
                if(count == 0){
                    count = 1;
                    p = i;
                }   
            }
        }
        return num[p];
    }
};

int main(void){
    
    int myints[] = {3,2,3,2,3};
    vector<int> a (myints, myints + sizeof(myints) / sizeof(int) );
    
    Solution s;
    printf("%d\n", s.majorityElement(a));
    system("pause");  
    return 0;
}
