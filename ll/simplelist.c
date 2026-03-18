#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct ListNode	{
    int val;
    struct ListNode *next;
};

void insertAtHead(struct ListNode** head, int data)	{
	struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
	newNode->val = data;
	newNode->next = *head;
	*head = newNode;
}

void removeElement(struct ListNode** head, int val) {
    struct ListNode** pp = head;
    while(*pp)  {
        if((*pp)->val == val)  {
            struct ListNode* to_del = *pp;
            *pp = (*pp)->next;
            free(to_del);
            break;
        }
        else {
            pp = &((*pp)->next);
        }
    }
}

bool listContains(struct ListNode* p, int data)	{
	bool exists = false;
	while(p)	{
		if(p->val == data)	{
			exists = true;
			break;
		}
		p = p->next;
	}
	return exists;
}

void printList(struct ListNode* node)	{
	while(node != NULL)	{
		printf("%d", node->val);
		node = node->next;
	}
	printf("\n");
}

int main()	{
	struct ListNode* head = NULL;
	insertAtHead(&head, 0);
	insertAtHead(&head, 1);
	insertAtHead(&head, 2);
	insertAtHead(&head, 3);
	printf("%d is existing: %d",1, listContains(head, 1));
	printf("%d is existing: %d",9, listContains(head, 9));
	printList(head);
	removeElement(&head, 3);
	printList(head);
	removeElement(&head, 1);
	printList(head);
	removeElement(&head, 5);
	printList(head);
}
