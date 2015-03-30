#include <iostream>
#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        int n1, n2, c;
        struct ListNode * t, result(0);
        
        c = 0;
        t = &result;
        
        while(l1 || l2 || c){
            n1 = l1? l1->val:0;
            n2 = l2? l2->val:0;
            t->next = new ListNode(( c + n1 + n2 ) % 10);
            t = t->next;
            c = ( c + n1 + n2 ) / 10;    
            l1 = l1? l1->next:NULL;
            l2 = l2? l2->next:NULL;
        }
        
        return result.next;
    }
};

void printList(struct ListNode * l){
    struct ListNode * t = l;
    do{
       printf("%d ", t->val);
       t = t->next;
    }while(t);
    printf("\n");
}

int main(){
    ListNode a1(2), a2(4), a3(3);
    a1.next = &a2;
    a2.next = &a3;
    
    ListNode b1(3), b2(4), b3(5);
    b1.next = &b2;
    b2.next = &b3;
 
    printList(&a1);
    printList(&b1);
    
    Solution s;
    printList(s.addTwoNumbers(&a1, &b1));
    
    system("pause");
    return 0;   
}
