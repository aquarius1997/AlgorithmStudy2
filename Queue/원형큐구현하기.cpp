//
//  원형큐구현하기.cpp
//  AJ
//
//  Created by 송혜경 on 03/10/2019.
//  Copyright © 2019 송혜경. All rights reserved.
//
#include <stdio.h>

typedef struct QueueType{
    int arr[110];
    int rear, front;
    int capacity; //큐의 용량
    int n;  //현재 큐에 들어있는 요소의 개수
    
    void init(int num){
        rear = front = 0;
        capacity = num;
        n = 0;
    }
    
    void push(int element){
        if(capacity == n)
            printf("Overflow\n");
        else{
            arr[rear] = element;
            rear = (rear+1) % capacity;
            n++;
        }
    }
    
    void pop(){
        if(n == 0)
            printf("Underflow\n");
        else{
            front = (front+1) % capacity;
            n--;
        }
    }
    
    int front_f(){
        if(n == 0)
            return -1;
        else
            return arr[front];
    }
}QueueType;

int main(void){
    int n, m;
    int ope, num;
    int i;
    int re;
    QueueType q;
    
    scanf("%d %d", &n, &m);
    
    q.init(n);
    
    for(i=0; i<m; i++){
        scanf("%d", &ope);
        
        if(ope == 1){
            scanf("%d", &num);
            q.push(num);
        }else if(ope == 2){
            q.pop();
        }else{
            re = q.front_f();
            if(re == -1)
                printf("NULL\n");
            else
                printf("%d\n", re);
        }
    }
    
    return 0;
}

