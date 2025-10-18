//
// Created by 유건 on 25. 10. 13..
//
#include <stdio.h>
#include <stdlib.h>

int rFE(const int *A, int l, int r, int k) {
    if (l > r)
        return r;  // 탐색구간이 비었을 때 그냥 반환

    int mid = (l + r) / 2; // 탐색구간을 중간점 middle을 기준으로 설정

    if (A[mid] == k) { // k를 찾은경우 곧바로 반환
        return mid;
    } else if (A[mid] > k) { // mid의 값이 k보다 크면 왼쪽만 탐색
        return rFE(A, l, mid - 1, k);
    } else { // mid의 값이 k보다 작으면 오른쪽 탐색
        return rFE(A, mid + 1, r, k);
    }
}

int findElement(const int *A, int n, int k) { // k값의 인덱스 반환 함수
    return rFE(A, 0, n - 1, k); // 인덱스 0부터 n-1까지에서 k값의 인덱스 출력
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);

    int *arr = (int*)malloc(n*sizeof(int));

    for (int i = 0; i < n; i++) { // 정렬된 배열 입력받은 후
        scanf("%d", &arr[i]);
    }

    printf("%d\n", findElement(arr, n, k));
}