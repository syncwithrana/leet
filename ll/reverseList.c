#include<stdio.h>
#include<stdlib.h>
#include "listUtil.h"

struct ListNode* reverseList(struct ListNode* head)  {
    struct ListNode* prev = NULL;
    struct ListNode* curr = head;
    struct ListNode* next;
    
    while(curr) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

int main()  {
    int arr[] = {1,2,3,4,5};
    int arrSize = sizeof(arr)/sizeof(arr[0]);
    struct ListNode* llist = array2List(arr, arrSize);
    printList(llist);
    struct ListNode* rlist = reverseList(llist);
    printList(rlist);
    return 0;
}