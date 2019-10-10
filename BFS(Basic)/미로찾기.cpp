//
//  미로찾기.cpp
//  AJ
//
//  Created by 송혜경 on 09/10/2019.
//  Copyright © 2019 송혜경. All rights reserved.
//

#include <cstdio>
#include <queue>

using namespace std;

queue <int> Queue;
const int MAXN = 1002;
int T[MAXN][MAXN];
int N, M;

void bfs(int x, int y) {
    int row, col;
    int d;
    
    Queue.push(x);  Queue.push(y);
    
    while(!(Queue.empty())) {
        row = Queue.front();    Queue.pop();
        col = Queue.front();    Queue.pop();
        d = T[row][col] + 1;
        
        //윗노드 확인
        if(row-1 >= 0) {
            if(T[row-1][col] == 0 || d < T[row-1][col]) {
                Queue.push(row-1);  Queue.push(col);
                T[row-1][col] = d;
            }
        }
        if(row + 1 < N) {
            if(T[row+1][col] == 0 || d < T[row+1][col] ) {
                Queue.push(row+1);  Queue.push(col);
                T[row+1][col] = d;
            }
        }
        if(col-1 >= 0) {
            if(T[row][col-1] == 0 || d < T[row][col-1]) {
                Queue.push(row);    Queue.push(col-1);
                T[row][col-1] = d;
            }
        }
        if(col+1 < M) {
            if(T[row][col+1] == 0 || d < T[row][col+1]) {
                Queue.push(row);    Queue.push(col+1);
                T[row][col+1] = d;
            }
        }
    }
    
}

int main(void) {
    int i, j;
    int num;
    
    scanf("%d %d", &N, &M);
    
    for(i=0; i<N; i++) {
        for(j=0; j<M; j++) {
            scanf("%d", &num);
            if(num == 0) {
                T[i][j] = 0;
            }else {
                T[i][j] = -1;
            }
        }
    }
    
    bfs(N-1, 0);
    
    T[N-1][0] = 0;
    
    printf("%d", T[0][M-1]);
    
    return 0;
}
