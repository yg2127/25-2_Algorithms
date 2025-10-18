//
// Created by 유건 on 25. 10. 10..
//
#include<stdio.h>
#include<stdlib.h>

int H[100];
int n = 0;

void swap(int *n1, int *n2) {
    int tmp = *n1;
    *n1 = *n2;
    *n2 = tmp;
}

void DownHeap(int num) { // 노드 x에 대해
    int right = num*2+1; // x의 오른쪽 자식노드
    int left = num*2; // x의 왼쪽 자식노드
    if (left > n) return; // 왼쪽 자식노드가 없다면 탈출
    int big = left; // 큰 노드를 왼쪽으로 설정 후
    if (right <= n) { // 오른쪽 노드가 있을 때
        if (H[right] > H[big]) { // 큰 노드가
            big = right;
        }
    }
    if (H[num] >= H[big]) return; // 큰 자식노드가 부모노드보다 작으면 탈출
    swap(&H[num], &H[big]); // 부모노드보다 크다면 교체
    DownHeap(big); // 자식노드에 대해 재귀적으로 DownHeap 시행
}

void rBuildHeap(int i) {
    if (i > n) return;
    rBuildHeap(i*2); // 왼쪽 자식노드에 대해 재귀적으로 실행
    rBuildHeap(i*2+1); // 오른쪽 자식노드에 대해 재귀적으로 실행
    DownHeap(i); // 그리고 나서 부모노드에 대해 DownHeap 시행
}

void PrintHeap() {
    for (int i = 1; i <= n; i++) {
        printf(" %d", H[i]);
    }
    printf("\n");
}

int main() {
    int num;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &H[i]);
    }
    rBuildHeap(1);
    PrintHeap();
    return 0;
}