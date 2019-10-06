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

const int MAX = 100;

int n;
int data[MAX];

int getSubMax(int start, int end) {
    int mid;
    int left, right;
    int leftSum, rightSum;
    int leftMax, rightMax;
    int myMax;
    int i;
    
    //base condition
    if(start >= end)
        return data[start];
    
    mid = (start + end) / 2;
    
    left = getSubMax(start, mid);
    right = getSubMax(mid+1, end);
    
    leftSum = 0;    leftMax = -987987987;
    for(i=mid; i>=start; i--) {
        leftSum = leftSum + data[i];
        
        if(leftMax < leftSum)
            leftMax = leftSum;
    }
    
    rightSum = 0;   rightMax = -987987987;
    for(i=mid+1; i<=end; i++) {
        rightSum = rightSum + data[i];
        
        if(rightMax < rightSum)
            rightMax = rightSum;
    }
    
    myMax = leftMax + rightMax;
    
    if(left >= right && left >= myMax){
        return left;
    }
    else if(right >= left && right >= myMax){
        return right;
    }
    else{
        return myMax;
    }
}

int main(void) {
    int i;
    
    scanf("%d", &n);
    
    for(i=0; i<n; i++) {
        scanf("%d", &data[i]);
    }
    
    printf("%d\n", getSubMax(0, n-1));
    
    return 0;
}
