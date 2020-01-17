//
//  SAFETYZONE.cpp
//  AJ
//
//  Created by 송혜경 on 15/10/2019.
//  Copyright © 2019 송혜경. All rights reserved.
//

#include <stdio.h>

const int MAXN = 105;

int N;
int counting;
int T[MAXN][MAXN] = {0, };
int visited[MAXN][MAXN] = {0, };

void dfs(int h, int i, int j) {
    
    visited[i][j] = 1;
    
    //위
    if(i-1 >= 0) {
        if(T[i-1][j] > h && visited[i-1][j] == 0) {
            dfs(h, i-1, j);
        }
    }
    //아래
    if(i+1 < N) {
        if(T[i+1][j] > h && visited[i+1][j] == 0) {
            dfs(h, i+1,j);
        }
    }
    //왼쪽
    if(j-1 >= 0) {
        if(T[i][j-1] > h && visited[i][j-1] == 0) {
            dfs(h, i, j-1);
        }
    }
    //오른쪽
    if(j+1 < N) {
        if(T[i][j+1] > h && visited[i][j+1] == 0) {
            dfs(h, i, j+1);
        }
    }
}

int main(void) {
    int maxH = 0;
    int maxCount;
    int i, j, h;
    
    scanf("%d", &N);
    
    //높이 정보를 입력받는다
    for(i=0; i<N; i++) {
        for(j=0; j<N; j++) {
            scanf("%d", &T[i][j]);
            //최대 높이를 알아낸다
            if(T[i][j] > maxH) {
                maxH = T[i][j];
            }
        }
    }
    
    //비가 0만큼 올 경우로 최대 안전한 영역의 수를 초기화한다
    maxCount = 1;
    
    //(최대높이-1)까지 반복하며 안전한 영역의 개수를 알아낸다
    for(h=1; h<maxH; h++) {
        
        //비가 h만큼 왔을 때 안전한 영역 개수를 구한다
        counting = 0;
        for(i=0; i<N; i++) {
            for(j=0; j<N; j++){
                
                //h보다 높이고 높고 방문 안한 영역에 대하여 dfs 호출한다
                if(T[i][j] > h && visited[i][j] == 0){
                    counting++;
                    dfs(h, i, j);
                }
                
            }   //end for(j)
        }   //end for(i)
        
        //최대 안전한 영역의 수를 업데이트 할 수 있는지 확인한다
        if(counting > maxCount)
            maxCount = counting;
        
        //visited 배열을 초기화
        for(i=0; i<N; i++) {
            for(j=0; j<N; j++) {
                visited[i][j] = 0;
            }
        }
        
    }   //end for(h)
    
    printf("%d", maxCount);
    
    return 0;
    
}
