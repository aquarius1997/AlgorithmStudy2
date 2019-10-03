//
//  합병정렬.c
//  AJ
//
//  Created by 송혜경 on 03/10/2019.
//  Copyright © 2019 송혜경. All rights reserved.
//

#include <stdio.h>

void merge(int arr[], int s1, int e1, int s2, int e2){
    int temp[100000];   int idx=0;
    int p, q;
    int i;
    
    p = s1; q= s2;
    
    while(p <= e1 && q <= e2){
        if(arr[p] < arr[q])
            temp[idx++] = arr[p++];
        else
            temp[idx++] = arr[q++];
    }
    //남은 q를 temp배열로 이동시킨다
    if(p>e1)
        for(i=q; i<=e2; i++)
            temp[idx++] = arr[i];
    
    //남은 p를 temp배열로 이동시킨다
    if(q>e2)
        for(i=p; i<=e1; i++)
            temp[idx++] = arr[i];
    
    //temp배열을 arr배열로 덮어씌운다
    for(i=0; i<idx; i++)
        arr[s1+i] = temp[i];
}

void merge_sort(int arr[], int s, int e){
    int mid = (s+e)/2;
    
    if(s<e){
        merge_sort(arr, s, mid);
        merge_sort(arr, mid+1, e);
        merge(arr, s, mid, mid+1, e);
    }
}

int main(void){
    int arr[100000];
    int n;
    int i;
    
    scanf("%d", &n);
    
    for(i=0; i<n; i++)
        scanf("%d", &arr[i]);
    
    merge_sort(arr, 0, n-1);
    
    for(i=0; i<n; i++)
        printf("%d ", arr[i]);
    return 0;
}
