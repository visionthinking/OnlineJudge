#include <stdlib.h>
#include <iostream>


using namespace std;


#include <memory.h>

class MinStack {
public:
    int * a, * b;
    int size;
    int capacity;
public:
    MinStack(){
        capacity = 1;
        size = 0;
        a = new int[capacity];
        b = new int[capacity];
    }
    
    ~MinStack(){
        delete [] a;
        delete [] b;
    }
    
    void push(int x) {
        if(size >= capacity){
            int * t;
            t = a;
            a = new int[capacity + 1];
            memcpy(a, t, capacity * sizeof(int));
            delete [] t;
            t = b;
            b = new int[capacity + 1];
            memcpy(b, t, capacity * sizeof(int));
            delete [] t;
            capacity += 1;
        }
        
        a[size] = x;
        if(size == 0){
            b[size] = x;
        }else{
            b[size] = (x < b[size-1]) ? x : b[size-1];  
        }
        size += 1;
    }

    void pop() {
        if(size > 0){
            size -= 1;   
        }
    }

    int top() {
        return a[size-1];
    }

    int getMin() {
        return b[size-1];
    }
};

void test(){
    MinStack s;
    s.push(5);
    cout << s.top() << " " << s.getMin() << endl;
    s.push(2);
    cout << s.top() << " " << s.getMin() << endl;
    s.push(3);
    cout << s.top() << " " << s.getMin() << endl;
    s.push(4);
    cout << s.top() << " " << s.getMin() << endl;
    s.push(1);
    cout << s.top() << " " << s.getMin() << endl;
    
    cout << sizeof(s) << " " << s.capacity << endl;
}

int main(void){
    test();
    system("pause");   
    return 0;
}
