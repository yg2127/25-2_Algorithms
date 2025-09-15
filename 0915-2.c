// 문제 2: 상향식 힙 생성 (max-heap)
#include <stdio.h>


int H[101];
int n = 0;                  // 현재 키 개수

void swap(int *a, int *b) { //자리 바꾸는 함수
    int temp = *a;
    *a = *b;
    *b = temp;
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

void printHeap(){ // 출력함수
    for(int i = 1; i <= n; i++){
        if(i > 1) printf(" ");
        printf("%d", H[i]); //
    }
    printf("\n");
}

int main(void){
    scanf("%d", &n);

    for (int i = 1; i <= n; ++i) {
        scanf("%d", &H[i]);
    }

    buildHeap();
    printHeap();
    return 0;
}

