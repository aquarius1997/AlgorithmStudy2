//
//  CHEEZE.cpp
//  AJ
//
//  Created by 송혜경 on 10/10/2019.
//  Copyright © 2019 송혜경. All rights reserved.
//  BFS활용

#include <cstdio>
#include <queue>

using namespace std;

const int MAXN = 105;
int N, M;
int hourT = 0;

queue <int> Queue;
int T[MAXN][MAXN] = {0, };  //현재 치즈의 모양
int tempT[MAXN][MAXN] = {0, };  //1시간 후의 치즈모양
int visited[MAXN][MAXN] = {0, };

void bfs(int x, int y) {
    int row, col;
    
    Queue.push(x);  Queue.push(y);
    visited[x][y] = 1;
    
    //큐가 빌때까지 반복해
    while(!Queue.empty()) {
        row = Queue.front();    Queue.pop();
        col = Queue.front();    Queue.pop();
        
        //위에 치즈있는지 확인해!
        if(row-1 >= 0) {
            //인접 공기이면 탐색합니당
            if(T[row-1][col] == 0 && visited[row-1][col] == 0) {
                Queue.push(row-1);  Queue.push(col);
                visited[row-1][col] = 1;
            }
            //치즈이면 녹힌다
            if(T[row-1][col] == 1) {
                tempT[row-1][col] = 0;
            }
        }
        //아래 확인
        if(row+1 < N) {
            if(T[row+1][col] == 0 && visited[row+1][col] == 0) {
                Queue.push(row+1);  Queue.push(col);
                visited[row+1][col] = 1;
            }
            if(T[row+1][col] == 1) {
                tempT[row+1][col] = 0;
            }
        }
        //왼쪽 확인
        if(col-1 >= 0){
            if(T[row][col-1] == 0 && visited[row][col-1] == 0) {
                Queue.push(row);    Queue.push(col-1);
                visited[row][col-1] = 1;
            }
            if(T[row][col-1] == 1) {
                tempT[row][col-1] = 0;
            }
        }
        //오른쪽 확인
        if(col+1 < M) {
            if(T[row][col+1] == 0 && visited[row][col+1] == 0) {
                Queue.push(row);    Queue.push(col+1);
                visited[row][col+1] = 1;
            }
            if(T[row][col+1] == 1) {
                tempT[row][col+1] = 0;
            }
        }
    
    }
    
}

int main(void) {
    int cheezeCount;
    int i, j;
    
    scanf("%d %d", &N, &M);
    
    for(i=0; i<N; i++) {
        for(j=0; j<M; j++) {
            scanf("%d", &T[i][j]);
            tempT[i][j] = T[i][j];
        }
    }
    

    
    while(1) {
        bfs(0, 0);
        hourT++;
        
        //tempT에서 치즈의 개수를 세서 0이면 break
        cheezeCount = 0;
        for(i=0; i<N; i++) {
            for(j=0; j<M; j++) {
                if(tempT[i][j] == 1) {
                    cheezeCount++;
                }
            }
        }
        
        if(cheezeCount == 0)
            break;
        
        //0아니면 tempT를 T로 덮어씌움 + visited초기화
        for(i=0; i<N; i++) {
            for(j=0; j<M; j++) {
                T[i][j] = tempT[i][j];
                visited[i][j] = 0;
            }
        }
    }
    
    //치즈가 모두 녹기 한시간 전의 치즈 모양은 T 배열에 저장되어있다
    cheezeCount = 0;
    for(i=0; i<N; i++) {
        for(j=0; j<M; j++) {
            if(T[i][j] == 1) {
                cheezeCount++;
            }
        }
    }
    
    printf("%d\n%d", hourT, cheezeCount);
    
    return 0;
}


