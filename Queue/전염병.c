//
//  전염병.c
//  AJ
//
//  Created by 송혜경 on 03/10/2019.
//  Copyright © 2019 송혜경. All rights reserved.
//

//방문하지 않은 노드이면서, 1~N사이의 노드이면 큐에 삽입한다

#include <stdio.h>

typedef struct QueueType {
    int capacity;   //큐사이즈
    int arr[100002];
    int front, rear;
    int num;        //현재 큐에 들어가있는 요소의 수
}QueueType;

void init(QueueType *q, int num) {
    q->capacity = num;
    q->num = 0;
    q->front = q->rear = 0;
}

void push(QueueType *q, int element) {
    q->arr[(q->rear)] = element;
    q->rear = ((q->rear) + 1) % (q->capacity);
    (q->num)++;
}

int pop(QueueType *q) {
    int element;
    element = q->arr[(q->front)];
    q->front = ((q->front) + 1) % (q->capacity);
    (q->num)--;
    return element;
}

int is_empty(QueueType *q) {
    if(q->num == 0) {
        return 1;
    }else {
        return 0;
    }
}

int main(void) {
    QueueType q;
    int N, K;
    int visited[100002] = {0, };
    int element;
    int count = 0;
    int i;
    
    scanf("%d %d", &N, &K);
    
    //init Queue
    init(&q, N);
    
    //K를 큐에 삽입
    push(&q, K);
    visited[K] = 1;
    
    //큐가 빌때까지 반복한다
    while(!(is_empty(&q))) {
        element = pop(&q);
        
        //범위안에들면서 방문 안한 노드이면
        if(element * 2 >= 1 && element * 2 <= N && visited[(element*2)] == 0) {
            push(&q, element*2);
            visited[element*2] = 1;
        }
        
        if(element / 3 >= 1 && element / 3 <= N && visited[(element/3)] == 0) {
            push(&q, element/3);
            visited[element/3] = 1;
        }
    }
    
    for(i=1; i<=N; i++) {
        if(visited[i] == 0) {
            count++;
        }
    }
    
    printf("%d", count);
    
    return 0;
    
}
