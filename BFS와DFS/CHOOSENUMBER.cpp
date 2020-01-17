//
//  CHOOSENUMBER.cpp
//  AJ
//
//  Created by 송혜경 on 19/10/2019.
//  Copyright © 2019 송혜경. All rights reserved.
//

#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 102;

int group[MAXN] = {0, };
int T[MAXN] = {0, };
int visited[MAXN] = {0, };
int N;

void grouping(int node) {
    int nextNode;
    
    group[node] = 1;
    
    nextNode = T[node];
    
    if(group[nextNode] == 0) {
        grouping(nextNode);
    }
}

void dfs(int node) {
    int nextNode;
    
    visited[node] = 1;
    
    nextNode = T[node];
    
    if(visited[nextNode] == 0) {
        dfs(nextNode);
    }else if(visited[nextNode] == 1 && group[nextNode] == 0) {   //그룹으로 만든다
        grouping(nextNode);     //그룹을 만들 수 있으므로 그룹을 만드는 함수 호출
    }
    //그룹에 속하지 않은 노드는
    if(group[node] == 0) {
        group[node] = -1;
    }
}

int main(void) {
    int counting;
    int i;
    
    scanf("%d", &N);
    
    for(i=1; i<=N; i++) {
        scanf("%d", &T[i]);
    }
    
    for(i=1; i<=N; i++) {
        if(visited[i] == 0) {
            dfs(i);
        }
    }
    
    counting = 0;
    for(i=1; i<=N; i++) {
        if(group[i] == 1) {
            counting++;
        }
    }
    
    printf("%d\n", counting);
    
    for(i=1; i<=N; i++) {
        if(group[i] == 1 ){
            printf("%d ", i);
        }
    }
    
    return 0;
}
