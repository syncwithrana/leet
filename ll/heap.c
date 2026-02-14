#include <stdio.h>

#define MAX_SIZE 100


void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int compare(int a, int b) {
    if (a > b) return 1;
    if (a < b) return -1;
    return 0;
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void heapify(int arr[], int n, int i) {
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n && compare(arr[l], arr[largest]) > 0)
        largest = l;
    if (r < n && compare(arr[r], arr[largest]) > 0)
        largest = r;

    if (largest != i) {
        swap(&arr[i], &arr[largest]);
        heapify(arr, n, largest);
    }
}

void buildHeap(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);
}

void bubbleUp(int arr[], int i) {
    while (i > 0) {
        int parent = (i - 1) / 2;
        if (compare(arr[parent], arr[i]) < 0) {
            swap(&arr[parent], &arr[i]);
            i = parent;
        } else break;
    }
}

void push(int arr[], int *n, int val) {
    if (*n >= MAX_SIZE) {
        printf("Heap overflow!\n");
        return;
    }
    arr[*n] = val;
    bubbleUp(arr, *n);
    (*n)++;
}

int pop(int arr[], int *n) {
    if (*n <= 0) return -1;
    int root = arr[0];
    arr[0] = arr[--(*n)];
    heapify(arr, *n, 0);
    return root;
}

int main() {
    int arr[MAX_SIZE] = {3, 1, 6, 5, 2, 4};
    int n = 6;

    buildHeap(arr, n);
    printf("Initial heap: ");
    printArray(arr, n);

    push(arr, &n, 10);
    printf("After push(10): ");
    printArray(arr, n);

    printf("Popped max: %d\n", pop(arr, &n));
    printf("After pop: ");
    printArray(arr, n);

    return 0;
}