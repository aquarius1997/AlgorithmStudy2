//
//  최단거리.cpp
//  AJ
//
//  Created by 송혜경 on 10/10/2019.
//  Copyright © 2019 송혜경. All rights reserved.
//

#include <cstdio>
#include <vector>
#define MAX 10000
#define INFIN 98798798
using namespace std;

vector <int> Graph[MAX];
//S[i] : i노드까지의 최단거리를 저장 (값이0일경우 해당 노드가 집합에 포함되지 않음을 의미)
int S[MAX]={0, };
//Q[i] : Q=V-S -> 아직 최단거리를 확정 짓지 못한 노드들의 집합.relax과정을 통해 최단거리를 구한다
int Q[MAX];

int main() {
    int N, M, a, b, start, end;
    int min_node, min;
    int i, j;
    
    scanf("%d %d", &N, &M);
    for(i=0; i<M; i++){
        scanf("%d %d", &a, &b);
        Graph[a].push_back(b);
        Graph[b].push_back(a);
    }
    scanf("%d %d", &start, &end);
    
    //Q의 값을 초기화한다. start노드에 값을 0으로 지정 / 나머지 정점들은 INFIN으로 저장
    for(i=0; i<N; i++){
        if(i==start)
            Q[i]=0;
        else
            Q[i]=INFIN;
    }
    
    for(i=0; i<N; i++){
        min=98798798;
        for(j=0; j<N; j++){
            if(Q[j]!=-1 && Q[j]<min){
                min=Q[j];
                min_node=j;
            }
        }
        //S집합에 가장 작은 값을 가지는 노드를 추가
        S[min_node]=Q[min_node];
        //Q집합에서 뺀 노드를 표시
        //min_node의 인접 정점들에 대해 relaxing
        for(j=0; j<Graph[min_node].size(); j++){
            if(Q[(Graph[min_node][j])] > Q[min_node]+1)
                Q[(Graph[min_node][j])]=Q[min_node]+1;
        }
        Q[min_node]=-1;
    }
    
    printf("%d", S[end]);
    return 0;
}
