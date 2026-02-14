#include <stdio.h>
#include <stdlib.h>
#include "listUtil.h"
#include<stdbool.h>

bool hasCycle(struct ListNode* head)    {
    struct ListNode* sp = head;
    struct ListNode* fp = head;
    while(fp && fp->next)   {
        sp = sp->next;
        fp = fp->next->next;
        if(sp == fp)    {
            return true;
        }
    }
    return false;
}

int main() {
    struct ListNode *n1 = createNode(1);
    struct ListNode *n2 = createNode(2);
    struct ListNode *n3 = createNode(3);
    struct ListNode *n4 = createNode(4);
    struct ListNode *n5 = createNode(5);
    struct ListNode *n6 = createNode(6);

    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;
    n5->next = n6;

    n6->next = n4;

    printf("Has Cycle %d", hasCycle(n1));
    return 0;
}
