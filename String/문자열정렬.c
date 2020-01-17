//
//  문자열정렬.c
//  AJ
//
//  Created by 송혜경 on 03/10/2019.
//  Copyright © 2019 송혜경. All rights reserved.
//
#include <stdio.h>
#include <string.h>

int main(void) {
    int n;
    char str[102][102];
    char temp[102];
    int i, j;
    
    scanf("%d", &n);
    
    for(i=0; i<n; i++) {
        scanf("%s", str[i]);
    }
    
    for(i=1; i<n; i++) {
        strcpy(temp, str[i]);
        for(j=i-1; j>=0; j--) {
            //temp string이 str[j]보다 사전순으로 앞에 위치할 경우 재정렬
            if(strcmp(temp, str[j]) < 0) {
                strcpy(str[j+1], str[j]);
            }else{
                break;
            }
        }
        strcpy(str[j+1], temp);
    }
    
    for(i=0; i<n; i++) {
        printf("%s\n", str[i]);
    }
    
    return 0;
}
