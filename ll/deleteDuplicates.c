#include<stdio.h>
#include<stdlib.h>
#include "listUtil.h"

struct ListNode* deleteDuplicates(struct ListNode* head) {
    if(!head) return NULL;
    struct ListNode* ref = head;
    struct ListNode* p = head->next;
    while(p) {
        if(p->val == ref->val)  {
            ref->next = p->next;
        }
        else{
            ref = p;
        }
        p = p->next;
    }
    return head;
}

int main()  {
    int arr[] = {1,1,2,3,3};
    int arrSize = sizeof(arr)/sizeof(arr[0]);
    struct ListNode* llist = array2List(arr, arrSize);
    printList(llist);
    struct ListNode* rlist = deleteDuplicates(llist);
    printList(rlist);
    return 0;
}