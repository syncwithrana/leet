#include <stdio.h>
#include <stdlib.h>
#include "listUtil.h"
#include <stdbool.h>

/* Attach tail to end of list */
void attachTail(struct ListNode* head, struct ListNode* tail) {
    while (head->next)
        head = head->next;
    head->next = tail;
}

/* YOUR LOGIC */
struct ListNode* cyclePoint(struct ListNode* head)    {
    struct ListNode* sp = head;
    struct ListNode* fp = head;
    bool isCycle = false;
    while(fp && fp->next)   {
        sp = sp->next;
        fp = fp->next->next;
        if(sp == fp)    {
            isCycle = true;
            break;
        }
    }
    if(isCycle) {
        sp = head;
        while(sp != fp) {
            sp = sp->next;
            fp = fp->next;
        }
        return sp;
    }
    else{
        return NULL;
    }
}

struct ListNode* endNode(struct ListNode* head)  {
    while(head && head->next) {
        head = head->next;
    }
    return head;
}

struct ListNode* getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    struct ListNode* endN = endNode(headA);
    endN->next = headB;
    struct ListNode* res = cyclePoint(headA);
    endN->next = NULL;
    return res;
}

int main() {
    /* Common tail */
    int commonArr[] = {8, 4, 5};
    struct ListNode* common = array2List(commonArr, 3);

    /* Prefix A: skipA = 2 */
    int arrA[] = {4, 1};
    struct ListNode* headA = array2List(arrA, 2);
    attachTail(headA, common);

    /* Prefix B: skipB = 3 */
    int arrB[] = {5, 6, 1};
    struct ListNode* headB = array2List(arrB, 3);
    attachTail(headB, common);

    struct ListNode* res = getIntersectionNode(headA, headB);

    if (res)
        printf("Intersection at node with value: %d\n", res->val);
    else
        printf("No intersection\n");

    return 0;
}
