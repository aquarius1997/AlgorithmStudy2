//
//  향상된연속부분최대합.c
//  AJ
//
//  Created by 송혜경 on 06/10/2019.
//  Copyright © 2019 송혜경. All rights reserved.
/*
 1. 왼쪽만 포함했을 때의 최대
 2. 오른쪽만 포함했을 때의 최대
 3. 자른 자리를 포함했을 때의 최대 (=> 자른자리로부터 왼쪽 최대 + 자른자리로부터 오른쪽 최대)
 중에서 최대를 구하면됨
 
 N개의 숫자에서 시간복잡도
 T(N) : N개의 숫자중 연속 부분 최대합을 구하는데 걸리는 시간
 T(N) = T(N/2) + T(N/2) + O(N)
 T(N) = 2*T(N/2) + O(N) = O(NlongN)
 */


#include <stdio.h>

//start ~ end 범위의 연속부분 최대 합을 구한다
int get_max(int arr[], int start, int end) {
    int leftSum, rightSum;  int leftM, rightM;
    int leftMax, rightMax, midMax;
    int mid;
    int i;
    
    if(start >= end) {
        return arr[start];
    }else {
        mid = (start + end) / 2;
        
        //왼쪽, 오른쪽 부분 배열에 대하여 연속부분 최대합을 구함
        leftMax = get_max(arr, start, mid);
        rightMax = get_max(arr, mid+1, end);
        
        leftSum = rightSum = 0;
        leftM = rightM = -987987987;
        
        //중간(mid)으로 부터 양옆으로 뻗어나가는 형식의 최대합 구간(최대합)을 구한다
        //i범위 유의!!!!!
        for(i=mid; i>=start; i--) {
            leftSum += arr[i];
            
            if(leftSum > leftM) {
                leftM = leftSum;
            }
        }
        for(i=mid+1; i<=end; i++) {
            rightSum += arr[i];
            
            if(rightSum > rightM) {
                rightM = rightSum;
            }
        }
        
        midMax = leftM + rightM;
        
        if(leftMax >= midMax && leftMax >= rightMax) {
            return leftMax;
        }else if(rightMax >= midMax && rightMax >= leftMax) {
            return rightMax;
        }else{
            return midMax;
        }
    }
}

int main(void) {
    int n;
    int arr[100002] = {0, };
    int i;
    
    scanf("%d", &n);
    
    for(i=0; i<n; i++) {
        scanf("%d", &arr[i]);
    }
    
    printf("%d", get_max(arr, 0, n-1));
    
    return 0;
}
