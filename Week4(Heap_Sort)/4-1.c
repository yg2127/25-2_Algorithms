//
// Created by 유건 on 25. 10. 12..
//
#include<stdio.h>

/*
 * 상향식 힙(rbuildHeap)을 통해 힙정렬 수행 고고
 * 상향식 힙은 최말단 부모노드부터 힙순서 성질을 만족시킨 후
 * 2기 연산 을 통해 root_node를 최말단 노드(n)와 swap한 후 n값을 조작하여 n-1로 변경 후 DownHeap(1)을 수행한다.
 */

int H[100];
int n;

void swap(int *n1, int *n2) {
    int tmp = *n1;
    *n1 = *n2;
    *n2 = tmp;
}

void DownHeap(int b) {
    int right = 2 * b + 1;
    int left = 2 * b;

    if (left > n) return;
    int big = left;
    if (right <= n) {
        if (H[right] > H[big]) big = right;
    }
    if (H[b] >= H[big]) return;
    swap(&H[b], &H[big]);
    DownHeap(big);
}

void rBuildHeap(int a) {
    if (a > n) return;
    rBuildHeap(a * 2);
    rBuildHeap(a*2+1);
    DownHeap(a);
}

void inplaceHeapSort() {
    int original_n = n;
    for (int i = n; i >= 2; i--) {
        swap(&H[1],&H[i]);
        n--;
        DownHeap(1);
    }
    n = original_n;
}
void printarr() {
    for (int i = 1; i <= n; i++) {
        printf(" %d", H[i]);
    }
}

int main() {

    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        scanf("%d", &H[i]);
    }

    rBuildHeap(1); // 상향식 힙 생성 (1기)

    inplaceHeapSort();

    printarr();

}

