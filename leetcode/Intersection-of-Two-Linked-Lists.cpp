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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int len1 = 0, len2 = 0;
        ListNode * t1, * t2, * tail;
        
        tail = NULL;
        t1 = headA;
        while(t1){
            len1 += 1;
            if(t1->next == NULL){
                tail = t1;
            }
            t1 = t1->next;
        }
        
        t2 = headB;
        while(t2){
            len2 += 1;
            if(t2->next == NULL){
                if(t2 != tail){
                    return NULL;
                }
            }
            t2 = t2->next;
        }
        
        t1 = headA;
        t2 = headB;
        if(len1 < len2){
            t1 = headB;
            t2 = headA;
        }
        
        int n = abs(len1 - len2);
        while(n--){
            t1 = t1->next;   
        }
        
        while(t1 != t2){
            t1 = t1->next;
            t2 = t2->next;
        }
        return t1;
    }
};

void printList(struct ListNode * l){
    struct ListNode * t = l;
    if(!t) return;
    do{
       printf("%d ", t->val);
       t = t->next;
    }while(t);
    printf("\n");
}

int main(){
    ListNode a1(1), a2(2), a3(3);
    a1.next = &a2;
    a2.next = &a3;
    
    ListNode b1(4), b2(5), b3(6);
    b1.next = &b2;
    b2.next = &b3;
    
    ListNode c1(10), c2(11), c3(12);
    c1.next = &c2;
    c2.next = &c3;
    
    a3.next = &c1;
    b1.next = &c1;
    
    printList(&a1);
    printList(&b1);
    
    Solution s;
    printList(s.getIntersectionNode(&a1, &b1));
    
    system("pause");
    return 0;   
}
