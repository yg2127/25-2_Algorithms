//
// Created by ���� on 25. 9. 8..
//

#include <stdio.h>
#include<stdlib.h>
#include <time.h>

void swap(int A[], int i, int j) {int temp = A[i]; A[i] = A[j]; A[j] = temp;}

//==============insertion========================
void insertionsort(int A[], int n) {
    for (int i = 0; i < n; i++) {
        int key = A[i];
        int j = i - 1;
        while (j >= 0 && A[j] > key) {
            A[j+1] = A[j];
            j--;
        }
        A[j+1] = key;
    }
}
//=============selection=========================

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
        lastin = n - i - 1;
        largein = PicLarge(A, lastin);
        swap(A,largein, lastin);
    }
}

//=============main==============================
int main() {
    int n;
    if (scanf("%d", &n) != 1 || n <= 0) return 0;

    int *A = (int*)malloc(n * sizeof(int));
    int *B = (int*)malloc(n * sizeof(int));
    if (!A || !B) return 1;

    srand((unsigned)time(NULL));
    for (int i = 0; i < n; i++) {
        long r = (((long)rand() << 15) | rand());
        int val = (int)(r % 1000000) + 1; // 1~1,000,000
        A[i] = val;
        B[i] = val; // ���� �����ͷ� ��
    }

    clock_t start, end;

    start = clock();
    selectionsort(A, n);
    end = clock();
    double sel_ms = (double)(end - start) * 1000.0 / CLOCKS_PER_SEC;

    start = clock();
    insertionsort(B, n);
    end = clock();
    double ins_ms = (double)(end - start) * 1000.0 / CLOCKS_PER_SEC;

    printf("%.9fms\n", sel_ms);
    printf("%.9fms\n", ins_ms);

    free(A);
    free(B);
    return 0;
}