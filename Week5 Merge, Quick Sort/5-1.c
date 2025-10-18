//
// Created by 유건 on 25. 10. 12..
//
#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    struct Node *next;
    int data;
}Node;

Node* newNode(int data) {
    Node *newnode = (Node*)malloc(sizeof(Node));
    newnode -> next = NULL;
    newnode -> data = data;
    return newnode;
}
void printL(Node *head) {
    Node *curr = head;
    while (1) {
        if (curr == NULL) break;
        printf(" %d", curr -> data);
        curr = curr->next;
    }
}
int isEmpty(Node *Head) {
    return (Head == NULL);
}
//=====================================
Node* divide_front(Node* Head, int n) {
    if (!Head) return NULL;
    Node* front_Head = Head;
    Node* curr = Head;
    for (int i = 1; i < n && curr->next; i++) {
        curr = curr->next;
    }
    if (curr) curr->next = NULL; // 앞부분 끝내기
    return front_Head;
}

Node* divide_behind(Node* Head, int n) {
    Node* curr = Head;
    for (int i = 0; i < n && curr; i++) {
        curr = curr->next;
    }
    return curr; // 뒷부분의 Head 반환
}
Node* Merge(Node* L1, Node* L2) {
    Node* result = NULL;
    Node* curr = NULL;
    while (L1 != NULL || L2 != NULL) {
        int val;
        if (L1 != NULL && (L2 == NULL || L1->data <= L2->data)) {
            val = L1->data;
            L1 = L1->next;
        } else {
            val = L2->data;
            L2 = L2->next;
        }
        Node* new_node = newNode(val);
        if (result == NULL) {
            result = new_node;
            curr = new_node;
        } else {
            curr->next = new_node;
            curr = curr->next;
        }
    }
    return result;
}

Node *Mergesort(Node *Head, int n) {
    if (n ==1) return Head;
    Node* result;
    Node* front = divide_front(Head, n/2);
    Node* behind = divide_behind(Head, n/2);
    return result = Merge(front, behind);
}

int main() {
    int n, data;
    scanf("%d", &n);
    Node *Head = NULL;
    for (int i = 0; i < n; i++) {
        scanf("%d", &data);
        if (Head == NULL) Head = newNode(data);
        else Head -> next = newNode(data);
    }

    printL(Mergesort(Head, n));
}