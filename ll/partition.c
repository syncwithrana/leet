#include "listUtil.h"
#include <stdlib.h>
#include <stdio.h>
struct ListNode* partition(struct ListNode* head, int x) {
    struct ListNode* head2 = NULL;
    struct ListNode** p2 = &head2;
    struct ListNode** p1 = &head;

    while(*p1) {
        if((*p1)->val >= x)  {
            struct ListNode* next = (*p1)->next;
            *p2 = *p1;
            *p1 = next;
            p2 = &((*p2)->next);
        } else {
            p1 = &((*p1)->next);
        }
    }
    *p2 = NULL;
    *p1 = head2;
    return head;
}

int main()  {
    int arr[] = {1,4,3,2,5,2};
    int arrSize = sizeof(arr)/sizeof(arr[0]);
    struct ListNode* llist = array2List(arr, arrSize);
    printList(llist);
    struct ListNode* rlist = partition(llist, 3);
    printList(rlist);
    return 0;
}

