//
//  division.c
//  AJ
//
//  Created by 송혜경 on 03/10/2019.
//  Copyright © 2019 송혜경. All rights reserved.
//
#include <stdio.h>

int count = 0;
void division(int arr[22], int n, int idx) {
    int i;
    int flag = 0;
    
    //종료조건
    if(n == 1 ) {
        //검증
        for(i=0; i<idx-1; i++) {
            if(arr[i] < arr[i+1])
                flag = 1;
        }
        //출력해도되면
        if(flag == 0){
            for(i=0; i<idx; i++) {
                printf("%d+", arr[i]);
            }
            printf("1\n");
            count++;
        }
    }else if(n == 0){
        //자기자신은 출력안함
        if(idx != 1) {
            //검증
            for(i=0; i<idx-1; i++) {
                if(arr[i] < arr[i+1])
                    flag = 1;
            }
            //출력해도되면
            if(flag == 0){
                for(i=0; i<idx-1; i++) {
                    printf("%d+", arr[i]);
                }
                printf("%d\n", arr[idx-1]);
                count++;
            }
        }
    }else {
        for(i=n; i>0; i--) {
            arr[idx] = i;
            division(arr, n-i, idx+1);
        }
    }
}

int main(void) {
    int arr[22] = {0, };
    int n;
    
    scanf("%d", &n);
    
    division(arr, n, 0);
    
    printf("%d", count);
    return 0;
    
}
