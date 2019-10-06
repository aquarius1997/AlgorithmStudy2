//
//  힙구현.cpp
//  AJ
//
//  Created by 송혜경 on 06/10/2019.
//  Copyright © 2019 송혜경. All rights reserved.
//  !! 힙(MIN_HEAP) : 부모의 값이 항상 자식보다 작은 완전 이진 트리 (=부모일수록 우선순위가 높음)
//  노드의 수가 N개인 힙의 삽입 시간 복잡도 : (높이 : log N) 따라서 O(log N)
//  삭제 시간 복잡도 : O(log N)
//  !!! 힙의 루트번호는 1번이다!!! 무조건 1번부터 시작
/*          1
 2       3
 4      5  6      7
 */

#include <stdio.h>
const int MAX = 100;

struct PriorityQueue {
    int data[MAX];
    int len = 1;    //원소의 마지막을 가리킨다
    
    //1.맨 끝에 값을 push하고
    //2.부모노드와 비교하며 우선순위큐를 만든다
    void push(int x) {
        int idx;
        
        data[len++] = x;
        
        idx = len - 1;
        
        //루트가 아닐때 반복하며 비교
        while(idx > 1) {
            if(data[idx] < data[idx/2]) {
                int temp = data[idx];
                data[idx] = data[idx/2];
                data[idx/2] = temp;
            }
            else break;
            
            idx = idx/2;
        }
    }
    
    //1. 루트 제거
    //2. 맨 끝에 있는 요소를 루트로 가져옴 + 크기 조정
    //3. 우선순위큐로 만든다
    void pop() {
        int idx;
        int pIdx;
        
        data[1] = data[len-1];
        len--;
        
        idx = 1;
        
        //0. 왼쪽과 오른쪽 자식이 있는지 확인한다
        //1. 자식들 중에서 우선순위가 높은 자식을 알아내서
        //2. 해당 자식노드와 자리를 바꾼다
        while(1) {
            pIdx = -1;
            
            //1) 자식노드가 없을 경우
            if(len*2 >= len) {
                break;
            }
            //2) 왼쪽 자식만 존재할 경우
            else if((idx*2 >= 1 && idx*2 < len) && idx*2+1 >= len) {
                pIdx = idx*2;
            }
            //3) 둘 다 존재하는 경우
            else {
                if(data[idx*2] < data[idx*2+1]) {
                    pIdx = idx*2;
                }
                else {
                    pIdx = idx*2 + 1;
                }
            }
            
            if(data[idx] > data[pIdx]) {
                int temp = data[idx];
                data[idx] = data[pIdx];
                data[pIdx] = temp;
                
                idx = pIdx;
            }
            //자식노드가 더 클 경우
            else break;
        }
    }
    
    int top() {
        return data[1];
    }
};

int main(void) {
    PriorityQueue q;
    
    q.push(3);
    q.push(1);
    q.push(2);
    
    printf("%d\n", q.top());
    q.pop();
    
    printf("%d\n", q.top());
    q.pop();
    
    printf("%d\n", q.top());
    q.pop();
    
    return 0;
}
