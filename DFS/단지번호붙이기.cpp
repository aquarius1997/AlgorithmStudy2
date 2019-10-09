//
//  단지번호붙이기.cpp
//  AJ
//
//  Created by 송혜경 on 09/10/2019.
//  Copyright © 2019 송혜경. All rights reserved.
//

#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 30;
int visited[MAXN][MAXN] = {0, };
int T[MAXN][MAXN];
int num = 0;    int counting = 0;
int N;

void dfs(int x, int y) {
    
    visited[x][y] = num;
    counting++;
    
    if(x-1 >= 0) {
        if(T[x-1][y] == 1 && visited[x-1][y] == 0) {
            dfs(x-1, y);
        }
    }
    if(x+1 < N) {
        if(T[x+1][y] == 1 && visited[x+1][y] == 0) {
            dfs(x+1, y);
        }
    }
    if(y-1 >= 0) {
        if(T[x][y-1] == 1 && visited[x][y-1] == 0) {
            dfs(x, y-1);
        }
    }
    if(y+1 < N) {
        if(T[x][y+1] == 1 && visited[x][y+1] == 0) {
            dfs(x, y+1);
        }
    }
}

int main(void) {
    int i, j;
    int arr[MAXN] = {0, };
    char str[MAXN];
    int idx = 0;
    
    scanf("%d", &N);
    
    for(i=0; i<N; i++) {
        scanf("%s", str);
        
        for(j=0; j<N; j++) {
            if(str[j] == '0') {
                T[i][j] = 0;
            }else {
                T[i][j] = 1;
            }
        }
    }
    
    for(i=0; i<N; i++) {
        for(j=0; j<N; j++) {
            if(T[i][j] == 1 && visited[i][j] == 0) {
                num++;
                counting = 0;
                dfs(i, j);
                arr[idx++] = counting;
            }
        }
    }
    
    sort(arr, arr+idx);
    
    printf("%d\n", num);
    
    for(i=0; i<idx; i++) {
        printf("%d\n", arr[i]);
    }
    
    return 0;
}
