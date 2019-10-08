//
//  두문자열사이의거리.c
//  AJ
//
//  Created by 송혜경 on 08/10/2019.
//  Copyright © 2019 송혜경. All rights reserved.
//
#include <stdio.h>
#include <string.h>

int main(void){
    char A[1002];   char B[1002];
    int T[1002][1002] = {0, };
    int A_len, B_len;
    int i, j;
    
    scanf("%s", A);
    scanf("%s", B);
    
    A_len = strlen(A);
    B_len = strlen(B);
    
    T[0][0] = 0;
    for(j=1; j<=A_len; j++)
        T[0][j] = T[0][j-1] + 1;
    for(i=1; i<=B_len; i++)
        T[i][0] = T[i-1][0] + 1;
    
    for(i=1; i<=B_len; i++){
        for(j=1; j<=A_len; j++){
            if(A[j-1] != B[i-1]){
                if(T[i-1][j] > T[i][j-1])
                    T[i][j] = T[i][j-1] + 1;
                else
                    T[i][j] = T[i-1][j] + 1;
            }else{
                T[i][j] = T[i-1][j-1];
            }
        }
    }
    
    printf("%d", T[B_len][A_len]);
    
    return 0;
}
