// Iterative (bottom-up) MergeSort for Singly Linked List
// gcc -O2 -std=c11 -Wall -Wextra -o mergesort_ll_iter mergesort_ll_iter.c
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int key;
    struct Node *next;
} Node;

/* 리스트 뒤에 새 노드 추가하기 */
void push_back(Node **head, Node **tail, int x){
    Node *nd = (Node*)malloc(sizeof(Node));
    nd->key = x; nd->next = NULL;
    if(*tail){ (*tail)->next = nd; *tail = nd; }
    else { *head = *tail = nd; }
}

/* 리스트 길이 세기 */
int length(Node *p){ int n=0; while(p){ ++n; p=p->next; } return n; }

/* 리스트를 앞에서 s개 잘라서 반환.
   - 원래 리스트는 s개까지만 남기고 끊어줌
   - 잘린 나머지 부분의 시작 노드를 리턴 */
Node* split(Node *head, int s){
    while(--s && head) head = head->next;
    if(!head) return NULL;
    Node *rest = head->next;
    head->next = NULL;       // 여기서 리스트를 딱 끊어버림
    return rest;
}

/* 두 개의 정렬된 리스트 a, b를 합쳐서 하나로 만든다.
   - 결과는 head 리턴
   - tail_out에는 마지막 노드 주소를 넣어줌 (다음 연결할 때 쓰려고) */
Node* merge_two(Node *a, Node *b, Node **tail_out){
    Node dummy = {0, NULL};
    Node *t = &dummy;
    while(a && b){
        if(a->key <= b->key){ t->next = a; a = a->next; }
        else { t->next = b; b = b->next; }
        t = t->next;
    }
    // 남은 거 그냥 이어 붙임
    t->next = (a ? a : b);
    // 끝까지 가서 tail 위치 찾기
    while(t->next) t = t->next;
    *tail_out = t;
    return dummy.next;
}

/* bottom-up 방식의 merge sort
   - 길이 1짜리 조각부터 시작해서 2, 4, 8…씩 늘려가며 합침 */
Node* mergeSort_iter(Node *head){
    if(!head || !head->next) return head; // 노드가 0개 or 1개면 그대로 리턴
    int n = length(head);
    Node dummy = {0, head};

    // s는 구간 크기. 1부터 시작해서 두 배씩 키움
    for(int s = 1; s < n; s <<= 1){
        Node *prev = &dummy;      // 합친 결과를 이어붙이는 포인터
        Node *cur  = dummy.next;  // 아직 안 처리한 구간의 시작

        while(cur){
            Node *left  = cur;                // 왼쪽 구간 시작
            Node *right = split(left, s);     // s개 자르고 오른쪽 구간 시작 찾기
            cur = split(right, s);            // 오른쪽도 s개 잘라서 다음 구간 시작

            // 두 구간 합치기
            Node *merged_tail = NULL;
            Node *merged_head = merge_two(left, right, &merged_tail);

            // 합친 걸 전체 결과에 이어 붙이기
            prev->next = merged_head;
            prev = merged_tail;
        }
        prev->next = NULL;        // 혹시 꼬리 이어짐 방지
    }
    return dummy.next;
}

/* 리스트 출력 (마지막 원소 뒤에는 공백 없이 개행만) */
void print_list(Node *L){
    for(Node *p=L; p; p=p->next){
        if(p->next) printf("%d ", p->key);
        else printf("%d\n", p->key);
    }
}

/* 메모리 해제 */
void free_list(Node *L){ while(L){ Node* t=L; L=L->next; free(t);} }

int main(void){
    int n;
    if(scanf("%d", &n) != 1) return 0;
    Node *head=NULL, *tail=NULL;
    for(int i=0;i<n;++i){ int x; scanf("%d",&x); push_back(&head,&tail,x); }
    head = mergeSort_iter(head);
    print_list(head);
    free_list(head);
    return 0;
}