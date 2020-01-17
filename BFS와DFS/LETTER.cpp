//
//  LETTER.cpp
//  AJ
//
//  Created by 송혜경 on 15/10/2019.
//  Copyright © 2019 송혜경. All rights reserved.
//

#include <stdio.h>

int visited[30] = {0, };
char T[30][30] = {0, };
int R, C;
int maxD = 0;

void dfs(int row, int col, int c) {
    
    
    visited[(T[row][col] - 'A')] = 1;
    
    if(c > maxD)
        maxD = c;
    
    if(row-1 >= 0) {
        if(visited[(T[row-1][col] - 'A')] == 0) {
            dfs(row-1, col, c+1);
        }
    }
    if(row+1 < R) {
        if(visited[(T[row+1][col] - 'A')] == 0) {
            dfs(row+1, col, c+1);
        }
    }
    if(col-1 >= 0) {
        if(visited[(T[row][col-1] - 'A')] == 0) {
            dfs(row, col-1, c+1);
        }
    }
    if(col+1 < C) {
        if(visited[(T[row][col+1] - 'A')] == 0) {
            dfs(row, col+1, c+1);
        }
    }
    
    visited[(T[row][col] - 'A')] = 0;
}

int main(void) {
    char str[30];
    int i, j;
    
    scanf("%d %d", &R, &C);
    
    //입력 초기화
    for(i=0; i<R; i++) {
        scanf("%s", str);
        
        for(j=0; j<C; j++) {
            T[i][j] = str[j];
        }
    }
    
    
    dfs(0, 0, 1);
    
    printf("%d", maxD);
    
    return 0;
}
