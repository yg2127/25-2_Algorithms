//
// Created by ���� on 25. 9. 15..
//
#include <stdio.h>

#define MAXN 100

int H[MAXN + 1];  // 1-indexed
int n = 0;

void swap(int *a, int *b){ int t = *a; *a = *b; *b = t; }

void upHeap(int i){
    while(i > 1 && H[i] > H[i/2]){
        swap(&H[i], &H[i/2]);
        i /= 2;
    }
}

void downHeap(int i){
    while(2*i <= n){
        int j = 2*i;
        if(j + 1 <= n && H[j] < H[j+1]) j++;
        if(H[i] >= H[j]) break;
        swap(&H[i], &H[j]);
        i = j;
    }
}

void insertItem(int key){
    if(n == MAXN) return;           // ���� ���ǻ� ��ġ�� ����
    H[++n] = key;
    upHeap(n);
}

int removeMax(void){
    if(n == 0) return -1;           // ���� ������ ȣ����� ����
    int key = H[1];
    H[1] = H[n--];
    if(n) downHeap(1);
    return key;
}

void printHeap(void){
    for(int i = 1; i <= n; i++){
        if(i > 1) printf(" ");
        printf("%d", H[i]);
    }
    printf("\n");
}

int main(void){
    char cmd;
    while (scanf(" %c", &cmd) == 1){
        if(cmd == 'i'){
            int key; scanf("%d", &key);
            insertItem(key);
            printf("0\n");          // ���� ��� ���
        } else if(cmd == 'd'){
            int x = removeMax();
            printf("%d\n", x);      // ������ Ű ���
        } else if(cmd == 'p'){
            printHeap();            // ������(�迭��) ���
        } else if(cmd == 'q'){
            break;                  // ����
        }
    }
    return 0;
}