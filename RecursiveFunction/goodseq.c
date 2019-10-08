//
//  goodseq.c
//  AJ
//
//  Created by 송혜경 on 06/10/2019.
//  Copyright © 2019 송혜경. All rights reserved.
//


//!! 시간복잡도에 유의해야함. 일반적인 재귀 방법으로 순열을 만들면 무조건 시간초과가 됨을 유의한다

#include <stdio.h>
int arr[85];
int N;
int cnt = 0;

//현재까지 만든 배열이 좋은 순열인지 검증한다
int good_seq(int idx) {
    int flag;
    int len;
    int j, k, m;
    
    //인접한 수끼리 중복되는지 확인할때는 (현재까지 만든 배열 길이/2) 까지만 확인하면됨
    len = (idx+1) / 2;
    
    for(j=1; j<=len; j++) { //조사할 substring의 길이
        for(k=0; k<=idx; k++) { //조사 범위
            
            //초기화는 중복됨으로 표시
            flag = 1;
            
            //오른쪽 이웃이 탐색 가능한 범위이면 문자열이 중복되는지 확인한다
            if(k+(j-1)+j <= idx) {
                for(m=0; m<j; m++) {
                    if(arr[k+m+j] != arr[k+m]) {
                        flag = 0;
                    }
                }
            }else {
                flag = 0;
            }
            
            //중복되면
            if(flag != 0) {
                break;
            }
            
        }
        //중복되면
        if(flag != 0) {
            break;
        }
    }
    
    return flag;
}

//순열을 만드는 함수 (재귀호출 바탕)
void make_seq(int idx) {
    int i;
    
    if(idx == N) {
        //가장 값이 작은 좋은 순열을 출력한다
        if(cnt == 0 && (good_seq(idx) == 0)) {
            for(i=0; i<idx; i++) {
                printf("%d", arr[i]);
            }
            cnt++;
        }
    }else {
        for(i=1; i<=3; i++) {
            arr[idx] = i;

            if(idx == 0) {
                make_seq(idx+1);
            }else{
                //현재까지 만든 배열이 좋은 순열인지 검증한다 + 아직 결과값을 낸 것이 없을 경우에만 다음을 진행한다
                if((good_seq(idx) == 0) && (cnt == 0)) {
                    make_seq(idx+1);
                }
                
            }
        }
    }
}

int main(void) {
    
    scanf("%d", &N);
    
    make_seq(0);
    
    return 0;
    
}
