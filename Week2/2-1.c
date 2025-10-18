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

void inplaceSelectionSort(int *arr, int n) { // 오름차순 제자리 삽입정렬
    for (int i = 0; i < n-1; i++) { // 마지막 이전 원소까지
        int min_i = i; // 최소값 원소 선언
        for (int j = i+1; j < n; j++) if (arr[j] < arr[min_i]) min_i = j; // i원소 이후로 작은 원소가 있다면 최소값 원소로 지정 후
        swap(&arr[i], &arr[min_i]); // i값과 최소값을 바꿈
    }
}

int main() {
    int n;

    scanf("%d", &n);

    int *arr = malloc(n*sizeof(int));

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    inplaceSelectionSort(arr, n);

    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
}

