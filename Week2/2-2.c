//
// Created by 유건 on 25. 10. 8..
//

#include<stdio.h>
#include<stdlib.h>
void swap(int *n1, int *n2) {
    int t = *n1;
    *n1 = *n2;
    *n2 = t;
}
void inplaceinsertionSort(int arr[], int n) { // 이해가 잘 안가는데??
    for (int i = 1; i < n; i++) {
        int s = arr[i];
        int j = i-1;
        while ((j>=0) && arr[j] > s) {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = s;
    }
}

int main() {
    int n;

    scanf("%d", &n);

    int *arr = malloc(n*sizeof(int));

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    inplaceinsertionSort(arr, n);

    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
}