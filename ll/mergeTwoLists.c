#include<stdio.h>
#include<stdlib.h>
#include "listUtil.h"

void processList(struct ListNode** head, struct ListNode** tail, struct ListNode** lnode)   {
    insertAtTail(head, tail, (*lnode)->val);
    *lnode = (*lnode)->next;
}


struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
    struct ListNode* head = NULL;
    struct ListNode* tail = NULL;

    while(list1 && list2)   {
        if(list1->val < list2->val) {
            processList(&head, &tail, &list1);
        }
        else {
            processList(&head, &tail, &list2);
        }
    }
    while(list1)    {
        processList(&head, &tail, &list1);
    }
    while(list2)    {
        processList(&head, &tail, &list2);
    }
    return head;
}

int main() {
    int arr1[] = {1, 2, 4};
    int arr2[] = {1, 3, 4};

    int arr1count = sizeof(arr1) / sizeof(arr1[0]);
    int arr2count = sizeof(arr2) / sizeof(arr2[0]);

    struct ListNode* list1 = array2List(arr1, arr1count);
    struct ListNode* list2 = array2List(arr2, arr2count);

    printList(list1);
    printList(list2);

    printList(mergeTwoLists(list1, list2));

    return 0;
}
