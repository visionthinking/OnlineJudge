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
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        int len = 0, m;
        ListNode * t, * target;
        
        t = head;
        
        while(t){
            len += 1;
            t = t->next;
        }
        
        if(n == len){
            t = head->next;
            delete head;
            return t;
        }else if(n < len && n >= 1){
            t = head;
            m = len - n - 1;
            while(m--){
                t = t->next;
            }
            target = t->next;
            t->next = target->next;
            delete target;
            return head;
        }
        return head;
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
    ListNode a1(1), a2(2), a3(3), a4(4), a5(5);
    a1.next = &a2;
    a2.next = &a3;
    a3.next = &a4;
    a4.next = &a5;
 
    printList(&a1);
    
    Solution s;
    printList(s.removeNthFromEnd(&a1, 1));
    
    system("pause");
    return 0;   
}
