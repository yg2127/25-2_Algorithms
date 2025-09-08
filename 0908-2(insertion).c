//
// Created by ���� on 25. 9. 8..
//

#include<stdio.h>
#include<stdlib.h>

void swap(int A[], int i, int j) {int temp = A[i]; A[i] = A[j]; A[j] = temp;}

void insertionsort(int A[], int n) {
    for (int i = 0; i < n; i++) {
        int key = A[i]; // ������ �� = key�� ����
        int j = i - 1; // j�� ������ ���ĵ� �迭�� �ȱ� ����
        while (j >= 0 && A[j] > key) { // ���� A[j]�� key���� ũ�� �׸��� j >= 0 �̶��
            A[j+1] = A[j]; // key���� ū ���ҵ��� ������ ��ĭ�� �̵�
            j--;
        } // j == 0 �̰ų� A[j]�� key ���� �۴ٸ�? �ش� ��ġ�� key ���ԵǾ�� ��
        A[j+1] = key; // ����
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