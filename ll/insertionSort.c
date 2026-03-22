#include "listUtil.h"
#include <stdlib.h>
#include <stdio.h>

void insertSmall(struct ListNode** node, struct ListNode* key)  {
    while(*node && (*node)->val < key->val)   {
        node = &((*node)->next);
    }
    key->next = *node;
    *node = key;
}

struct ListNode* insertionSortList(struct ListNode* head) {
    if(!head || !(head->next)) return head;
    struct ListNode* tail = head;
    struct ListNode* key = head->next;
    head->next = NULL;
    while(key)  {
        struct ListNode* next = key->next;
        if (key->val >= tail->val) {
            key->next = NULL;
            tail->next = key;
            tail = key;
        } else {
            insertSmall(&head, key);
        }
        key = next;
    }
    return head;   
}

int main()  {
    int arr[] = {0,5,4,2,1,3};
    //int arr[] = {-1,5,3,4,0};
    int arrSize = sizeof(arr)/sizeof(arr[0]);
    struct ListNode* llist = array2List(arr, arrSize);
    printList(llist);
    llist = insertionSortList(llist);
    printList(llist);
    return 0;
}