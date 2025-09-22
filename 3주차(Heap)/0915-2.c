// ���� 2: ����� �� ���� (max-heap)
#include <stdio.h>


int H[101];
int n = 0;                  // ���� Ű ����

void swap(int *a, int *b) { //�ڸ� �ٲٴ� �Լ�
    int temp = *a;
    *a = *b;
    *b = temp;
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

void buildHeap(){ // ��� �θ��� �ε��� i�� ���ؼ� DownHeap ����
    for (int i = n/2; i >= 1; --i) {
        downHeap(i);
    }
}

void printHeap(){ // ����Լ�
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

