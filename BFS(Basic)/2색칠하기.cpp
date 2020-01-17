//
//  2색칠하기.cpp
//  AJ
//
//  Created by 송혜경 on 09/10/2019.
//  Copyright © 2019 송혜경. All rights reserved.
//

#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

const int NODEN=100002;

vector <int> Graph[NODEN];
queue <int> Queue;

int visited[NODEN] = {0, };
int flag = 0;

void bfs(int node) {
    int w;
    int i;
    
    while(!Queue.empty()) {
        w = Queue.front();  Queue.pop();
        
        for(i=0; i<Graph[w].size(); i++) {
            if(visited[Graph[w][i]] == 0) {
                if(visited[w] == 1) {
                    visited[Graph[w][i]] = 2;
                }else {
                    visited[Graph[w][i]] = 1;
                }
                Queue.push(Graph[w][i]);
            }else {
                if(visited[w] == 1) {
                    if(visited[Graph[w][i]] != 2) {
                        flag = 1;
                    }
                }else {
                    if(visited[Graph[w][i]] != 1) {
                        flag = 1;
                    }
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
    Queue.push(0);
    
    bfs(0);
    
    if(flag == 1){
        printf("NO");
    }else {
        printf("YES");
    }
    
    return 0;
    
}

