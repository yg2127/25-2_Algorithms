//
// Created by 유건 on 25. 10. 9..
//
// 제자리 최대 힙 성질 유지 삽입식 (한개씩)

#include<stdio.h>

int H[100];
int n = 0;

void swap(int *n1, int *n2) {
    int tmp = *n1;
    *n1 = *n2;
    *n2 = tmp;
}
/*
 * UpHeap에서 input 인자는 insertitem에서 추가된 원소로부터 시작된다.
 * 추가된 원소(n)와 그 부모원소(n/2)의 대소비교 및 힙순서 속성유지
 * 그 부모원소에 대해 재귀적으로 UpHeap 시행
 * 만약 root노드 시 수행 종료
 */
void UpHeap(int num) { // 부모가 더 커야함
    int parent = num/2;
    if (num == 1) return; // 만약 위치가 root_node까지 올라가면 탈출
    if (H[num] <= H[parent]) return; // 부모노드가 더 크거나 같으면 탈출
    swap(&H[num], &H[parent]); // 부모노드보다 자식노드가 더 클 경우 위치 변환
    UpHeap(num/2); // 그리고 부모노드에 대해 재귀적으로 시행 (root_node까지)
}
void insertitem(int data) { // 삽입 시
    H[++n] = data; // 최대노드에 대해 값 삽입
    UpHeap(n); // 힙순서 성질 유지
}


// 251010 - 현재 문제가 있음 oj 60점, 아무래도 DownHeap에서 문제 발생하나봄

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
void removemax() {
    swap(&H[1], &H[n]); // root_node와 맨 마지막 leaf_node와 교체 후
    n--; // 배열 1칸 줄이기
    DownHeap(1); //
}

void PrintHeap() {
    for (int i = 1; i <= n; i++) {
        printf(" %d", H[i]);
    }
    printf("\n");
}

int main() {
    char c;
    int d;

    while (1) {
        scanf(" %c", &c);
        if (c == 'i') {
            scanf("%d", &d);
            insertitem(d);
            printf("0\n");
        }
        else if (c == 'd') {
            printf("%d\n", H[1]);
            removemax();
        }
        else if (c == 'p') {
            PrintHeap();
        }
        else if (c == 'q') {
            printf("\n");
            break;
        }
        else continue;
    }
}

