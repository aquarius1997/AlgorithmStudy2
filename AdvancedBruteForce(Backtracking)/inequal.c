//
//  inequal.c
//  AJ
//
//  Created by 송혜경 on 03/10/2019.
//  Copyright © 2019 송혜경. All rights reserved.
//

#include <stdio.h>
#include <string.h>

//입력으로 받은 부등호 배열
char str[11];
//부등호 개수
int k;
int m_flag=0;

//처음 idx 1부터 시작
void inequal(int arr[], int idx){
    int i, j;
    int flag=0;
    int visited[10]={0, };
    
    
    //종료부. 예외처리+출력
    if(idx==k+1){
        //우선 중복 예외처리 하지 않음
        for(i=0; i<idx; i++){
            if(visited[(arr[i])]==0)
                visited[(arr[i])]=1;
            else{
                flag=1; break;
            }
        }
        if(flag==0 && m_flag==0){
            for(i=0; i<idx; i++)
                printf("%d", arr[i]);
            printf("\n");
            m_flag=1;
        }
    }else{
        if(m_flag==0){
            if(str[idx-1]=='>'){
                for(i=0; i<arr[idx-1]; i++){
                    arr[idx]=i;
                    inequal(arr, idx+1);
                }
            }
            if(str[idx-1]=='<'){
                for(i=arr[idx-1]+1; i<=9; i++){
                    arr[idx]=i;
                    inequal(arr, idx+1);
                }
            }
        }
    }
}

void inequal2(int arr[], int idx){
    int i, j;
    int flag=0;
    int visited[10]={0, };
    
    
    //종료부. 예외처리+출력
    if(idx==k+1){
        //우선 중복 예외처리 하지 않음
        for(i=0; i<idx; i++){
            if(visited[(arr[i])]==0)
                visited[(arr[i])]=1;
            else{
                flag=1; break;
            }
        }
        if(flag==0 && m_flag==0){
            for(i=0; i<idx; i++)
                printf("%d", arr[i]);
            printf("\n");
            m_flag=1;
        }
    }else{
        if(m_flag==0){
            if(str[idx-1]=='>'){
                for(i=arr[idx-1]-1; i>=0; i--){
                    arr[idx]=i;
                    inequal2(arr, idx+1);
                }
            }
            if(str[idx-1]=='<'){
                for(i=9; i>=arr[idx-1]+1; i--){
                    arr[idx]=i;
                    inequal2(arr, idx+1);
                }
            }
        }
    }
}

int main(void){
    char temp[22];
    int i;  int len;  int idx=0;
    int arr[11];
    
    scanf("%d", &k);
    
    fgets(temp, 21, stdin);
    fgets(temp, 21, stdin);
    
    len = strlen(temp);
    
    for(i=0; i<len; i++)
        if(temp[i]!=' ')
            str[idx++]=temp[i];
    
    
    for(i=9; i>=0; i--){
        arr[0]=i;
        inequal2(arr, 1);
        if(m_flag==1)
            break;
    }
    
    m_flag=0;
    
    for(i=0; i<=9; i++){
        arr[0]=i;
        inequal(arr, 1);
        if(m_flag==1)
            break;
    }
    
    return 0;
}
