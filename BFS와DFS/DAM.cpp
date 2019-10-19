//
//  DAM.cpp
//  AJ
//
//  Created by 송혜경 on 18/10/2019.
//  Copyright © 2019 송혜경. All rights reserved.
//

#include <cstdio>
#include <queue>

using namespace std;

const int MAXN = 102;
int N;
int T[MAXN][MAXN] = {0, };

void bfs(int row, int col) {
    queue <int> Queue;
    int r, c, d;
    
    Queue.push(row);
    Queue.push(col);
    
    while(!Queue.empty()) {
        r = Queue.front();  Queue.pop();
        c = Queue.front();  Queue.pop();
        d = T[r][c] + 1;
        
        if(r-1 >= 0) {
            if(T[r-1][c] == 0 || T[r-1][c] > d) {
                T[r-1][c] = d;
                Queue.push(r-1);    Queue.push(c);
            }
        }
        if(r+1 < N) {
            if(T[r+1][c] == 0 || T[r+1][c] > d) {
                T[r+1][c] = d;
                Queue.push(r+1);    Queue.push(c);
            }
        }
        if(c-1 >= 0) {
            if(T[r][c-1] == 0 || T[r][c-1] > d) {
                T[r][c-1] = d;
                Queue.push(r);  Queue.push(c-1);
            }
        }
        if(c+1 < N) {
            if(T[r][c+1] == 0 || T[r][c+1] > d) {
                T[r][c+1] = d;
                Queue.push(r);  Queue.push(c+1);
            }
        }
                            
    }   //end while
    
    
}

int main(void) {
    int num;
    int R, C, K;
    int counting = 0;
    int i, j;
    
    scanf("%d", &N);
    
    for(i=0; i<N; i++) {
        for(j=0; j<N; j++) {
            scanf("%d", &num);
            if(num == 1) {  //건물(지나갈 수 없는 길)은 -1로 테이블에 저장
                T[i][j] = -1;
            }else {
                T[i][j] = num;
            }
        }
    }
    
    scanf("%d %d", &C, &R);
    scanf("%d", &K);
    
    bfs(R-1, C-1);
    T[R-1][C-1] = 0;
    
    for(i=0; i<N; i++) {
        for(j=0; j<N; j++) {
            if(T[i][j] == K) {
                counting++;
            }
        }
    }
    
    if(counting == 0 || N == 1) {
        printf("-1");
    }else {
        printf("%d", counting);
    }
    
    return 0;
}
