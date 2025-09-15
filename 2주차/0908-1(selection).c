//
// Created by 유건 on 25. 9. 8..
//
#include<stdio.h>
#include<stdlib.h>
void swap(int A[], int i, int j) {int temp = A[i]; A[i] = A[j]; A[j] = temp;}

int PicLarge(int A[], int l) { // 0 ~ l 범위 내에서 가장 큰 수의 인덱스 반환 함수
    int max = A[0], maxi = 0;
    for (int i = 1; i <= l; i++){
        if (max < A[i]) {
            maxi = i;
            max = A[i];
        }
    };
    return maxi;
}
void selectionsort(int A[], int n) { // 최대 n개의 입력을 받을 때
    int lastin, largein; //마지막 인덱스, 수가 가장 큰 인덱스
    for (int i = 0; i < n; i++) {
        lastin = n - i - 1; // 정렬 안된 배열의 마지막 인덱스
        largein = PicLarge(A, lastin); // 0~last_index 범위 내에서 가장 큰 수의 인덱스 반환
        swap(A,largein, lastin); // 마지막 인덱스와 가장 큰 수의 인덱스 자리교체
    }
}


int main() {
    int n;
    scanf("%d", &n);

    int *arr = (int*)malloc(n*sizeof(int));

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    selectionsort(arr, n);

    for (int j = 0; j < n; j++) {
        printf("%d ", arr[j]);
    }
}