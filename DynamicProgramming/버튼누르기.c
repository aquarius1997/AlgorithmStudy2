//
//  버튼누르기.c
//  AJ
//
//  Created by 송혜경 on 08/10/2019.
//  Copyright © 2019 송혜경. All rights reserved.
//

#include <stdio.h>
#define MAXN(A, B)  (((A) > (B)) ? (A) : (B))

int main(void) {
    //rgb[i][0] : i초일때 빨강버튼값, rgb[i][1] : .. 초록버튼값, rgb[i][2] : ... 파란버튼값
    int rgb[100003][3] = {0, };
    //T[i][0] : i초에 빨간버튼을 선택했을 경우 최대값, [i][1] : ...초록 .. , [i][2] : .. 파랑 ..
    int T[100003][3] = {0, };
    int N, i;
    
    scanf("%d", &N);
    
    for(i=1; i<=N; i++) {
        scanf("%d %d %d", &rgb[i][0], &rgb[i][1], &rgb[i][2]);
    }
    
    //base-case
    T[1][0] = rgb[1][0];
    T[1][1] = rgb[1][1];
    T[1][2] = rgb[1][2];
    
    for(i=2; i<=N; i++) {
        T[i][0] = rgb[i][0] + MAXN(T[i-1][1], T[i-1][2]);
        T[i][1] = rgb[i][1] + MAXN(T[i-1][0], T[i-1][2]);
        T[i][2] = rgb[i][2] + MAXN(T[i-1][0], T[i-1][1]);
    }
    
    printf("%d", MAXN(T[N][0], (MAXN(T[N][1], T[N][2]))));
    
    return 0;
}
