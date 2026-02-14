struct ListNode {
    int val;
    struct ListNode* next;
};

struct ListNode* createNode(int val);
void insertAtTail(struct ListNode** head, struct ListNode** tail, int val);
struct ListNode* array2List(int arr[], int n);
void printList(struct ListNode* node);