//
//  SLIKAR.cpp
//  AJ
//
//  Created by 송혜경 on 14/10/2019.
//  Copyright © 2019 송혜경. All rights reserved.
//

/*
 BFS 활용
 1. 각 위치로의 물의 최소 이동 시간을 구한다
 2. 각 위치로의 고슴도치 최소 이동시간을 구한다. 이때, 물의 최소 이동 시간보다 더 작아야만 이동 가능함을 주의한다
 */

#include <cstdio>
#include <queue>

using namespace std;

const int MAXN = 53;
int s_r, s_c, d_r, d_c, w_r ,w_c;

int R, C;
int T[MAXN][MAXN] = {0, };


void bfs(int row, int col) {
    queue <int> Queue;
    int i, j, d;
    
    Queue.push(row);    Queue.push(col);
    
    //큐가 빌때까지 반복한다. visited필요없음
    while(!Queue.empty()) {
        i = Queue.front();  Queue.pop();
        j = Queue.front();  Queue.pop();
        
        d = T[i][j] + 1;    //다음으로 이동할 위치의 최소 이동 시간
        
        //상하좌우 확인
        if(i-1 >= 0) {
            if(T[i-1][j] == 0 || T[i-1][j] > d) {
                T[i-1][j] = d;
                Queue.push(i-1);    Queue.push(j);
            }
        }   //end 위쪽 확인
        if(i+1 < R) {
            if(T[i+1][j] == 0 || T[i+1][j] > d) {
                T[i+1][j] = d;
                Queue.push(i+1);    Queue.push(j);
            }
        }   //end 아래쪽 확인
        if(j-1 >= 0) {
            if(T[i][j-1] == 0 || T[i][j-1] > d) {
                T[i][j-1] = d;
                Queue.push(i);  Queue.push(j-1);
            }
        }   //end 왼쪽 확인
        if(j+1 < C) {
            if(T[i][j+1] == 0 || T[i][j+1] > d) {
                T[i][j+1] = d;
                Queue.push(i);  Queue.push(j+1);
            }
        }   //end 오른쪽 확인
        
        
    }   //end while
    
}

int main(void) {
    char str[MAXN];
    int flag = 0;
    int i, j;
    
    scanf("%d %d", &R, &C);
    
    for(i=0; i<R; i++) {
        scanf("%s", str);
        
        for(j=0; j<C; j++) {
            if(str[j] == '.') { //비어있는 갈 수 있는 길
                T[i][j] = 0;
            }else if(str[j] == '*') {   //물
                T[i][j] = 0;
                w_r = i;    w_c = j;
            }else if(str[j] == 'X') {   //돌 (= 갈 수 없는 길)
                T[i][j] = -1;
            }else if(str[j] == 'D') {   //비버굴 위치
                T[i][j] = 0;
                d_r = i;    d_c = j;
            }else { //고슴도치 시작점
                T[i][j] = 0;
                s_r = i;    s_c = j;
            }
        }
        
    }
    
    
    //물의 최소 이동 시간을 구한다
    //이때 비버굴은 못가도록 -1로 초기화
    T[d_r][d_c] = -1;
    bfs(w_r, w_c);
    T[w_r][w_c] = 0;
    

    //비버굴로 갈 수 있도록 초기화
    T[d_r][d_c] = 0;
    T[s_r][s_c] = 0;
    bfs(s_r, s_c);
    T[s_r][s_c] = 0;
    
    
    if(T[d_r][d_c] == 0) {  //도달 못함
        flag = 1;
    }else {
        printf("%d", T[d_r][d_c]);
    }
    
    if(flag == 1) {
        printf("KAKTUS");
    }
    
    return 0;
}

