//
//  TRESURE.cpp
//  AJ
//
//  Created by 송혜경 on 15/10/2019.
//  Copyright © 2019 송혜경. All rights reserved.
//

#include <cstdio>
#include <queue>

using namespace std;

const int MAXN = 55;
int N, M;
int T[MAXN][MAXN] = {0, };  //입력으로 받은 테이블 정보
int distT[MAXN][MAXN] = {0, };
queue <int> Queue;
int maxD = -987987987;


void bfs(int row, int col) {
    int i, j, d;
    
    Queue.push(row);    Queue.push(col);
    
    while(!Queue.empty()) {
        i = Queue.front();  Queue.pop();
        j = Queue.front();  Queue.pop();
        d = distT[i][j] + 1;
        
        //위쪽 확인
        if(i-1 >= 0) {
            if(distT[i-1][j] == 0 || distT[i-1][j] > d) {
                distT[i-1][j] = d;
                Queue.push(i-1);    Queue.push(j);
            }
        }   //end 위쪽확인
        //아래쪽 확인
        if(i+1 < N) {
            if(distT[i+1][j] == 0 || distT[i+1][j] > d) {
                distT[i+1][j] = d;
                Queue.push(i+1);    Queue.push(j);
            }
        }   //end 아래쪽 확인
        //왼쪽 확인
        if(j-1 >= 0) {
            if(distT[i][j-1] == 0 || distT[i][j-1] > d) {
                distT[i][j-1] = d;
                Queue.push(i);  Queue.push(j-1);
            }
        }   //end 왼쪽확인
        if(j+1 < M) {
            if(distT[i][j+1] == 0 || distT[i][j+1] > d) {
                distT[i][j+1] = d;
                Queue.push(i);  Queue.push(j+1);
            }
        }
    }
}

void refresh(void) {
    int i, j;
    
    for(i=0; i<N; i++) {
        for(j=0; j<M; j++) {
            if(maxD < distT[i][j])
                maxD = distT[i][j];
            distT[i][j] = T[i][j];
        }
    }
}


int main(void) {
    char str[55];
    int i, j;
    
    scanf("%d %d", &N, &M);
    
    for(i=0; i<N; i++) {
        scanf("%s", str);
        for(j=0; j<M; j++) {
            if(str[j] == 'W') { //갈 수 없을 경우 -1로 저장
                distT[i][j] = T[i][j] = -1;
            }else {
                distT[i][j] = T[i][j] = 0;
            }
        }
    }
    
    for(i=0; i<N; i++) {
        for(j=0; j<M; j++) {
            if(T[i][j] == 0) {
                bfs(i, j);
                distT[i][j] = 0;
                refresh();
            }
        }
    }
    
    
    printf("%d", maxD);
    
    return 0;
}
