//
//  BISHOP2.cpp
//  AJ
//
//  Created by 송혜경 on 19/10/2019.
//  Copyright © 2019 송혜경. All rights reserved.
/* 그냥 bfs 탐색을 돌리면 시간초과
 !! 비숍을 대각선 이외의 방향은 공격 못함을 이용하자 ->
 N = 4 인 테이블에 대하여 하얀색(1)칸과 검은색(2)칸을 다음과 같이 나눌 때, 하얀색칸에 놓는 비숍과 검은색 칸에 놓는 비숍은 서로 영향을 절대 주지않는다
 1 2 1 2
 2 1 2 1
 1 2 1 2
 2 1 2 1
 
 따라서 (하얀색 칸에 놓을 수 있는 최대 비숍 수 + 검은색 칸에 놓을 수 있는 최대 비숍 수) 가 정답이 된다
 */

#include <stdio.h>


const int MAXN = 12;

int T[MAXN][MAXN] = {0, };  // 1 : 비숍 놓을 수 있음 , 0 : 없음
int WB[MAXN][MAXN] = {0, }; // 1 : 흰색 칸, 2: 검은색 칸
int visited[MAXN][MAXN] = {0, };
int N;
int maxWhite = 0;
int maxBlack = 0;

void dfs(int row, int col, int wb, int cc) {
    int temp[MAXN][MAXN] = {0, };
    
    int i, j;
    
    //하얀색과검은색 칸에 놓을 수 있는 최대 비숍 수를 업데이트
    if(wb == 1 && cc > maxWhite) {
        maxWhite = cc;
    }
    if(wb == 2 && cc > maxBlack) {
        maxBlack = cc;
    }
    
    //현재 테이블의 정보를 저장
    for(i=0; i<N; i++) {
        for(j=0; j<N; j++) {
            temp[i][j] = T[i][j];
        }
    }
    
    //방문처리
    visited[row][col] = 1;
    
    //현재 자리에 체스를 놓음으로서 못 놓는 자리에 대하여 -1로 업데이트
    for(i=1; i<N; i++) {
        //위쪽 대각선
        if(row-i >= 0 && col-i >= 0) {
            T[row-i][col-i] = -1;
        }
        if(row-i >= 0 && col+i < N) {
            T[row-i][col+i] = -1;
        }
        //아래 대각선
        if(row+i < N && col-i >= 0) {
            T[row+i][col-i] = -1;
        }
        if(row+i < N && col+i < N) {
            T[row+i][col+i] = -1;
        }
    }
    
    //비숍을 놓을 수 있는 자리에 대하여 dfs호출
    for(i=row; i<N; i++) {
        for(j=0; j<N; j++) {
            if(visited[i][j] == 0 && WB[i][j] == wb && T[i][j] == 1) {
                dfs(i, j, wb, cc+1);
                visited[i][j] = 0;
            }
        }
    }
    
    //원래의 테이블 정보로 다시 초기화
    for(i=0; i<N; i++) {
        for(j=0; j<N; j++) {
            T[i][j] = temp[i][j];
        }
    }
}

int main(void) {
    int p = 0;
    int i, j;
    
    scanf("%d", &N);
    
    for(i=0; i<N; i++) {
        if(p == 0) {
            for(j=0; j<N; j++) {
                scanf("%d", &T[i][j]);
                
                if(j == 0) {
                    WB[i][j] = 1;
                }else if(j % 2 == 0) {
                    WB[i][j] = 1;
                }else {
                    WB[i][j] = 2;
                }
                
            }
            p = 1;
        }else {
            for(j=0; j<N; j++) {
                scanf("%d", &T[i][j]);
                
                if(j == 0) {
                    WB[i][j] = 2;
                }else if(j % 2 == 1) {
                    WB[i][j] = 1;
                }else {
                    WB[i][j] = 2;
                }
            }
            p = 0;
        }
    }
    
    //하얀색 칸에 비숍을 놓는다
    for(i=0; i<N; i++) {
        for(j=0; j<N; j++) {
            if(T[i][j] == 1 && WB[i][j] == 1) {
                dfs(i, j, 1, 1);
            }
            if(T[i][j] == 1 && WB[i][j] == 2) {
                dfs(i, j, 2, 1);
            }
        }
    }
    
    printf("%d", maxWhite + maxBlack);
    
    return 0;
}

