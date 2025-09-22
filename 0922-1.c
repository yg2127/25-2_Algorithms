//
// Created by ���� on 25. 9. 22..
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
void buildHeap(){ // ��� �θ��� �ε��� i�� ���ؼ� DownHeap ����
    for (int i = n/2; i >= 1; --i) {
        downHeap(i);
    }
}
void insertItem(int key){ // �����Լ�
    if(n >= 100) return;
    H[++n] = key;
    upHeap(n); // �ε��� n�� �θ��� �������� �� ����
}

void inPlaceHeapSort(void){
    int originalN = n;
    buildHeap(); // ��� �θ��� �ε��� i�� ���ؼ� DownHeap ������ ��
    for (int i = n; i >= 2; --i){ // rootnode�� ������ ��� ���鿡 ���� �� ���� �������
        swap(&H[1], &H[i]); // ���� ū ��(root node)�� �� �ڷ� ����
        n = i - 1; // ���� ��ȿ ũ�⸦ i-1 �� ��� (���� �� �� ���� ���� ��� �ƴ�)
        downHeap(1); // ��Ʈ���� �� ���� �����ϰ� ��� ���鿡 ���� �� ���� �ݺ� ��
    }
    n = originalN; // ����� ���ؼ� n��(�迭 ũ��) ����
}

// �迭 ���� ���

void printArray(void){ // �迭 ���
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

