#include "sll.h"
#include<stdio.h>
#include<stdlib.h>

int sllGet(struct ListNode* head, int index)   {
    struct ListNode* p = head;
    for(int i=0; i<index && p; i++) {
        p = p->next;
    }
    return p ? p->val : -1;
}

void sllAddAtHead(struct ListNode** head, int val) {
    struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
	newNode->val = val;
	newNode->next = *head;
	*head = newNode;
}

void sllAddAtTail(struct ListNode** head, int val) {
    struct ListNode** pp = head;
    while(*pp) {
        pp = &((*pp)->next);
    }
    *pp = (struct ListNode*)malloc(sizeof(struct ListNode));
    (*pp)->val = val;
    (*pp)->next = NULL;
}

void sllAddAtIndex(struct ListNode** head, int index, int val) {
    struct ListNode** pp = head;
    int i;
    for(i=0; i<index && *pp; i++) {
        pp = &((*pp)->next);
    }
    if(index == i)  {
        struct ListNode* next = *pp;
        *pp = (struct ListNode*)malloc(sizeof(struct ListNode));
        (*pp)->val = val;
        (*pp)->next = next;
    }
}

void sllDeleteAtIndex(struct ListNode** head, int index) {
    if(!*head) return;
    struct ListNode** pp = head;
    for(int i=0; i<index && *pp; i++) {
        pp = &((*pp)->next); 
    }
    if(*pp) {
        struct ListNode* tobedel = *pp;
        *pp = (*pp)->next;
        free(tobedel);
    }
}

void sllFree(struct ListNode** head) {
    struct ListNode** pp = head;
    while(*pp) {
        struct ListNode* tobedel = *pp;
        *pp = (*pp)->next;
        free(tobedel);
    }
}

struct ListNode* sllRemoveNthFromEnd(struct ListNode* head, int n) {
    struct ListNode* p1 = head;
    struct ListNode** p2 = &head;
    
    for(int i=0; i<n; i++)  {
        p1 = p1->next;
    }
    while(p1)   {
        p1 = p1->next;
        p2 = &((*p2)->next);
    }
    *p2 = (*p2)->next;
    return head;
}

struct ListNode* swapPairs(struct ListNode* head) {
    struct ListNode** pp = &head;
    while(*pp && (*pp)->next) {
        struct ListNode* next = (*pp)->next;
        (*pp)->next = (*pp)->next->next;
        next->next = *pp;
        *pp = next;
        pp = &((*pp)->next->next);
    }
    return head;
}

