//
//  자원채취.c
//  AJ
//
//  Created by 송혜경 on 08/10/2019.
//  Copyright © 2019 송혜경. All rights reserved.
//
#include <stdio.h>
#define MAX(a, b)   (((a)>(b)) ? a : b)

const int max = 1001;

int main(void){
    int arr[max][max] = {0, };
    //T[i][j] : 출발지점부터 i행j열까지의 최대 자원 채취 양
    int T[max][max] = {0, };
    int N, M;
    int i, j;
    
    scanf("%d %d", &N, &M);
    
    for(i=0; i<N; i++)
        for(j=0; j<M; j++)
            scanf("%d", &arr[i][j]);
    
    T[0][0] = arr[0][0];
    
    //0행 먼저 수행
    for(j=1; j<M; j++)
        T[0][j] = T[0][j-1] + arr[0][j];
    
    //0열 수행
    for(i=1; i<N; i++)
        T[i][0] = T[i-1][0] + arr[i][0];
    
    for(i=1; i<N; i++){
        for(j=1; j<M; j++){
            T[i][j] = arr[i][j] + MAX(T[i-1][j], T[i][j-1]);
        }
    }
    
    printf("%d", T[N-1][M-1]);
    return 0;
}
