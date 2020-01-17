//
//  목수의 미로탈출.cpp
//  AJ
//
//  Created by 송혜경 on 09/10/2019.
//  Copyright © 2019 송혜경. All rights reserved.
//
//이거 처음풀때 진짜 시간초과때문에 쥬거씀... 코칭님께서 도와주신 코드이니 꼭꼭 해결방법 혼자 떠올려 봐야함

#include <cstdio>
#include <queue>

using namespace std;

const int MAXN = 1002;

queue <int> Queue;
int N, M;

//출발지점으로 부터 각 길의 최단거리를 구하는 함수
void getMinDist(int T[MAXN][MAXN], int x, int y) {
    int row, col;
    int dist;
    
    Queue.push(x);  Queue.push(y);
    
    while(!Queue.empty()) {
        row = Queue.front();    Queue.pop();
        col = Queue.front();    Queue.pop();
        
        dist = T[row][col] + 1;
        
        if(row-1 >= 0) {
            if(T[row-1][col] == 0 || T[row-1][col] > dist) {
                T[row-1][col] = dist;
                Queue.push(row-1);  Queue.push(col);
            }
        }
        if(row+1 < N) {
            if(T[row+1][col] == 0 || T[row+1][col] > dist) {
                T[row+1][col] = dist;
                Queue.push(row+1);  Queue.push(col);
            }
        }
        if(col-1 >= 0) {
            if(T[row][col-1] == 0 || T[row][col-1] > dist) {
                T[row][col-1] = dist;
                Queue.push(row);    Queue.push(col-1);
            }
        }
        if(col+1 < M) {
            if(T[row][col+1] == 0 || T[row][col+1] > dist) {
                T[row][col+1] = dist;
                Queue.push(row);    Queue.push(col+1);
            }
        }
    }
}

