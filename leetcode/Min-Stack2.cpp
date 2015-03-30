#include <stdlib.h>
#include <iostream>

#include <stack> 
using namespace std;

class MinStack {
private:
    stack<int> s;
    stack<int> t;
public:
    void push(int x) {
        s.push(x);
        if(t.empty() || x <= t.top()) {
            t.push(x);
        }
    }

    void pop() {
        int a = s.top();
        s.pop();
        if(a <= t.top()) {
            t.pop();
        }
    }

    int top() {
        return s.top();
    }

    int getMin() {
        return t.top();
    }
};
void test(){
    MinStack s;
    s.push(0);
    cout << s.top() << " " << s.getMin() << endl;
    s.push(1);
    cout << s.top() << " " << s.getMin() << endl;
    s.push(0);
    cout << s.top() << " " << s.getMin() << endl;
    s.pop();
    cout << s.top() << " " << s.getMin() << endl;
    
    cout << sizeof(s) << " " << endl;
}

int main(void){
    test();
    system("pause");   
    return 0;
}
