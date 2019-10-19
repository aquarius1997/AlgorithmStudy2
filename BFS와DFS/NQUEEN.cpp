//
//  NQUEEN.cpp
//  AJ
//
//  Created by 송혜경 on 17/10/2019.
//  Copyright © 2019 송혜경. All rights reserved.
//
#include <stdio.h>

const int MAXN = 14;

int N;
int T[MAXN][MAXN] = {0, };
int visited[MAXN][MAXN] = {0, };
int c = 0;

void dfsS(int row, int col, int counting) {
    int i, j, k;
    int temp[MAXN][MAXN] = {0, };
    
    if(counting == N) {
        c++;    return;
    }
    
    //현재 줄부터 원래 테이블의 정보를 저장해둔다
    for(i=row; i<N; i++)
        for(j=0; j<N; j++)
            temp[i][j] = T[i][j];
    
    //퀸을 놓는다
    T[row][col] = 1;
    
    //퀸을 놓은 행의 아래 행부터 갈 수 없는 위치를 -1로 표시한다
    for(i=row+1; i<N; i++) {
        if(T[i][col] != 1)
            T[i][col] = -1;
    }
    for(k=1; k<N; k++) {
        if(row+k < N && col-k >= 0) {
            T[row+k][col-k] = -1;
        }
        if(row+k < N && col+k < N) {
            T[row+k][col+k] = -1;
        }
    }
    
    //다음 행에 대하여 퀸을 놓을 수 있는 자리(다음행의 모든 열)에 대하여 재귀 함수 호출
    for(j=0; j<N; j++) {
        if(T[row+1][j] == 0) {
            dfsS(row+1, j, counting+1);
        }
    }
    
    //원래 테이블의 정보를 저장한다
    for(i=row; i<N; i++)
        for(j=0; j<N; j++)
            T[i][j] = temp[i][j];
    
}


int main(void) {
    
    scanf("%d", &N);
    
    //한 행에는 무조건 1개의 퀸을 놓아야만 N개의 퀸을 놓을 수 있으므로
    //0번째 행의 모든 열에 대하여 함수 호출하면된다
    for(int j=0; j<N; j++) {
        dfsS(0, j, 1);
    }
    
    printf("%d", c);
    
    return 0;
    
}
