//
//  ICEBERG.cpp
//  AJ
//
//  Created by 송혜경 on 17/10/2019.
//  Copyright © 2019 송혜경. All rights reserved.
//
/*
 1. round 함수에서 현재 빙산모습에 대한 1시간 이후의 빙산모습을 구한다
 2. round 함수에서 dfs탐색을 호출하여 빙산이 2개 이상 분리되었는지 검증한다
 3. 빙산이 2개 이상 분리되지 않으면 다시 round 함수 실행, 분리되면 종료
 */

#include <stdio.h>

void dfs(int row, int col);

const int MAXN = 303;

int N, M;
int T[MAXN][MAXN] = {0, };  //현재 빙산
int tempT[MAXN][MAXN] = {0, };  //1시간 이후의 빙산
int visited[MAXN][MAXN] = {0, };

//t시간 이후의 빙산 모습을 만드는 함수
int round(int t) {
    int i, j;
    int c;
    int dfsCallCount, iceberg;
    
    
    //현재 빙산을 토대로 1시간 이후의 빙산 모습을 구한다
    for(i=0; i<N; i++) {
        for(j=0; j<M; j++) {
            
            c = 0;  //초기화
            
            //빙산일 경우 상하좌우 바다 면적을 구해서 뺀다 (이때 뺀 결과는 무조건 0이상임을 유의하자)
            if(T[i][j] > 0) {
                
                if(i-1 >= 0) {
                    if(T[i-1][j] == 0) {
                        c++;
                    }
                }
                if(i+1 < N) {
                    if(T[i+1][j] == 0) {
                        c++;
                    }
                }
                if(j-1 >= 0) {
                    if(T[i][j-1] == 0) {
                        c++;
                    }
                }
                if(j+1 < M) {
                    if(T[i][j+1] == 0) {
                        c++;
                    }
                }
            }   //end if(빙산의 상하좌우 바다 면적 구하기)
            
            tempT[i][j] = T[i][j] - c;
            if(tempT[i][j] < 0) {   //모두 녹은 경우
                tempT[i][j] = 0;
            }
            
        }
    }   //end 1시간 이후의 빙산 면적 구하기
    
    dfsCallCount = 0;
    
    for(i=0; i<N; i++) {
        for(j=0; j<M; j++) {
            if(visited[i][j] == 0 && tempT[i][j] > 0) {
                dfs(i, j);
                dfsCallCount++;
            }
        }
    }

    
    //빙하가 2개 이상으로 분리되었다면
    if(dfsCallCount > 1) {
        return t;
    }else { //분리 안되었으면 더녹여야 한다
        
        iceberg = 0;
        
        //tempT를 T에 옮겨 저장하면서 남아있는 빙하 수를 카운트 + visited 배열 초기화
        for(i=0; i<N; i++) {
            for(j=0; j<M; j++) {
                if(tempT[i][j] > 0) {
                    iceberg++;
                }
                T[i][j] = tempT[i][j];
                visited[i][j] = 0;
            }
        }
        
        //만약 녹일 빙하가 없으면
        if(iceberg == 0) {
            return 0;
        }else {
            return round(t+1);
        }
        
    }
}

void dfs(int row, int col) {
    
    visited[row][col] = 1;
    
    if(row-1 >= 0) {
        if(tempT[row-1][col] > 0 && visited[row-1][col] == 0) {
            dfs(row-1, col);
        }
    }
    if(row+1 < N) {
        if(tempT[row+1][col] > 0 && visited[row+1][col] == 0) {
            dfs(row+1, col);
        }
    }
    if(col-1 >= 0) {
        if(tempT[row][col-1] > 0 && visited[row][col-1] == 0) {
            dfs(row, col-1);
        }
    }
    if(col+1 < M) {
        if(tempT[row][col+1] > 0 && visited[row][col+1] == 0) {
            dfs(row, col+1);
        }
    }
}

int main(void) {
    int i, j;
    
    scanf("%d %d", &N, &M);
    
    for(i=0; i<N; i++) {
        for(j=0; j<M; j++) {
            scanf("%d", &T[i][j]);
            tempT[i][j] = T[i][j];
        }
    }
    
    printf("%d", round(1));
    
    return 0;

}
