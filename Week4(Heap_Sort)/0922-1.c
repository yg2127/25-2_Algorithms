//
// Created by 유건 on 25. 9. 22..
//
#include<stdio.h>

int H[101];
int n = 0;

void swap(int *a, int *b) { //자리 바꾸는 함수
    int temp = *a;
    *a = *b;
    *b = temp;
}

void upHeap(int i){ // 자식노드와 부모노드의 자리 바꿈
    while(i > 1 && H[i] > H[i/2]){ // 자식노드가 부모노드보다 크다면?
        swap(&H[i], &H[i/2]);
        i /= 2; // 부모, 자식노드들의 재귀적인 대소비교를 통해 힙순서 속성 유지!
    }
}
void downHeap(int i){ // 자식노드와 부모 노드의 자리바꿈
    while(2*i <= n){ // 자식이 있을 때
        int j = 2*i; // 왼쪽 자식을 j로 선언
        if(j + 1 <= n && H[j] < H[j+1]) j++; // 오른쪽 자식이 더 크면 j = 오른쪽
        if(H[i] >= H[j]) break; // 부모노드가 더 크면 break
        swap(&H[i], &H[j]); // 자리 교체
        i = j; // 자식노드가 다시 재귀적으로 부모노드가 된다.
    }
}
void buildHeap(){ // 모든 부모노드 인덱스 i에 대해서 DownHeap 구현
    for (int i = n/2; i >= 1; --i) {
        downHeap(i);
    }
}
void insertItem(int key){ // 삽입함수
    if(n >= 100) return;
    H[++n] = key;
    upHeap(n); // 인덱스 n의 부모노드 기준으로 힙 정렬
}

void inPlaceHeapSort(void){
    int originalN = n;
    buildHeap(); // 모든 부모노드 인덱스 i에 대해서 DownHeap 구현한 후
    for (int i = n; i >= 2; --i){ // rootnode를 제외한 모든 노드들에 대해 맨 뒤의 노드들부터
        swap(&H[1], &H[i]); // 가장 큰 값(root node)를 맨 뒤로 보냄
        n = i - 1; // 힙의 유효 크기를 i-1 로 축소 (이제 맨 뒤 노드는 정렬 대상 아님)
        downHeap(1); // 루트에서 힙 성질 복구하고 모든 노드들에 대해 위 과정 반복 후
    }
    n = originalN; // 출력을 위해서 n값(배열 크기) 복구
}

// 배열 내용 출력

void printArray(void){ // 배열 출력
    for (int i = 1; i <= n; ++i){
        printf("%d ", H[i]);
    }
    printf("\n");
}

int main() {
    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        scanf("%d", &H[i]);
    }

    inPlaceHeapSort();
    printArray();

    return 0;
}

