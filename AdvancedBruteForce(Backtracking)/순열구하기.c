//
//  순열구하기.c
//  AJ
//
//  Created by 송혜경 on 03/10/2019.
//  Copyright © 2019 송혜경. All rights reserved.
//
#include <stdio.h>

int n, r;

//main에서 호출시 넘겨받는 인자 값(arr, 0)
void make_permutation(int arr[12], int idx) {
    int i, j;
    int visited[12] = {0, };
    int flag = 0;
    
    //종료조건
    if(idx == r) {
        //중복검증
        for(i=0; i<r; i++) {
            if(visited[arr[i]] == 0) {
                visited[(arr[i])]++;
            }else {
                flag = 1;
            }
        }
        if(flag == 0){
            for(i=0; i<r; i++) {
                printf("%c", arr[i]+'a');
            }
            printf("\n");
        }
    }else {
        for(i=0; i<n; i++) {
            arr[idx] = i;
            make_permutation(arr, idx+1);
        }
    }
}

int main(void) {
    int arr[12] = {0, };
    
    scanf("%d %d", &n, &r);
    
    make_permutation(arr, 0);
    
    return 0;
}
