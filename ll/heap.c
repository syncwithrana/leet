#include <stdio.h>

#define MAX_SIZE 100

typedef struct {
    int key;
    int val;
} HeapNode;

int heap_compare(HeapNode a, HeapNode b) {
    if (a.key < b.key) return 1;
    if (a.key > b.key) return -1;
    return 0;
}

void heap_swap(HeapNode *a, HeapNode *b) {
    HeapNode tmp = *a;
    *a = *b;
    *b = tmp;
}

void heap_print(HeapNode heap[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d:%d ", heap[i].key, heap[i].val);
    }
    printf("\n");
}

void heapify(HeapNode heap[], int n, int i) {
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n && heap_compare(heap[l], heap[largest]) > 0)
        largest = l;
    if (r < n && heap_compare(heap[r], heap[largest]) > 0)
        largest = r;

    if (largest != i) {
        heap_swap(&heap[i], &heap[largest]);
        heapify(heap, n, largest);
    }
}

void heap_build(HeapNode heap[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(heap, n, i);
}

void heap_bubble_up(HeapNode heap[], int i) {
    while (i > 0) {
        int parent = (i - 1) / 2;
        if (heap_compare(heap[parent], heap[i]) < 0) {
            heap_swap(&heap[parent], &heap[i]);
            i = parent;
        } else break;
    }
}

void heap_push(HeapNode heap[], int *n, int key, int val) {
    if (*n >= MAX_SIZE) {
        printf("Heap overflow!\n");
        return;
    }
    heap[*n].key = key;
    heap[*n].val = val;
    heap_bubble_up(heap, *n);
    (*n)++;
}

HeapNode heap_pop(HeapNode heap[], int *n) {
    HeapNode empty = { .key = -1, .val = -1 };
    if (*n <= 0) return empty;
    HeapNode root = heap[0];
    heap[0] = heap[--(*n)];
    heapify(heap, *n, 0);
    return root;
}

int main() {
    HeapNode heap[MAX_SIZE] = { {3,30}, {1,10}, {6,60}, {5,50}, {2,20}, {4,40} };
    int n = 6;

    heap_build(heap, n);
    printf("Initial heap: ");
    heap_print(heap, n);

    heap_push(heap, &n, 10, 100);
    printf("After push(10:100): ");
    heap_print(heap, n);

    HeapNode p = heap_pop(heap, &n);
    printf("Popped max: %d:%d\n", p.key, p.val);
    printf("After pop: ");
    heap_print(heap, n);

    return 0;
}