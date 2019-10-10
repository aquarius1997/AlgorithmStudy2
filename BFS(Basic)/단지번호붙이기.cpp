//
//  단지번호붙이기.cpp
//  AJ
//
//  Created by 송혜경 on 09/10/2019.
//  Copyright © 2019 송혜경. All rights reserved.
//

#include <cstdio>
#include <queue>
#include <algorithm>

using namespace std;

const int MAXN = 30;
int T[MAXN][MAXN];
int visited[MAXN][MAXN] = {0, };
int counting;
int N;

queue <int> Queue;

void bfs(int x, int y) {
    int row, col;
    
    Queue.push(x);  Queue.push(y);
    visited[x][y] = 1;
    counting++;
    
    while(!(Queue.empty())) {
        row = Queue.front();    Queue.pop();
        col = Queue.front();    Queue.pop();
        
        if(row-1 >= 0) {
            if(visited[row-1][col] == 0 && T[row-1][col] == 1) {
                visited[row-1][col] = 1;
                Queue.push(row-1);  Queue.push(col);
                counting++;
            }
        }   //end if(row-1 >= 0)
        if(row+1 < N) {
            if(visited[row+1][col] == 0 && T[row+1][col] == 1) {
                visited[row+1][col] = 1;
                Queue.push(row+1);  Queue.push(col);
                counting++;
            }
        }   //end if(row+1 < N)
        if(col-1 >= 0) {
            if(visited[row][col-1] == 0 && T[row][col-1] == 1) {
                visited[row][col-1] = 1;
                Queue.push(row);    Queue.push(col-1);
                counting++;
            }
        }   //end if(col-1 >= 0)
        if(col+1 < N) {
            if(visited[row][col+1] == 0 && T[row][col+1] == 1) {
                visited[row][col+1] = 1;
                Queue.push(row);    Queue.push(col+1);
                counting++;
            }
        }   //end if(col+1 < N)
    }
}


int main(void) {
    char str[MAXN];
    int arr[MAXN*MAXN] = {0, }; int idx=0;
    int i, j;
    
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
            if(visited[i][j] == 0 && T[i][j] == 1) {
                counting = 0;
                bfs(i, j);
                arr[idx++] = counting;
            }
        }
    }

    sort(arr, arr+idx);
    
    printf("%d\n", idx);
    for(i=0; i<idx; i++) {
        printf("%d\n", arr[i]);
    }
    
    return 0;
}
