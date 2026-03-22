#include "listUtil.h"

void insertSmall(struct ListNode** node, struct ListNode* key)  {
    while(*node && (*node)->val >  key->val)    {
        node = &((*node)->next);
    }
    key->next = *node;
    *node = key;
}


int main()  {
    int arr[] = {5,4,2,1};
    int arrSize = sizeof(arr)/sizeof(arr[0]);
    struct ListNode* llist = array2List(arr, arrSize);
    printList(llist);
    insertSmall(&llist, createNode(3));
    printList(llist);
    insertSmall(&llist, createNode(7));
    printList(llist);
    insertSmall(&llist, createNode(0));
    printList(llist);
    return 0;
}