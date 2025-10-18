//
// Created by 유건 on 25. 10. 15..
//

// 단일연결리스트에서 헤더는 더미노드값을 갖고 있어야만 한다!!

#include<stdio.h>
#include<stdlib.h>

typedef struct Node {
    struct Node *next;
    int data;
}Node;

Node *newNode (int data){
    Node *nn = (Node*)malloc(sizeof(Node));
    nn -> data = data, nn -> next = NULL;
    return nn;
}
Node *searchNode(Node* Head, int n) { // 입력받은 연결리스트 노드로부터 n번째 떨어져있는 노드 반환
    Node *curr = Head;
    for (int i = 0; i < n; i++) {
        curr = curr -> next;
    }
    return curr; // n = 2이면 노드는 3번째 노드부터 출력함
}

Node* partition(Node *L, int n) { // 입력받은 연결리스트 헤더에서 첫번째 부터 n번째까지 새 단일연결리스트 출력

    Node *Head = newNode(0);
    Node *curr = Head;

    for (int i = 0; i < n && L; i++) {
        curr -> next = newNode(L -> data);
        curr = curr -> next,L = L->next;
    }
    return Head -> next;
}

Node* Merge(Node *L1, Node *L2) { // 입력받은 두 리스트를 순차적으로 병합하는 알고리즘으로 newnode 함수를 통해 연결리스트 반환
    Node *Head = newNode(0), *curr = Head;
    while (L1 && L2) {
        if (L1 -> data <= L2 -> data) {curr -> next = newNode(L1->data); L1 = L1->next;}
        else {curr -> next = newNode(L2->data);L2 = L2->next;}
        curr = curr -> next;
    }
    while (L1) {curr -> next = newNode(L1->data);curr=curr->next;L1=L1->next;}
    while (L2) {curr -> next = newNode(L2->data);curr=curr->next;L2=L2->next;}
    return Head -> next;
}

Node* MergeSort(Node *L, int n) { // recurrently calling partition & Merge
    if (n<=1 || !L) return L;
    int mid = n/2;
    Node *L1, *L2;
    L1 = partition(L, mid);
    L2 = partition(searchNode(L, mid), n - mid);
    L1 = MergeSort(L1, mid);
    L2 = MergeSort(L2, n-mid);

    return Merge(L1, L2);
}

void printarr(Node *L) {
    while (L) {
        printf(" %d", L -> data);
        L=L->next;
    }
}

int main() {
    int n, data;
    Node *Head = newNode(0);
    Node *curr = Head;
    scanf("%d", &n);


    for (int i = 0; i < n; i++) {
        scanf("%d", &data);
        curr -> next = newNode(data);
        curr=curr->next;
    }

    printarr(MergeSort(Head -> next, n));
}