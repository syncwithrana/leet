#include <stdio.h>
#include <stdlib.h>
#include "listUtil.h"

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    int c = 0;
    struct ListNode* ret = NULL;
    struct ListNode** p = &ret;
    while(l1 || l2 || c)  {
        int a = 0;
        int b = 0;
        if(l1)  {
            a = l1->val;
            l1 = l1->next;
        }
        if(l2)  {
            b = l2->val;
            l2 = l2->next;
        }
        int sum = a + b + c;
        struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
        newNode->val = sum % 10;
        newNode->next = NULL;
        *p = newNode;
        p = &((*p)->next);
        c = sum / 10;
        printf("%d %d %d %d\n", a, b, c, sum);
    }
    return ret;
}

int main() {
    int arr1[] = {2, 4, 3};
    int arr2[] = {5, 6, 4};

    int arr1count = sizeof(arr1) / sizeof(arr1[0]);
    int arr2count = sizeof(arr2) / sizeof(arr2[0]);

    struct ListNode* list1 = array2List(arr1, arr1count);
    struct ListNode* list2 = array2List(arr2, arr2count);

    printList(list1);
    printList(list2);
    struct ListNode* result = addTwoNumbers(list1, list2);
    printList(result);
    return 0;
}
