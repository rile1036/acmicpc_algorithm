#include <stdio.h>
#include <iostream>
typedef int count;
typedef struct Heapsort {
    count heap[100001];
    int size;
}
Heapsort;
count value(count data) {
    if (data < 0)
    {
        return -data;
    }
    return data;
}
void init(Heapsort *h) {
   h->size = 0;
    return;
}

int is_empty(Heapsort *h) {
    return (h->size == 0);
}

void insert(Heapsort *h, count data) {
   int i;
    i = ++(h->size);
    while (i != 1 && ((value(h->heap[i / 2])>value(data)) || ((value(h->heap[i/2]) == value(data)) && (h->heap[i/2] > data))))
    {
            h->heap[i] = h->heap[i / 2];
            i = i / 2;
    }
    h->heap[i] = data;
    return;
} 

int remove(Heapsort *h) {
    int left, center, tmp, min;
    min = h->heap[1];
    tmp = h->heap[h->size--];
    center = 1;
    left = 2;
    while (left <= h->size) {
        if (left<h->size && ((value(h->heap[left]) == value(h->heap[left+1]) && h->heap[left] > h->heap[left+1]) || (value(h->heap[left])>value(h->heap[left + 1]))))
            left++; 

        if ((value(tmp)<value(h->heap[left])) || ((value(tmp) == value(h->heap[left])) && (tmp < h->heap[left])))
            break;

        h->heap[center] = h->heap[left];
        center = left;
        left *= 2;
    }
    h->heap[center] = tmp;
    return min;
}

int main() {
    int i, x, num;
    int answer[100001];
    long long result = 0;
    Heapsort heap;
    init(&heap);
    scanf("%d", &x);

    for (i = 0; i<x; i++) {
        scanf("%d", &num);
        if (num == 0) {
            if (heap.size == 0) {
                printf("%d\n", 0);
            }
            else {
                printf("%d\n", remove(&heap));
            }
        }
        else {
            insert(&heap, num);
        }
    }
    return 0;
}

