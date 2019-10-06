//
//  goodseq.c
//  AJ
//
//  Created by 송혜경 on 06/10/2019.
//  Copyright © 2019 송혜경. All rights reserved.
//


/*
#include <stdio.h>
//처음 호출할때 idx : 0
void goodseq(int n, int idx, int arr[], int *end){
    int i,j,k;  int l;  int flag=0;
    int final=0;
    //좋은 순열인지 확인
    if(idx==n){
        for(i=0; i<n; i++)
            printf("%d", arr[i]);
        printf("\n");
        *end=1;
        return;
    }
    for(i=1; i<=3; i++){
        arr[idx]=i;
        for(l=1; l<=idx; l++){
            for(j=0; j<=idx-(l*2)+1; j++){
                flag=0;
                for(k=0; k<l; k++){
                    if(arr[j+k]!=arr[j+k+l]){
                        flag=1;
                        break;
                    }
                }
                if(flag==0){
                    final=1;
                    break;
                }
            }
            if(final==1)
                break;
        }
        if(final==1){
            final=0;
            continue;
        }
        goodseq(n, idx+1, arr, end);
        if(*end==1)
            return;
    }
    return;
}

int main() {
    int N;
    int arr[81];
    int end=0;
    scanf("%d", &N);
    goodseq(N, 0, arr, &end);
    return 0;
}

*/

//!! 시간복잡도에 유의해야함. 일반적인 재귀 방법으로 순열을 만들면 무조건 시간초과가 됨을 유의한다

#include <stdio.h>
int arr[85];
int N;



void make_seq(int idx) {
    int i, j;
    int len;
    if(idx == N) {
        
    }else {
        for(i=1; i<=3; i++) {
            arr[idx] = i;
            
            //현재까지 만든 배열이 좋은 순열인지 검증한다
            //인접한 수끼리 중복되는지 확인할때는 (현재까지 만든 배열 길이/2) 까지만 확인하면됨
            len = (idx+1) / 2;
            for(j=0; j<=(idx-len+1); j++) {
                //len만큼 이웃배열이 중복되는지 확인
            }
            
            //현재까지 만든 배열이 좋은 순열일 경우 재귀함수 호출해서 다음을 진행한다
            make_seq(idx+1);
            
            //현재까지 만든 수가 나쁜 순열일 경우 재귀함수 호출하지 않는다
        }
    }
}

int main(void) {
    int i;
    
    scanf("%d", &N);
    
    make_seq(0);
    
    return 0;
    
}
