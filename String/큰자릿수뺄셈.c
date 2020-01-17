//
//  큰자릿수뺄셈.c
//  AJ
//
//  Created by 송혜경 on 03/10/2019.
//  Copyright © 2019 송혜경. All rights reserved.
//

#include <stdio.h>
#include <string.h>

int main(void) {
    char inputStr[1000000];
    int A[1000000]; int B[1000000]; int result[1000000];
    int aLen, bLen; int idx = 0;  int temp; int c;
    int isMinus = 0;
    int i, j;
    
    scanf("%s", inputStr);
    
    //입력받은 문자열을 숫자형으로 변환해서 저장
    aLen = strlen(inputStr);
    for(i=0; i<aLen; i++) {
        A[i] = inputStr[i] - '0';
    }
    
    scanf("%s", inputStr);
    
    //입력받은 문자열을 숫자형으로 변환해서 저장2
    bLen = strlen(inputStr);
    for(i=0; i<bLen; i++) {
        B[i] = inputStr[i] - '0';
    }
    
    //A랑 B 중에 뭐가 더 큰지 알아낸다
    if(aLen == bLen) {
        for(i=0; i<bLen; i++) {
            if(A[i] == B[i]){
                continue;
            }else if(A[i] > B[i]) {
                break;
            }else {
                //B가 더 클경우 A랑 값을 바꾼다(무조건 A가 더 큰수임을 가정하고 작성할 예정)
                for(i=0; i<bLen; i++) {
                    B[i] = A[i];
                    A[i] = inputStr[i] - '0';
                }
                isMinus = 1;
            }
        }
    }else if(bLen > aLen) {
        //B가 더 클경우 A랑 값을 바꾼다 (무조건 A가 더 큰수임을 가정하고 작성할 예정)
        for(i=0; i<aLen; i++) {
            B[i] = A[i];
        }
        for(i=0; i<bLen; i++) {
            A[i] = inputStr[i] - '0';
        }
        temp = aLen;
        aLen = bLen;
        bLen = temp;
        isMinus = 1;
    }
    
    c = i = j = 0;
    //A-B 과정을 구한다
    while(i<aLen && j<bLen) {
        temp = (c + A[aLen-1-i] - B[bLen-1-j]);
        
        //앞자리에서 수를 빌려와야할 경우
        if(temp < 0) {
            result[idx++] = temp + 10;
            c = -1;
        }else {
            result[idx++] = temp;
            c = 0;
        }
        i++;
        j++;
    }
    
    //A수가 남아있을 경우
    while(i < aLen) {
        temp = (c + A[aLen-1-i]);
        
        if(temp < 0) {
            result[idx++] = temp + 10;
            c = -1;
        }else{
            result[idx++] = temp;
            c = 0;
        }
        i++;
    }
    
    i = idx-1;
    while(result[i] == 0 && i!=0) {
        idx--;
        i--;
    }
    
    //결과가 음수일 경우
    if(isMinus == 1) {
        printf("-");
    }
    for(i=0; i<idx; i++) {
        printf("%d", result[idx-1-i]);
    }
    
    return 0;
    
}
