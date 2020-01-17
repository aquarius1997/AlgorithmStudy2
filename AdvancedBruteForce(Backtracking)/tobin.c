//
//  tobin.c
//  AJ
//
//  Created by 송혜경 on 03/10/2019.
//  Copyright © 2019 송혜경. All rights reserved.
//

#include <stdio.h>

void tobin(int arr[32], int n, int k, int idx) {
    int i;
    
    //종료조건
    if(n == 1) {
        if(k == 1) {
            for(i=0; i<idx; i++) {
                printf("%d", arr[i]);
            }
            printf("1\n");
        }
        if(k == 0) {
            for(i=0; i<idx; i++) {
                printf("%d", arr[i]);
            }
            printf("0\n");
        }
    }else { //순환
        if(k > 0) {
            arr[idx] = 1;
            tobin(arr, n-1, k-1, idx+1);
        }
        arr[idx] = 0;
        tobin(arr, n-1, k, idx+1);
    }
}

int main(void) {
    int n, k;
    int arr[32];
    
    scanf("%d %d", &n, &k);
    
    tobin(arr, n, k, 0);
    
    return 0;
}
