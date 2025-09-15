//
// Created by 유건 on 25. 9. 8..
//

#include<stdio.h>
#include<stdlib.h>

void swap(int A[], int i, int j) {int temp = A[i]; A[i] = A[j]; A[j] = temp;}

void insertionsort(int A[], int n) {
    for (int i = 0; i < n; i++) {
        int key = A[i]; // 정렬할 수 = key로 지정
        int j = i - 1; // j는 이전의 정렬된 배열을 훑기 시작
        while (j >= 0 && A[j] > key) { // 만약 A[j]가 key보다 크고 그리고 j >= 0 이라면
            A[j+1] = A[j]; // key보다 큰 원소들은 앞으로 한칸씩 이동
            j--;
        } // j == 0 이거나 A[j]가 key 보다 작다면? 해당 위치에 key 삽입되어야 함
        A[j+1] = key; // 삽입
    }
}

int main() {
    int n;
    scanf("%d", &n);

    int *arr = (int*)malloc(n*sizeof(int));

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    insertionsort(arr, n);

    for (int j = 0; j < n; j++) {
        printf("%d ", arr[j]);
    }
}