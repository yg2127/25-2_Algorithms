//
// Created by 유건 on 25. 10. 13..
//
#include <stdio.h>

int main() {
    int a, b, t;

    scanf("%d %d %d", &a, &b, &t);

    char ch;

    for (int i = 0; i < t && a < b; i++) {
        scanf(" %c", &ch); //문자열을 하나씩 읽어간다.

        int m = (a + b) / 2; // mid = a, b의 평균

        if (ch == 'Y') { //
            a = m + 1;  // k > m
        }
        else if (ch == 'N') {
            b = m;      // k ≤ m
        }
    }

    // 문제 조건상 입력이 정답에 맞게 주어지므로 최종 k는 a==b
    printf("%d\n", a);
    return 0;
}