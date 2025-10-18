#include <stdio.h>
#include <stdlib.h>

void swap(int *x, int *y){    // 그냥 두 수 자리 바꾸는 함수
    int t=*x; *x=*y; *y=t;
}

int medianIndex(int *A, int i, int j, int k){   // 세 값 중에 중간값 인덱스 리턴
    int a=A[i], b=A[j], c=A[k];
    if(a < b){
        if(b < c) return j;    // a < b < c 구조면 b가 중간
        else if(a < c) return k;   // a < c <= b면 c가 중간
        else return i;   // 나머지는 a가 중간
    }else{
        if(a < c) return i;    // b <= a < c면 a가 중간
        else if(b < c) return k;   // b < c <= a면 c가 중간
        else return j;    // 나머지는 b가 중간
    }
}

int findPivot(int *A, int l, int r){   // 피벗 인덱스 뽑는 함수
    int m = l + (r - l)/2;   // 그냥 가운데 위치
    return medianIndex(A, l, m, r);   // 양끝+중간 중에 중간값 리턴
}

void inPlacePartition(int *A, int l, int r, int k, int *a_out, int *b_out){
    int pv = A[k];   // pivot 값
    int i = l, lt = l, gt = r;   // lt는 pivot보다 작은 구간 끝, gt는 pivot보다 큰 구간 시작
    while(i <= gt){   // i가 gt를 넘을 때까지 반복
        if(A[i] < pv){ swap(&A[i], &A[lt]); ++i; ++lt; }   // 작으면 앞으로 보내고 lt 증가
        else if(A[i] > pv){ swap(&A[i], &A[gt]); --gt; }   // 크면 뒤로 보내고 gt 줄임
        else{ ++i; }   // 같으면 그냥 넘어감
    }
    *a_out = lt;   // pivot이 시작되는 구간
    *b_out = gt;   // pivot이 끝나는 구간
}

void inPlaceQuickSort(int *A, int l, int r){   // 퀵정렬 본체
    if(l >= r) return;   // 구간 길이가 1 이하이면 끝
    int k = findPivot(A, l, r);   // 피벗 위치 찾음
    int a, b;
    inPlacePartition(A, l, r, k, &a, &b);   // 구간 나눔
    inPlaceQuickSort(A, l, a - 1);   // pivot보다 작은 쪽 재귀
    inPlaceQuickSort(A, b + 1, r);   // pivot보다 큰 쪽 재귀
}

int main(void){
    int n;
    if(scanf("%d", &n) != 1) return 0;   // n 못 읽으면 그냥 종료

    int *A = (int*)malloc(sizeof(int) * (size_t)n);   // 동적 배열 할당
    if(!A) return 0;   // 메모리 실패 시 종료

    for(int i=0;i<n;++i) scanf("%d", &A[i]);   // n개 입력 받기

    inPlaceQuickSort(A, 0, n-1);   // 퀵정렬 호출

    for(int i=0;i<n;++i){   // 정렬된 배열 출력
        if(i+1<n) printf("%d ", A[i]);   // 중간엔 공백
        else printf("%d\n", A[i]);   // 마지막은 개행
    }

    free(A);   // 동적 메모리 해제
    return 0;
}