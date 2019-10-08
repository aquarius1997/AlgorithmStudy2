//
//  연속부분최대합3.c
//  AJ
//
//  Created by 송혜경 on 08/10/2019.
//  Copyright © 2019 송혜경. All rights reserved.
//
/*
 완전탐색 : O(n*n)
 분할정복법 : O(n*log(n))
 DP : O(n)
 
 각각의 숫자가 오른쪽 끝 일 경우 최대값을 모두 구하고, 그중에서 가장 최댓값을 구하면 된다
 
 (1, 2, -4, 5, 3, -2, 9, 10) 이라고 할때,
  1  3  -1  5  8   6  15 25 -> 25 이다
 
 */
#include <stdio.h>

int main(void) {
    //T[i] : i번째 숫자를 오른쪽 끝으로 하는 연속 부분 최대합
    int T[100];
    int data[100];
    int n;
    int max = -987987987;
    int i;
    
    scanf("%d", &n);
    
    for(i=0; i<n; i++) {
        scanf("%d", &data[i]);
    }
    
    //base-case
    T[0] = data[0];
    
    for(i=1; i<n; i++) {
        if(T[i-1] + data[i] > data[i]) {
            T[i] = T[i-1] + data[i];
        }else {
            T[i] = data[i];
        }
    }
    
    for(i=0; i<n; i++) {
        if(T[i] > max)
            max = T[i];
    }
    
    printf("%d", max);
    
    return 0;
}
