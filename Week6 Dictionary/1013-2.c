//
// Created by 유건 on 25. 10. 13..
//
#include <stdio.h>
#include <stdlib.h>

int lower_bound_index(const int *A, int n, int k) {
    int l = 0, r = n - 1, ans = n; // 기본값 n (없을 때 규칙)
    while (l <= r) { // A[mid] =
        int mid = l + (r - l) / 2; // 중간 인덱스 계산하기
        if (A[mid] >= k) {      // 후보 갱신, 더 왼쪽 탐색
            ans = mid;          //
            r = mid - 1;        // 배열의 가장 오른쪽 인덱스는 중간 바로 왼쪽으로 국한하여 l,r 구간을 조정한다.
        } else {                // A[mid] < k → 오른쪽 탐색
            l = mid + 1;        // l을 중간 오른쪽으로 선언하여 구간을 조정함
        }
    }
    return ans;
}

int main(void) {
    int n, k;
    scanf("%d %d", &n, &k);
    int *A = (int*)malloc(sizeof(int) * n); // 동적할당
    for (int i = 0; i < n; i++) scanf("%d", &A[i]); // 배열 입력받음

    int idx = lower_bound_index(A, n, k); // 비재귀 이진탐색
    printf("%d\n", idx);

    free(A);
    return 0;
}