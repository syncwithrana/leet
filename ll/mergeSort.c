#include <stdio.h>
#include <stdlib.h>
#include "listUtil.h"

struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
    struct ListNode* head = NULL;
    struct ListNode** tail = &head;

    while(list1 && list2)   {
        if(list1->val < list2->val) {
            *tail = list1;
            list1 = list1->next;
        }
        else {
            *tail = list2;
            list2 = list2->next;
        }
        tail = &((*tail)->next);
    }
    if(list1)    {
        *tail = list1;
    }
    if(list2)    {
        *tail = list2;
    }
    return head;
}

struct ListNode* findMiddle(struct ListNode* head)   {
    struct ListNode** sp = &head;
    struct ListNode* fp = head;
    while(fp && fp->next)   {
        fp = fp->next->next;
        sp = &((*sp)->next);
    }
    if(fp)  {
        sp = &((*sp)->next);
    }
    struct ListNode* head2 = *sp;
    (*sp) = NULL;
    return head2;
}

struct ListNode* mergeSort(struct ListNode* head){
    if(!head || !(head->next)) return head;
    printList(head);
    struct ListNode* head2 = findMiddle(head);
    head = mergeSort(head);
    head2 = mergeSort(head2);
    return mergeTwoLists(head, head2);
}

// Driver code
int main(){
    int arr[] = {0,5,4,2,1,3};
    int arrSize = sizeof(arr)/sizeof(arr[0]);
    struct ListNode* llist = array2List(arr, arrSize);
    printList(llist);
    llist = mergeSort(llist);
    printList(llist);
    return 0;
}