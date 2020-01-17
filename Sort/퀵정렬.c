//
//  퀵정렬.c
//  AJ
//
//  Created by 송혜경 on 03/10/2019.
//  Copyright © 2019 송혜경. All rights reserved.
//

#include <stdio.h>


void quick_sort(int arr[], int start, int end){
    int pivot;
    int left[100000];
    int right[100000];
    int left_idx; int right_idx;
    int i;
    left_idx=right_idx=0;
    
    if(start>=end)
        return;
    
    pivot=arr[start];
    for(i=start+1; i<=end; i++){
        if(arr[i]<=pivot)
            left[left_idx++]=arr[i];
        else
            right[right_idx++]=arr[i];
    }
    
    for(i=0; i<left_idx; i++)
        arr[start+i]=left[i];
    arr[start+left_idx]=pivot;
    for(i=0; i<right_idx; i++)
        arr[start+left_idx+1+i]=right[i];
    
    quick_sort(arr, start, start+left_idx-1);
    quick_sort(arr, start+left_idx+1, end);
}

int main() {
    int arr[100000];
    int n;
    int i;
    
    scanf("%d", &n);
    for(i=0; i<n; i++)
        scanf("%d", &arr[i]);
    
    quick_sort(arr, 0, n-1);
    for(i=0; i<n; i++)
        printf("%d ", arr[i]);
    
    return 0;
}
