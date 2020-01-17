//
//  깊이우선탐색과너비우선탐색.cpp
//  AJ
//
//  Created by 송혜경 on 09/10/2019.
//  Copyright © 2019 송혜경. All rights reserved.
//
//c++ STL (vector)를 사용해서 그래프를 만듦

#include <cstdio>
#include <vector>
#include <queue>
#define NODEN   1002

using namespace std;

//그래프
vector <int> Graph[NODEN];
//노드 방문 여부를 표시
int visited[NODEN] = {0, };
//bfs탐색에 사용할 큐
queue <int> Queue;

//dfs탐색
void dfs(int node) {
    int i;
    int minNode;
    int count;
    
    visited[node] = 1;
    printf("%d ", node);
    
    //모든 인접정점에 대하여 dfs호출 여부를 확인
    while(1) {
        
        minNode = 987987987;
        count = 0;
        
        //정점node의 인접정점들에 대하여 for문 탐색
        for(i=0; i<Graph[node].size(); i++) {
            //방문안한 인접정점이면서 정점번호가 최소인 노드를 찾는다
            if(visited[(Graph[node][i])] == 0) {
                if(minNode > Graph[node][i]) {
                    minNode = Graph[node][i];
                }
                count++;
            }
        }
        
        //방문안한 인접정점 있으면
        if(count > 0) {
            dfs(minNode);
        }else   break;
        
    }
}

//bfs탐색
void bfs(int node) {
    int w;
    int minNode, count;
    int i;
    
    //첫 정점 삽입
    Queue.push(node);   visited[node] = 1;
    
    //큐가 빌때까지 반복한다
    while(!Queue.empty()) {
        //큐 선단에서 꺼낸 정점에 대하여
        w = Queue.front();  Queue.pop();
        printf("%d ", w);
        
        while(1) {
            count = 0;
            minNode = 987987987;
            
            //노드번호가 최소인 인접정점을 찾는다
            for(i=0; i<Graph[w].size(); i++) {
                //방문안한 인접정점일 경우 큐에 삽입하며 방문함을 표시한다
                if(visited[(Graph[w][i])] == 0) {
                    if(minNode > Graph[w][i]) {
                        minNode = Graph[w][i];
                    }
                    count++;
                }
            }
            
            if(count > 0) {
                Queue.push(minNode);
                visited[minNode] = 1;
            }else {
                break;
            }
        
        }
        
    }
    
}


int main(void) {
    int N, M, a, b;
    int i;
    
    scanf("%d %d", &N, &M);
    
    //간선정보를 입력받으면서 그래프를 초기화한다 (무방향)
    for(i=0; i<M; i++) {
        scanf("%d %d", &a, &b);
        Graph[a].push_back(b);
        Graph[b].push_back(a);
    }
    
    dfs(0);
    printf("\n");
    
    //방문 여부 초기화
    for(i=0; i<N; i++) {
        visited[i] = 0;
    }
    
    bfs(0);
    
    return 0;
}
