//
// Created by À¯°Ç on 25. 9. 15
//
#include<stdio.h>

int n = 0;
int arr[101];
void swap(int a, int b) {
    int tmp = arr[a];
    arr[a] = arr[b];
    arr[b] = tmp;
}

void upHeap(int i) {
    while (i != 1) {
        if (arr[i] > arr[i/2]) swap(i, i/2);
        i /= 2;
    }
}

void downHeap(int i) {

}
void insertItem(int key) {

}
int removeMax() {
    int key = arr[1];
    arr[1] = arr[n];
    n--;

    return key;
}
void printHeap() {
    for (int i = 1; i <=n; i++) {
        printf(" %d", arr[i]);
    }
}
int main() {
    char c;
    while (1) {
        scanf("%c", &c);

        if (c == 'i') {

        }
        else if (c == 'q') {
            break;
        }
    }
}