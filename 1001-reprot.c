#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// swap: 두 정수 교환
void swap(int *a, int *b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

// writeList: 리스트 출력
void writeList(int *L, int n){
    for(int i=0;i<n;i++){
        printf("%d ", L[i]);
    }
    printf("\n");
}

// buildList: 랜덤 리스트 생성
int* buildList(int n, int minv, int maxv){
    int *L = (int*)malloc(sizeof(int)*n);
    for(int i=0;i<n;i++) L[i] = minv + rand()%(maxv-minv+1);
    return L;
}

int findKthSmallest(const int *L, int n, int k){

    int *H = (int*)malloc(sizeof(int)*n); // 새로운 힙구조의 배열은 n개 크기의 배열
    for(int i=0;i<n;i++) H[i] = L[i]; // 기존 배열과 새로운 힙구조 배열을 똑같게 만듬

    for(int i=(n-2)/2; i>=0; --i) { // 부모 노드들을 대상으로 최소힙 성질 유지시키기
        int idx = i; // while을 통한 반복문이므로 i값을 변수에 저장한다.
        while(1){
            int l = 2*idx+1, r = 2*idx+2, m = idx; // left는 왼쪽 자식노드, right는 오른쪽 자식노드, mother는 현재의 인덱스 i를 의미
            if(l<n && H[l]<H[m]) m = l; // 만약 부모노드가 왼쪽 자식노드보다 작다면 m = l
            if(r<n && H[r]<H[m]) m = r; // 만약 부모노드가 오른쪽 자식노드보다 작다면 m = r
            if(m==idx) break; // 만약 부모노드가 가장 작다면 해당 노드 i에 대해 break한다.
            swap(&H[idx], &H[m]); // swap함수를 통해 부모노드값과 자식노드값을 바꾼다.
            idx = m; // 작은 자식노드 m에 대해 재귀적으로 최소힙 성질을 유지시킨다.
        }
    }

    int heap_size = n; // heap_size를 선언한 후 heap_size를 힙 H의 최대 크기로 선언한다.
    for(int t=1; t<k; ++t){ // k-1번 최소값을 제거해서 k번째로 작은 노드값을 출력한다.
        swap(&H[0], &H[heap_size-1]); // 가장 작은 값 (root노드)와 마지막 leaf node값을 교체한다.
        heap_size--; // heap_size를 줄여서
        int idx = 0; // root node부터 최소힙 성질 유지하기
        while(1){ // 위와 똑같이 반복문을 통해 루트노드에 대해 최소힙 성질 유지
            int l = 2*idx+1, r = 2*idx+2, m = idx; // left는 왼쪽 노드, right는 오른쪽 노드, m 은 현재 노드
            if(l<heap_size && H[l]<H[m]) m = l; // 왼쪽 노드값이 부모 노드값보다 작으면 m = l
            if(r<heap_size && H[r]<H[m]) m = r; // 오른쪽 노드값이 부모 노드값보다 작으면 m = r
            if(m==idx) break; // 부모노드값이 가장 작으면 반복문 탈출
            swap(&H[idx], &H[m]); // 더 작은 자식노드 m과 부모노드 idx값 교체
            idx = m; // while문을 통해 m에 대해 재귀적으로 최소힙 성질 유지
        }
    }

    int ans = H[0]; // k번째로 작은 수가 root node에 위치하므로 정답 = H[0] (root node)
    free(H);
    return ans; // 정답 값 반환
}

/* ------------------------- main ------------------------- */
int main(void){
    srand((unsigned)time(NULL)); // 난수 발생기 시드값을 결정하는 함수, time 함수에 따라 seed가 결정되므로 계속 다른 시드값이 들어가서 rand함수가 무작위의 값을 출력함

    clock_t st, ed; // cpu시간 측정시 사용하는 정수 타입
    double elapsed; // 소수점 6자리까지 연산 시간 저장

    int *L = buildList(10, 1, 100);
    writeList(L, 10);
    printf("%d %d %d\n",
           findKthSmallest(L, 10, 1),
           findKthSmallest(L, 10, 2),
           findKthSmallest(L, 10, 3));
    free(L);

    int n = 100000;
    L = buildList(n, 1, 1000000);
    int ks[4] = {1, 100, 99900, 99999};
    for(int i=0;i<4;i++){ // ks 배열 원소 4개에 대해서 반복문
        st = clock(); // 시작 시점의 cpu시간 저장
        int val = findKthSmallest(L, n, ks[i]);
        ed = clock(); // 끝 시점의 cpu시간 저장
        elapsed = (double)(ed - st)/CLOCKS_PER_SEC; // 시작, 종료 cpu시간을 초 당 cpu시간으로 나눠서 몇 초가 걸렸는지 알려주는 변수
        printf("%d %.6f\n", val, elapsed);
    }
    free(L);

    return 0;
}
