#include<stdio.h>
#include<stdlib.h>
#include "sll.h"

MyLinkedList* myLinkedListCreate() {
    MyLinkedList* list = malloc(sizeof(MyLinkedList));
    list->head = NULL;
    return list;
}

void sllPrint(struct ListNode* p)   {
    while(p) {
        printf("%d..",p->val);
        p = p->next;
    }
    printf("\n");
}

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
    struct ListNode** pp = &head;
    while(*pp) {
        pp = &((*pp)->next);
    }
    *pp = (struct ListNode*)malloc(sizeof(struct ListNode));
    (*pp)->val = val;
    (*pp)->next = NULL;
}

void sllAddAtIndex(struct ListNode** head, int index, int val) {
    struct ListNode** pp = &head;
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

void sllDeleteAtIndex(MyLinkedList* obj, int index) {
    if(!obj->head) return;
    struct ListNode** pp = &(obj->head);
    for(int i=0; i<index && *pp; i++) {
        pp = &((*pp)->next); 
    }
    if(*pp) {
        struct ListNode* tobedel = *pp;
        *pp = (*pp)->next;
        free(tobedel);
    }
}

void sllFree(struct ListNode* head) {
    struct ListNode** pp = &head;
    while(*pp) {
        struct ListNode* tobedel = *pp;
        *pp = (*pp)->next;
        free(tobedel);
    }
}

int myLinkedListGet(MyLinkedList* obj, int index) {
    return sllGet(obj->head, index);
}

void myLinkedListAddAtHead(MyLinkedList* obj, int val) {
    sllAddAtHead(&(obj->head), val);
}

void myLinkedListAddAtTail(MyLinkedList* obj, int val) {
    sllAddAtTail(&(obj->head), val);
}

void myLinkedListAddAtIndex(MyLinkedList* obj, int index, int val) {
    sllAddAtIndex(&(obj->head), index, val);
}

void myLinkedListDeleteAtIndex(MyLinkedList* obj, int index) {
    sllDeleteAtIndex(&(obj->head), index);
}

void myLinkedListFree(MyLinkedList* obj) {
    sllFree(obj->head);
    free(obj);
}
