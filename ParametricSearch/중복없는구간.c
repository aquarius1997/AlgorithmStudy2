//
//  중복없는구간.c
//  AJ
//
//  Created by 송혜경 on 03/10/2019.
//  Copyright © 2019 송혜경. All rights reserved.
//

//이진탐색 방법을 사용한 경우
#include <stdio.h>
int arr[100005] = {0, };
int n;

//start : 해당 구간길이로 중복없는 구간을 만들 수 있는 경우만 가리킨다
//end : 해당 구간길이로 중복없는 구간을 만들 수 없는 경우만 가리킨다
//mid : start와 end의 중간을 가리킨다
//따라서 이진탐색을 수행하다 start + 1 == end일 경우 start가 정답이 된다
int binary_search(int start, int end) {
    int visited[100005] = {0, };
    int mid;
    int e;  int count;  int flag = 0;
    int i, j;
    
    
    if(start < end) {
        if(start + 1 == end) {
            return start;
        } else {
            mid = (end + start) / 2;
            
            for(i=0; i<=n-mid; i++) {
                count = 0;
                
                for(j=0; j<mid; j++) {
                    if(visited[(arr[i+j])] == 0 || visited[(arr[i+j])] == i+j+1) {
                        visited[(arr[i+j])] = i+j+1;
                        count++;
                    }else {
                        //초기화 안하면서 (0 / 1 방식 말고)
                        visited[(arr[i+j])] = i+j+1;
                    }
                }
                
                if(count == mid) {
                    flag = 1;
                }
                
            }
            
            //한번이라도 통과하면
            if(flag == 1) {
                return binary_search(mid, end);
            }else{
                return binary_search(start, mid);
            }
        }
    }
}

int main(void) {
    int i;
    int result;
    int visited[100005] = {0, };
    int flag = 0;
    
    scanf("%d", &n);
    
    for(i=0; i<n; i++) {
        scanf("%d", &arr[i]);
    }
    
    //end가 없을 경우를 따로 구해줘야함 => 길이 n이 중복없는 구간의 최대일 경우
    for(i=0; i<n; i++) {
        if(visited[arr[i]] == 0) {
            visited[arr[i]] = 1;
        }else {
            flag = 1;
        }
    }
    
    if(flag == 0) {
        result = n;
    }else{
        result = binary_search(1, n);
    }
    
    printf("%d", result);
    
    return 0;
}
