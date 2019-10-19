//
//  COWART.cpp
//  AJ
//
//  Created by 송혜경 on 18/10/2019.
//  Copyright © 2019 송혜경. All rights reserved.
//

#include <cstdio>
#include <queue>

using namespace std;

const int MAXN = 102;
int T[MAXN][MAXN] = {0, };  //사람이 읽을 입력 테이블 정보 (R : 1, G : 2, B : 3)
int CT[MAXN][MAXN] = {0, }; //소에게 보이는 입력 테이블 정보 (R, G : 1, B : 2)
int visited[MAXN][MAXN] = {0, };

int N;

void bfs(int row, int col) {
    queue <int> Queue;
    int rgb;
    int i, j;
    
    Queue.push(row);    Queue.push(col);
    visited[row][col] = 1;
    rgb = T[row][col];

    while(!Queue.empty()) {
        i = Queue.front();  Queue.pop();
        j = Queue.front();  Queue.pop();
        
        
        if(i-1 >= 0) {
            if(T[i-1][j] == rgb && visited[i-1][j] == 0) {
                Queue.push(i-1);    Queue.push(j);
                visited[i-1][j] = 1;
            }
        }
        if(i+1 < N) {
            if(T[i+1][j] == rgb && visited[i+1][j] == 0) {
                Queue.push(i+1);    Queue.push(j);
                visited[i+1][j] = 1;
            }
        }
        if(j-1 >= 0) {
            if(T[i][j-1] == rgb && visited[i][j-1] == 0) {
                Queue.push(i);  Queue.push(j-1);
                visited[i][j-1] = 1;
            }
        }
        if(j+1 < N) {
            if(T[i][j+1] == rgb && visited[i][j+1] == 0) {
                Queue.push(i);  Queue.push(j+1);
                visited[i][j+1] = 1;
            }
        }
    }
}

int main(void) {
    char str[102];
    int countCow, countP;
    int i, j;
    
    scanf("%d", &N);
    
    for(i=0; i<N; i++) {
        scanf("%s", str);

        for(j=0; j<N; j++) {
            
            if(str[j] == 'R') {
                T[i][j] = CT[i][j] =1;
            }else if(str[j] == 'G') {
                T[i][j] = 2;
                CT[i][j] = 1;
            }else {
                T[i][j] = 3;
                CT[i][j] = 2;
            }
            
        }
    }
    
    countCow = countP = 0;
    
    for(i=0; i<N; i++) {
        for(j=0; j<N; j++) {
            if(visited[i][j] == 0) {
                bfs(i, j);
                countP++;
            }
        }
    }
    
    for(i=0; i<N; i++) {
        for(j=0; j<N; j++) {
            visited[i][j] = 0;
            T[i][j] = CT[i][j];
        }
    }
    
    for(i=0; i<N; i++) {
        for(j=0; j<N; j++) {
            if(visited[i][j] == 0) {
                bfs(i, j);
                countCow++;
            }
        }
    }
    
    printf("%d %d", countP, countCow);
    
    return 0;
}
