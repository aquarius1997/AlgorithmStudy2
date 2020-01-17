//
//  TOMATO.cpp
//  AJ
//
//  Created by 송혜경 on 14/10/2019.
//  Copyright © 2019 송혜경. All rights reserved.
/*
 1. 상자를 탐색하며 익은 토마토가 있을 때 마다 BFS 함수를 호출한다
 2. BFS함수에서는 더 빨리 익힐 수 있는지에 따라 큐에 넣고 뺀다
 3. 위의 과정이 끝나면 상자를 탐색하며 모든 토마토가 익었는지 확인한다
 */

#include <cstdio>
#include <queue>

using namespace std;

const int MAXN = 105;
int N, M, H;
int T[MAXN][MAXN][MAXN] = {0, };    //결과 토마토 정보

void bfs(int h, int row, int col) {
    queue <int> Queue;
    int i, j, k, d;
    
    Queue.push(row);    Queue.push(col);    Queue.push(h);
    
    while(!Queue.empty()) {
        i = Queue.front();  Queue.pop();
        j = Queue.front();  Queue.pop();
        k = Queue.front();  Queue.pop();
        d = T[k][i][j] + 1;
        
        //같은 판에서의 위쪽 토마토를 익힌다
        if(i-1 >= 0) {
            if(T[k][i-1][j] == 0  || T[k][i-1][j] > d) {
                T[k][i-1][j] = d;
                Queue.push(i-1);    Queue.push(j);  Queue.push(k);
            }
        }
        //같은 판에서 아래쪽 토마토를 익힌다
        if(i+1 < N) {
            if(T[k][i+1][j] == 0 || T[k][i+1][j] > d) {
                T[k][i+1][j] = d;
                Queue.push(i+1);    Queue.push(j);  Queue.push(k);
            }
        }
        //같은 판에서 왼쪽 토마토를 익힌다
        if(j-1 >= 0) {
            if(T[k][i][j-1] == 0 || T[k][i][j-1] > d) {
                T[k][i][j-1] = d;
                Queue.push(i);  Queue.push(j-1);    Queue.push(k);
            }
        }
        //같은 판에서 오른쪽 토마토를 익힌다
        if(j+1 < M) {
            if(T[k][i][j+1] == 0 || T[k][i][j+1] > d) {
                T[k][i][j+1] = d;
                Queue.push(i);  Queue.push(j+1);    Queue.push(k);
            }
        }
        //윗쪽 판의 토마토를 익힌다
        if(k+1 < H) {
            if(T[k+1][i][j] == 0 || T[k+1][i][j] > d) {
                T[k+1][i][j] = d;
                Queue.push(i);  Queue.push(j);  Queue.push(k+1);
            }
        }
        //아래쪽 판의 토마토를 익힌다
        if(k-1 >= 0) {
            if(T[k-1][i][j] == 0 || T[k-1][i][j] > d) {
                T[k-1][i][j] = d;
                Queue.push(i);  Queue.push(j);  Queue.push(k-1);
            }
        }
        
    }
}


int main(void) {
    int max = -987987987;
    int flag = 0;
    int i, j, k;
    
    scanf("%d %d %d", &M, &N, &H);
    
    for(k=0; k<H; k++) {
        for(i=0; i<N; i++) {
            for(j=0; j<M; j++) {
                scanf("%d", &T[k][i][j]);
            }
        }
    }
    
    for(k=0; k<H; k++) {
        for(i=0; i<N; i++) {
            for(j=0; j<M; j++) {
                //익은 토마토에 대해 BFS 탐색
                if(T[k][i][j] == 1) {
                    bfs(k, i, j);
                }
            }
        }
    }
    
    for(k=0; k<H; k++) {
        for(i=0; i<N; i++) {
            for(j=0; j<M; j++) {
                //익지 않은 토마토가 있으면
                if(T[k][i][j] == 0) {
                    flag = 1;
                    break;
                }else {
                    if(max < T[k][i][j]) {
                        max = T[k][i][j];
                    }
                }
            }
        }
    }
    
    if(flag == 1) {
        printf("-1");
    }else {
        printf("%d", max-1);
    }
    
    return 0;
}

