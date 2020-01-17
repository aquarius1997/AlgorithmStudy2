//
//  CONNECTEDCOMP.cpp
//  AJ
//
//  Created by 송혜경 on 10/10/2019.
//  Copyright © 2019 송혜경. All rights reserved.
//
//  DFS 탐색을 통하여 문제 해결

#include <cstdio>
#include <vector>

using namespace std;

const int NODEM = 1002;

//connected componenet의 수
int cc = 0;
vector <int> Graph[NODEM];
int visited[NODEM] = {0, };

void dfs(int node) {
    int i;
    
    visited[node] = 1;
    
    //node의 인접정점들에 대하여
    for(i=0; i<Graph[node].size(); i++) {
        //방문안했을경우 DFS호출
        if(visited[Graph[node][i]] == 0) {
            dfs(Graph[node][i]);
        }
    }
}

int main(void) {
    int V, E, v1, v2;
    int i;
    
    scanf("%d %d", &V, &E);
    
    for(i=0; i<E; i++) {
        scanf("%d %d", &v1, &v2);
        
        Graph[v1].push_back(v2);
        Graph[v2].push_back(v1);
    }
    
    for(i=1; i<=V; i++) {
        if(visited[i] == 0) {
            cc++;
            dfs(i);
        }
    }
    
    printf("%d", cc);
    
    return 0;
}

