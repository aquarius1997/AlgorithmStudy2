//
//  문자열포함관계조사.c
//  AJ
//
//  Created by 송혜경 on 03/10/2019.
//  Copyright © 2019 송혜경. All rights reserved.
//

#include <stdio.h>
#include <string.h>

int main(void) {
    char A[1003]; char B[1003];
    int aLen, bLen;
    int flag;
    int i, j;
    
    scanf("%s", A);
    scanf("%s", B);
    
    aLen = strlen(A);
    bLen = strlen(B);
    
    for(i=0; i<aLen; i++) {
        //B의 첫번째 문자와 A의 문자가 동일한 부분부터 검증 시작
        if(A[i] == B[0]) {
            flag = 0;
            for(j=0; j<bLen; j++) {
                if(A[i+j] != B[j]) {
                    flag = 1; break;
                }
            }
            //문자열 마지막까지 루프를 못돌았는지 확인
            if(j != bLen)
                flag = 1;
            
            if(flag == 0) {
                printf("YES");  return 0;
            }
        }
    }
    
    printf("NO");
    return 0;
}
