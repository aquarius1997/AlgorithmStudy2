//
//  Dijkstra.cpp
//  AJ
//
//  Created by 송혜경 on 10/10/2019.
//  Copyright © 2019 송혜경. All rights reserved.
//
/*  T[i] : 정점 i에 도달하는데 걸리는 최단거리
 for i = 0 ~ n
 
 1. T[i] 중 최솟값을 정한다 (->index). 단, 지금까지 최솟값으로 뽑히지 않았던 값들 중에서
 2. index로부터 뻗어나간다. index의 인접노드들에 대하여 T[index] + cost
*/

#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX = 100;

vector <int> graph[MAX];
vector <int> cost[MAX];

int n, m, start, last;

int Table[MAX];
int Check[MAX]; //check[i] = true : i노드의 최단거리가 정해짐

int main(void) {
    scanf("%d %d %d %d", &n, &m ,&start, &last);
    
    for(int i=0; i<m; i++) {
        int a, b, c;
        
        //a -- [가중치c] -- b
        scanf("%d %d %d", &a, &b, &c);
        
        graph[a].push_back(b);
        graph[b].push_back(a);
        
        //간선의 가중치를 저장
        cost[a].push_back(c);
        cost[b].push_back(c);
    }
    
    for(int i=0; i<n; i++) {
        Table[i] = 987987987;
    }
    Table[start] = 0;
    
    for(int i=0; i<n; i++) {
        //1.  지금까지 최단거리로 확정되지 않은 정점에 대하여 최솟값을 구한다
        //2. 그 최솟값을 갖는 노드로부터 뻗어나간다
        
        int minValue = 987987987, minIndex = -1;
        
        for(int j=0; j<n; j++) {
            if(!Check[j] && minValue > Table[j]) {
                minValue = Table[j];
                minIndex = j;
            }
        }
        
        Check[minIndex] = true;
        
        for(int j=0; j<graph[minIndex].size(); j++) {
            int node2 = graph[minIndex][j];
            int cost2 = cost[minIndex][j];
            
            if(Table[node2] > Table[minIndex] + cost2) {
                Table[node2] = Table[minIndex] + cost2;
            }
        }
    }
    
    printf("%d\n", Table[last]);
    
    return 0;
}
