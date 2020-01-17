//
//  NN단표.c
//  AJ
//
//  Created by 송혜경 on 03/10/2019.
//  Copyright © 2019 송혜경. All rights reserved.
//

#include <stdio.h>

int check(int n, int k, long long mid){
    int i, j;
    int count=0;  int temp=0;
    
    for(i=1; i<=n; i++){
        if(i*n<=mid){
            count+=(n-i)*2+1;a
        }else{
            if(i*i<=mid){
                count++;
            }else break;
            
            temp=(mid/i)-i;
            count+=temp*2;
        }
        if(count>=k)
            return 1;
    }
    if(count>=k)
        return 1;
    else
        return -1;
}
int main(){
    int i, j;
    int N, K;
    long long start, end, mid;
    
    scanf("%d", &N);
    scanf("%d", &K);
    
    start=1;
    end=N*N;
    if(check(N, K, start)==1){
        printf("%d", start);
        return 0;
    }
    
    while(start+1<end){
        mid=(start+end)/2;
        if(check(N, K, mid)==1)
            end=mid;
        else
            start=mid;
    }
    printf("%d", end);
    return 0;
}
