//
// Created by ���� on 25. 9. 15
//
#include<stdio.h>
int H[101];
int n = 0;

void swap(int *a, int *b) { //�ڸ� �ٲٴ� �Լ�
    int temp = *a;
    *a = *b;
    *b = temp;
}

void upHeap(int i){ // �ڽĳ��� �θ����� �ڸ� �ٲ�
    while(i > 1 && H[i] > H[i/2]){ // �ڽĳ�尡 �θ��庸�� ũ�ٸ�?
        swap(&H[i], &H[i/2]);
        i /= 2; // �θ�, �ڽĳ����� ������� ��Һ񱳸� ���� ������ �Ӽ� ����!
    }
}

void downHeap(int i){ // �ڽĳ��� �θ� ����� �ڸ��ٲ�
    while(2*i <= n){ // �ڽ��� ���� ��
        int j = 2*i; // ���� �ڽ��� j�� ����
        if(j + 1 <= n && H[j] < H[j+1]) j++; // ������ �ڽ��� �� ũ�� j = ������
        if(H[i] >= H[j]) break; // �θ��尡 �� ũ�� break
        swap(&H[i], &H[j]); // �ڸ� ��ü
        i = j; // �ڽĳ�尡 �ٽ� ��������� �θ��尡 �ȴ�.
    }
}
int removeMax() {
    if (n == 0) return -1;
    int key = H[1];
    H[1] = H[n--];
    if (n > 0) downHeap(1);  // n�� 0���� Ŭ ���� downHeap ȣ��
    return key;
}

void insertItem(int key){ // �����Լ�
    if(n >= 100) return;
    H[++n] = key;
    upHeap(n); // �ε��� n�� �θ��� �������� �� ����
}
void printHeap(){ // ����Լ�
    for(int i = 1; i <= n; i++){
        if(i > 1) printf(" ");
        printf("%d", H[i]); //
    }
    printf("\n");
}
int main() {
    char c;
    int data;

    while (scanf(" %c", &c) == 1) {  // ���� ���� �����ϰ� �Է¹ޱ�
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