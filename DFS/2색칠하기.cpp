//
//  2색칠하기.cpp
//  AJ
//
//  Created by 송혜경 on 09/10/2019.
//  Copyright © 2019 송혜경. All rights reserved.
// 기계식 키보드 처음써보는데 죻넹?

/*
 방문안한 인접정점은 다른색으로 칠하고
 방문한 인접정점은 다른색으로 칠해져 있는지 검증한다
 */

#include <cstdio>
#include <vector>
using namespace std;

const int NODEN=100002;

vector <int> Graph[NODEN];
int visited[NODEN] = {0, };
int flag = 0;

void dfs(int node) {
    int i;
    
    for(i=0; i<Graph[node].size(); i++) {
        //방문안한 인접노드이면
        if(visited[Graph[node][i]] == 0) {
            //현재 노드와 반대 색으로 칠함
            if(visited[node] == 1) {
                visited[Graph[node][i]] = 2;
            }else {
                visited[Graph[node][i]] = 1;
            }
            //dfs호출
            dfs(Graph[node][i]);
        }else {
            //방문한 인접노드이면 다른색으로 칠해져있는지 확인
            if(visited[node] == 1) {
                if(visited[Graph[node][i]] != 2) {
                    flag = 1;
                }
            }else {
                if(visited[Graph[node][i]] != 1) {
                    flag = 1;
                }
            }
        }
    }
}

int main(void) {
    int N, M, a, b;
    int i;
    
    scanf("%d %d", &N, &M);
    
    for(i=0; i<M; i++) {
        scanf("%d %d", &a, &b);
        Graph[a].push_back(b);
        Graph[b].push_back(a);
    }
    
    //0번정점부터 시작할거임
    visited[0] = 1;
    dfs(0);
    
    if(flag == 1){
        printf("NO");
    }else {
        printf("YES");
    }
    
    return 0;
    
}

