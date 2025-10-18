//
// Created by 유건 on 25. 9. 15
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
int removeMax() {
    if (n == 0) return -1;
    int key = H[1];
    H[1] = H[n--];
    if (n > 0) downHeap(1);  // n이 0보다 클 때만 downHeap 호출
    return key;
}

void insertItem(int key){ // 삽입함수
    if(n >= 100) return;
    H[++n] = key;
    upHeap(n); // 인덱스 n의 부모노드 기준으로 힙 정렬
}
void printHeap(){ // 출력함수
    for(int i = 1; i <= n; i++){
        if(i > 1) printf(" ");
        printf("%d", H[i]); //
    }
    printf("\n");
}
int main() {
    char c;
    int data;

    while (scanf(" %c", &c) == 1) {  // 공백 문자 무시하고 입력받기
        if (c == 'i') {
            scanf("%d", &data);
            insertItem(data);
            printf("0\n");
        }
        else if (c == 'd') {
            int r = removeMax();
            printf("%d\n", r);
        }
        else if (c == 'p') {
            printHeap();
        }
        else if (c=='q') {
            break;
        }
    }

    return 0;
}