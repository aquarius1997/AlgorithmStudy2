//
//  연속부분최대합.c
//  AJ
//
//  Created by 송혜경 on 06/10/2019.
//  Copyright © 2019 송혜경. All rights reserved.
//
/*
 sum[x] : 첫번째 수 부터 x번째 수까지 더한 값
 
 1, 2, -4, 5, 3, -2, 9, 10
 
 -4 ~ 9 까지의 합 = sum[7] - sum[2]
 
 sum을 구한다 : O(n)
 start : 0 ~ n : O(n)
 end : start ~ n : O(n)
 구간합 구하기 ; O(1)
 최댓값 구하기: O(1)
 
 따라서 시간복잡도 : O(n^2) , 왜냐면 sum 구하는거는 for문 밖에서 행해지기때문에
 */

#include <stdio.h>

int main(void) {
    int data[1000];
    int sum[1000];
    int myMax = -987987987;
    int n;
    int i;
    
    scanf("%d", &n);
    
    for(i=0; i<n; i++) {
        scanf("%d", &data[i]);
    }
    
    sum[0] = data[0];
    for(i=0; i<n; i++) {
        sum[i] = sum[i-1] + data[i];
    }
    
    for(int start=0; start<n; start++) {
        for(int end=start; end<n; end++) {
            int mySum = 0;
            
            //start ~ end 까지의 합 = sum[end] - sum[start-1]
            if(start == 0) {
                mySum = sum[end];
            }
            else {
                mySum = sum[end] - sum[start-1];
            }
            
            if(mySum > myMax) {
                myMax = mySum;
            }
        }
    }
    
    printf("%d", myMax);
    
    return 0;
}

