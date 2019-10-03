//
//  큰자릿수곱셈.c
//  AJ
//
//  Created by 송혜경 on 03/10/2019.
//  Copyright © 2019 송혜경. All rights reserved.
//
#include <stdio.h>
#include <string.h>

int main(void) {
    char inputStr[1000000];
    int A[1000000]; int B[1000000]; int result[1000000] = {0, };
    int aLen, bLen; int idx=0;  int c;
    int temp, tempSum;  int sum=0;
    int i, j;
    
    scanf("%s", inputStr);
    aLen = strlen(inputStr);
    for(i=0; i<aLen; i++) {
        A[i] = inputStr[i] - '0';
    }
    
    scanf("%s", inputStr);
    bLen = strlen(inputStr);
    for(i=0; i<bLen; i++) {
        B[i] = inputStr[i] - '0';
    }
    
    //무조건 A의 자리수가 더 크도록 설정해준다
    if(bLen > aLen) {
        for(i=0; i<aLen; i++) {
            B[i] = A[i];
        }
        for(i=0; i<bLen; i++) {
            A[i] = inputStr[i] - '0';
        }
        temp = aLen;  aLen = bLen;  bLen = temp;
    }
    
    //B의 일의자리부터 마지막자리까지 곱셈을 시작한다
    for(i=0; i<bLen; i++) {
        c = 0;
        for(j=0; j<aLen; j++) {
            temp = (A[aLen-1-j] * B[bLen-1-i]) + c + result[i+j];
            
            if(temp >= 10) {
                result[i+j] = temp % 10;
                c = temp / 10;
            }else {
                result[i+j] = temp;
                c = 0;
            }
        }//end 1st inner for
        while(c != 0) {
            temp = result[i+j] + c;
            
            if(temp >= 10) {
                result[i+j] = temp % 10;
                c = temp/10;
            }else {
                result[i+j] = c;
                c = 0;
            }
            j++;
        }//end while
    }//end outter for
    
    idx = aLen + bLen - 1;
    if(result[idx] != 0) {
        idx++;
    }
    
    for(i=0; i<idx; i++) {
        printf("%d", result[idx-1-i]);
    }
    
    return 0;
}
