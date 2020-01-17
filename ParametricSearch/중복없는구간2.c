//
//  중복없는구간2.c
//  AJ
//
//  Created by 송혜경 on 03/10/2019.
//  Copyright © 2019 송혜경. All rights reserved.
//
#include <stdio.h>

int main(void){
    int n;
    int s=0;
    int d=0;
    int max_d=0;
    int arr[100001];  int visited[100001]={0, };
    int i;
    
    scanf("%d", &n);
    
    for(i=0; i<n; i++)
        scanf("%d", &arr[i]);
    
    for(i=0; i<n;){
        if(visited[arr[i]] == 0){
            d++;
            visited[arr[i]]=1;
            if(d>max_d)
                max_d = d;
            i++;
        }else{
            visited[arr[s]] = 0;
            s++;
            d--;
        }
    }
    
    printf("%d", max_d);
    
    return 0;
}
