#include <stdio.h>
#include <stdlib.h>
#include "listUtil.h"

struct ListNode* createNode(int val) {
    struct ListNode* newNode = malloc(sizeof(struct ListNode));
    if (!newNode) {
        perror("malloc failed");
        exit(1);
    }
    newNode->val = val;
    newNode->next = NULL;
    return newNode;
}

void insertAtTail(struct ListNode** head, struct ListNode** tail, int val) {
    struct ListNode* newNode = createNode(val);

    if (*head == NULL) {
        *head = newNode;
        *tail = newNode;
    } else {
        (*tail)->next = newNode;
        *tail = newNode;
    }
}

struct ListNode* array2List(int arr[], int n) {
    struct ListNode* head = NULL;
    struct ListNode* tail = NULL;

    for (int i = 0; i < n; i++) {
        insertAtTail(&head, &tail, arr[i]);
    }

    return head;
}

void printList(struct ListNode* node) {
    while (node) {
        printf("%d ", node->val);
        node = node->next;
    }
    printf("\n");
}

