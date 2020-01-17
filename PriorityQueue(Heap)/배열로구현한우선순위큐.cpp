//
//  배열로구현한우선순위큐.cpp
//  AJ
//
//  Created by 송혜경 on 06/10/2019.
//  Copyright © 2019 송혜경. All rights reserved.
// 삽입 : O(1) , 삭제(pop) : O(N) 이므로 매우 비효율적이다

#include <stdio.h>

const int MAX = 100;

struct priorityQueue {
    int data[MAX];
    int len = 0;
    
    void push(int x) {
        data[len++] = x;
    }
    
    //우선순위가 가장 높은 원소를 찾는다
    //그 원소를 제거하고, 뒤의 원소를 앞으로 당긴다(배열로 구현했기 때문에)
    void pop() {
        int myMAX = -987987987, myMaxIdx = -1;
        
        for(int i=0; i<len; i++) {
            if(data[i] > myMax) {
                myMax = data[i];
                myMaxIdx = i;
            }
        }
        
        for(int i=myIdx; i<len; i++) {
            data[i] = data[i+1];
        }
        
        len--;
    }
    
    //우선순위가 가장 높은 원소를 반환한다
    int top() {
        int myMAX = -987987987;
        
        for(int i=0; i<len; i++) {
            if(data[i] > myMax) {
                myMax = data[i];
            }
        }
        
        return myMax;
    }
};

