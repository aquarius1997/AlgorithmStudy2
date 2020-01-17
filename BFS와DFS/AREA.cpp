//
//  AREA.cpp
//  AJ
//
//  Created by 송혜경 on 15/10/2019.
//  Copyright © 2019 송혜경. All rights reserved.
//

#include <cstdio>
#include <algorithm>

using namespace std;

int N, M, K;
const int MAXN = 105;
int T[MAXN][MAXN] = {0, };
int visited[MAXN][MAXN] = {0, };
int counting = 0;

void dfs(int row, int col) {
    
    visited[row][col] = 1;
    counting += 1;
    
    if(row-1 >= 0) {
        if(visited[row-1][col] == 0 && T[row-1][col] == 0) {
            dfs(row-1, col);
        }
    }
    if(row+1 < M) {
        if(visited[row+1][col] == 0 && T[row+1][col] == 0) {
            dfs(row+1, col);
        }
    }
    if(col-1 >= 0) {
        if(visited[row][col-1] == 0 && T[row][col-1] == 0) {
            dfs(row, col-1);
        }
    }
    if(col+1 < N) {
        if(visited[row][col+1] == 0 && T[row][col+1] == 0) {
            dfs(row, col+1);
        }
    }
}

int main(void) {
    int arr[MAXN*2] = {0, };    int idx = 0;
    int a, b, c, d;
    int callCount = 0;
    int i, j, k;
    int row1, row2, col1, col2;
    
    scanf("%d %d %d", &M, &N, &K);
    
    for(k=0; k<K; k++) {
        scanf("%d %d %d %d", &a, &b, &c, &d);
        
        row1 = (M-1) - d + 1;
        row2 = (M-1) - b;
        col1 = a;
        col2 = c - 1;
        
        //입력받은 직사각형의 범위에 대하여 탐색 못하는 범위로 설정한다
        for(i=row1; i<=row2; i++) {
            for(j=col1; j<=col2; j++) {
                T[i][j] = -1;
            }
        }
    }
    
    for(i=0; i<M; i++) {
        for(j=0; j<N; j++) {
            if(T[i][j] == 0 && visited[i][j] == 0) {
                callCount += 1;
                counting = 0;
                dfs(i, j);
                arr[idx++] = counting;
            }
        }
    }
    
    sort(arr, arr+idx);
    
    printf("%d\n", callCount);
    
    for(i=0; i<idx; i++) {
        printf("%d ", arr[i]);
    }
    
    return 0;
    
}
