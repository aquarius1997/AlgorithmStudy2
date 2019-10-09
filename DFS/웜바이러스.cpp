//
//  웜바이러스.cpp
//  AJ
//
//  Created by 송혜경 on 09/10/2019.
//  Copyright © 2019 송혜경. All rights reserved.
//

//정점 1번으로 dfs 탐색 가능한 노드의 수를 구한다

#include <cstdio>
#include <vector>

using namespace std;

const int MAXN = 102;

vector <int> Graph[MAXN];
int visited[MAXN] = {0, };
int counting;

void dfs(int node) {
    int w;
    int i;
    
    visited[node] = 1;
    counting++;
    
    for(i=0; i<Graph[node].size(); i++) {
        w = Graph[node][i];
        
        if(visited[w] == 0) {
            dfs(w);
        }
    }
}

int main(void) {
    int N, M, a, b;
    int i;
    
    scanf("%d", &N);
    scanf("%d", &M);
    
    counting = 0;
    
    for(i=0; i<M; i++) {
        scanf("%d %d", &a, &b);
        
        Graph[a].push_back(b);
        Graph[b].push_back(a);
    }
    
    dfs(1);
    
    printf("%d", counting-1);
    
    return 0;
}
