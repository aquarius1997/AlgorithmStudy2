//
//  큰자릿수덧셈.c
//  AJ
//
//  Created by 송혜경 on 03/10/2019.
//  Copyright © 2019 송혜경. All rights reserved.
//
#include <stdio.h>
#include <string.h>

int main(void) {
    char inputArr[1000000];
    int A[1000000]; int B[1000000]; int result[1000000];
    int aLen, bLen;
    int temp;
    int idx = 0;  int c;
    int i, j;
    
    //입력받은 문자열을 int배열에 숫자로 변환
    scanf("%s", inputArr);
    aLen = strlen(inputArr);
    for(i=0; i<aLen; i++) {
        A[i] = inputArr[i] - '0';
    }
    
    scanf("%s", inputArr);
    bLen = strlen(inputArr);
    for(i=0; i<bLen; i++) {
        B[i] = inputArr[i] - '0';
    }
    
    c = i = j = 0;
    while(i<aLen && j<bLen) {
        temp = (c + A[aLen-1-i] + B[bLen-1-j]);
        
        //올림수 발생
        if(temp >= 10) {
            result[idx++] = temp % 10;
            c = temp / 10;
        }else {
            result[idx++] = temp;
            c = 0;
        }
        
        i++;  j++;
    }
    
    //A문자열에서 남은게 있다면
    while(i < aLen) {
        temp = (c + A[aLen-1-i]);
        if(temp >= 10) {
            result[idx++] = temp % 10;
            c = temp / 10;
        }else {
            result[idx++] = temp;
            c = 0;
        }
        i++;
    }
    
    //B문자열에서 남은게 있다면
    while(j < bLen) {
        temp = (c + B[bLen-1-j]);
        if(temp >= 10) {
            result[idx++] = temp % 10;
            c = temp / 10;
        }else {
            result[idx++] = temp;
            c = 0;
        }
        j++;
    }
    
    if(c != 0) {
        result[idx++] = c;
    }
    
    //결과 출력
    for(i=0; i<idx; i++) {
        printf("%d", result[idx-1-i]);
    }
    
    return 0;
}