int main(void) {
    int T[MAXN][MAXN];  //입력 테이블
    int start[MAXN][MAXN] = {0, };  //출발지점에서 도착지점까지 최단거리로 갈 때에 대한 정보
    int end[MAXN][MAXN] = {0, };    //도착지점에서 출발지점까지 최단거기로 갈 때에 대한 정보
    int num;
    int minD = 987987987;
    int i, j;
    
    scanf("%d %d", &N, &M);
    
    for(i=0; i<N; i++) {
        for(j=0; j<M; j++) {
            scanf("%d", &num);
            
            if(num == 0) {
                T[i][j] = start[i][j] = end[i][j] = 0;
            }else { //이동할 수 없는 부분은 -1로 초기화
                T[i][j] = start[i][j] = end[i][j] = -1;
            }
        }
    }
    
    //시작지점에서 출발했을 경우의 최단거리 테이블 정보를 구한다
    start[N-1][0] = 1;
    getMinDist(start, N-1, 0);
  //  start[N-1][0] = 0;
    //끝 지점에서 출발했을 경우의 최단거리 테이블 정보를 구한다
    end[0][M-1]= 1;
    getMinDist(end, 0, M-1);
//    end[0][M-1] = 0;

    //벽을 부시는 경우에 대해서 하나씩 실행
    for(i=0; i<N; i++) {
        for(j=0; j<M; j++) {
            if(T[i][j] == -1) {
                
                //벽의 위쪽이 뚫려있으면
                if(i-1 >= 0) {
                    if(start[i-1][j] > 0) {
                        //나머지 세 방향이 벽이 아닌지 확인하고 벽이 아닐 경우 end에서 출발할 경우와 더해 최소 거리를 update한다
                        if(j-1 >= 0) {  //벽 왼쪽 확인
                            if(end[i][j-1] > 0) {
                                if(start[i-1][j] + end[i][j-1] < minD) {
                                    minD = start[i-1][j] + end[i][j-1];
                                }
                            }
                        }//end  벽의 왼쪽 확인
                        
                        if(i+1 < N) {   //벽의 아래 확인
                            if(end[i+1][j] > 0) {
                                if(start[i-1][j] + end[i+1][j] < minD) {
                                    minD = start[i-1][j] + end[i+1][j];
                                }
                            }
                        }   //end 벽의 아래 확인
                        
                        if(j+1 < M) {   //벽의 오른쪽 확인
                            if(end[i][j+1] > 0) {
                                if(start[i-1][j] + end[i][j+1] < minD) {
                                    minD = start[i-1][j] + end[i][j+1];
                                }
                            }
                        }   //end 벽의 오른쪽 확인
                        
                    }
                }   //end 벽의 위쪽이 뚫려있으면
                
                if(i+1 < N) {   //벽의 아래쪽이 뚫려있으면
                    if(start[i+1][j] > 0){
                        
                        if(j-1 >= 0) {  //벽 왼쪽 확인
                            if(end[i][j-1] > 0) {
                                if(start[i+1][j] + end[i][j-1] < minD) {
                                    minD = start[i+1][j] + end[i][j-1];
                                }
                            }
                        }//end  벽의 왼쪽 확인
                        
                        if(i-1 >= 0) {  //벽의 위쪽 확인
                            if(end[i-1][j] > 0) {
                                if(start[i+1][j] + end[i-1][j] < minD) {
                                    minD = start[i+1][j] + end[i-1][j];
                                }
                            }
                        }   //end 벽의 위쪽 확인
                        
                        if(j+1 < M) {   //벽의 오른쪽 확인
                            if(end[i][j+1] > 0) {
                                if(start[i+1][j] + end[i][j+1] < minD) {
                                    minD = start[i+1][j] + end[i][j+1];
                                }
                            }
                        }   //end 벽의 오른쪽 확인
                        
                    }
                }   //end 벽의 아래쪽이 뚫려있으면
                
                
                if(j-1 >= 0) {  //벽의 왼쪽이 뚫려있으면
                    if(start[i][j-1] > 0) {
                        
                        if(i-1 >= 0) {  //벽의 위쪽 확인
                            if(end[i-1][j] > 0) {
                                if(start[i][j-1] + end[i-1][j] < minD) {
                                    minD = start[i][j-1] + end[i-1][j];
                                }
                            }
                        }   //end 벽의 위쪽 확인
                        
                        if(j+1 < M) {   //벽의 오른쪽 확인
                            if(end[i][j+1] > 0) {
                                if(start[i][j-1] + end[i][j+1] < minD) {
                                    minD = start[i][j-1] + end[i][j+1];
                                }
                            }
                        }   //end 벽의 오른쪽 확인
                        
                        
                        if(i+1 < N) {   //벽의 아래 확인
                            if(end[i+1][j] > 0) {
                                if(start[i][j-1] + end[i+1][j] < minD) {
                                    minD = start[i][j-1] + end[i+1][j];
                                }
                            }
                        }   //end 벽의 아래 확인
                    }
                }   //end 벽의 왼쪽이 뚫려있으면
                
                if(j+1 < M) {   //if 벽의 오른쪽이 뚫려있으면
                    if(start[i][j+1] > 0){
                        
                        if(i+1 < N) {   //벽의 아래 확인
                            if(end[i+1][j] > 0) {
                                if(start[i][j+1] + end[i+1][j] < minD) {
                                    minD = start[i][j+1] + end[i+1][j];
                                }
                            }
                        }   //end 벽의 아래 확인
                        
                        if(j-1 >= 0) {  //벽 왼쪽 확인
                            if(end[i][j-1] > 0) {
                                if(start[i][j+1] + end[i][j-1] < minD) {
                                    minD = start[i][j+1] + end[i][j-1];
                                }
                            }
                        }//end  벽의 왼쪽 확인
                        
                        if(i-1 >= 0) {  //벽의 위쪽 확인
                            if(end[i-1][j] > 0) {
                                if(start[i][j+1] + end[i-1][j] < minD) {
                                    minD = start[i][j+1] + end[i-1][j];
                                }
                            }
                        }   //end 벽의 위쪽 확인
                    }
                }   //end 벽의 오른쪽이 뚫려있으면
                
                
            }   //end if(T[i][j] == -1)
        }   //end inner for
    }   //end outer for
    
    
    printf("%d", minD);
    
    
    return 0;
}

