//
// Created by À¯°Ç on 25. 10. 12..
//
#include<stdio.h>
#include<stdlib.h>

void swap(int *n1, int *n2) {
    int tmp = *n1;
    *n1 = *n2;
    *n2 = tmp;
}

void printarr(int H[], int n) {
    for (int i = 0; i < n; i++) {
        printf(" %d", H[i]);
    }
    printf("\n");
}

int findpivot(int *arr, int l, int r) {
    int i = arr[l], j = arr[r], k = arr[(l+r)/2];
    if ((i <= j && j <= k)||(k <= j && j <= i)) return r;
    else if ((j <= i && i <= k) || (k <= i && i <= j)) return l;
    else return (l+r)/2;
}

void inplacepartition(int *arr, int l, int r, int pivot) {
    int i = l, j = r;
    while (1) {
        while (arr[i] <= arr[pivot] && i <= pivot) i++;
        while (arr[j] >= arr[pivot] && j >= pivot) j--;
        if (i > j) break;
        swap(&arr[i], &arr[j]);
    }
    swap(&arr[j], &arr[pivot]);
}

void QuickSort(int arr[], int l, int r) {
    if (l >= r) return;
    int pivot = findpivot(arr, l, r);

    inplacepartition(arr, l, r, pivot);

    QuickSort(arr, l, pivot-1);
    QuickSort(arr, pivot+1, r);
}

int main() {
    int n;
    scanf("%d", &n);
    int *arr = (int*)malloc(n*sizeof(int));

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    QuickSort(arr, 1, n);

    printarr(arr, n);

}