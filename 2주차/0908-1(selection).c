//
// Created by ���� on 25. 9. 8..
//
#include<stdio.h>
#include<stdlib.h>
void swap(int A[], int i, int j) {int temp = A[i]; A[i] = A[j]; A[j] = temp;}

int PicLarge(int A[], int l) { // 0 ~ l ���� ������ ���� ū ���� �ε��� ��ȯ �Լ�
    int max = A[0], maxi = 0;
    for (int i = 1; i <= l; i++){
        if (max < A[i]) {
            maxi = i;
            max = A[i];
        }
    };
    return maxi;
}
void selectionsort(int A[], int n) { // �ִ� n���� �Է��� ���� ��
    int lastin, largein; //������ �ε���, ���� ���� ū �ε���
    for (int i = 0; i < n; i++) {
        lastin = n - i - 1; // ���� �ȵ� �迭�� ������ �ε���
        largein = PicLarge(A, lastin); // 0~last_index ���� ������ ���� ū ���� �ε��� ��ȯ
        swap(A,largein, lastin); // ������ �ε����� ���� ū ���� �ε��� �ڸ���ü
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