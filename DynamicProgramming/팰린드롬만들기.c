//
//  팰린드롬만들기.c
//  AJ
//
//  Created by 송혜경 on 08/10/2019.
//  Copyright © 2019 송혜경. All rights reserved.
//
#include <stdio.h>
#include <string.h>

int main(void){
    int T[1002][1002];
    char str[1002];
    int len;
    int i, j;
    
    scanf("%s", str);
    
    len = strlen(str);
    
    //base case
    for(i=0; i<len; i++)
        T[i][i] = 0;
    
    
    for(i=len-2; i>=0; i--){
        if(str[i] == str[i+1])
            T[i][i+1] = 0;
        else
            T[i][i+1] = 1;
        for(j=i+2; j<len; j++){
            if(str[i] == str[j])
                T[i][j] = T[i+1][j-1];
            else{
                if(T[i+1][j] < T[i][j-1])
                    T[i][j] = T[i+1][j] + 1;
                else
                    T[i][j] = T[i][j-1] + 1;
            }
            
        }
    }
    
    printf("%d", T[0][len-1]);
    return 0;
}
