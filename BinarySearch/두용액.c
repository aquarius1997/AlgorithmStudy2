//
//  두용액.c
//  AJ
//
//  Created by 송혜경 on 03/10/2019.
//  Copyright © 2019 송혜경. All rights reserved.
//
#include <cstdio>
#include <algorithm>
#define ARRSIZE 100002

using namespace std;
//0과 가장 가까운 특성값을 저장한다
int result = 987987987;
int num1, num2;

void binary_search(int arr[ARRSIZE], int idx, int start, int end) {
    int num;
    int mid;
    
    //인자값으로 들어온 인덱스의 값을 num에 초기화한다
    num = arr[idx];
    
    if(start <= end) {
        //가운데 인덱스를 구한다
        mid = (start+end) / 2;
        
        //인자로 들어온 인덱스가 가운데 인덱스였으면
        if(mid == idx) {
            binary_search(arr, idx, start, mid-1);
            binary_search(arr, idx, mid+1, end);
        }
        else {
            //기준 인덱스의 값이랑 mid인덱스의 값의 합이 0이면
            if(num+arr[mid] == 0 && result != 0) {
                result = 0;
                num1 = num;
                num2 = arr[mid];
            }
            //기준 인덱스의 값이랑 mid인덱스의 값의 합이 양수이면
            else if(num+arr[mid] > 0) {
                //값을 업데이트 할 수 있는지 확인한다
                if(num+arr[mid] < result) {
                    result = num+arr[mid];
                    num1 = num;
                    num2 = arr[mid];
                }
                binary_search(arr, idx, start, mid-1);
            }
            //기준 인덱스의 값이랑 mid인덱스의 값의 합이 음수이면
            else {
                if((num+arr[mid])*(-1) < result) {
                    result = (num+arr[mid])*(-1);
                    num1 = num;
                    num2 = arr[mid];
                }
                binary_search(arr, idx, mid+1, end);
            }
        }
    }
    
}

int main(void) {
    int arr[ARRSIZE];
    int N;
    int i;
    
    scanf("%d", &N);
    
    for(i=0; i<N; i++) {
        scanf("%d", &arr[i]);
    }
    
    //정렬
    sort(arr, arr+N);
    
    //이진탐색을 활용
    for(i=0; i<N; i++) {
        binary_search(arr, i, 0, N-1);
    }
    
    if(num1 > num2) {
        printf("%d %d", num2, num1);
    }else {
        printf("%d %d", num1, num2);
    }
    
    return 0;
}
