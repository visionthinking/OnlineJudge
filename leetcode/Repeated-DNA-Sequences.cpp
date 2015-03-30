/* Repeated-DNA-Sequences */

#include <iostream>
#include <stdlib.h>

#include <vector>
#include <string>
#include <hash_map>

using namespace std;

class Solution {
public:
    int getValue(string & s, int pos){
        int v = 0;
        int n = 1;
        int m;
        for(int i = 9 + pos; i >= 0 + pos; i--){
            switch(s[i]){
            case 'A':
                v += n * 0;
                n *= 2;
                v += n * 0;
                n *= 2;
                break;
            case 'C':
                v += n * 1;
                n *= 2;
                v += n * 0;
                n *= 2;
                break;
            case 'G':
                v += n * 0;
                n *= 2;
                v += n * 1;
                n *= 2;
                break;
            case 'T':
                v += n * 1;
                n *= 2;
                v += n * 1;
                n *= 2;
                break;
            }
        }
        return v;
    }

    vector<string> findRepeatedDnaSequences(string s) {
        hash_map<int, int> vmap;
        vector<string> result;
        const char * str;
        int len, value;
        
        len = s.length();
        str = s.c_str();
        for(int i = 0; i < len - 9; i++){
            value = getValue(s, i);
            map<int, int>::iterator iter = vmap.find(value);
            if(iter == vmap.end()){
                vmap[value] = 1;
            }else{
                if(iter->second == 1){
                    string t = s.substr(i,10);
                    result.push_back(t);
                    vmap[value] += 1;
                }
            }
        }
        return result;
    }
};



Solution s;

void printVector(vector<string> a){
    for(vector<string>::iterator it = a.begin();it != a.end(); it++){
        cout << *it << " ";
    }   
    cout << endl;
}

void test_1(){
    vector<string> a = s.findRepeatedDnaSequences("AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT");
    printVector(a);
}

void test_2(){
    vector<string> a = s.findRepeatedDnaSequences("AAAAAAAAAAAAAA");
    printVector(a);
}

int main(void){
    test_1();
    test_2();
    system("pause");
    return 0;
}
