//
//  SCC.cpp
//  AJ
//
//  Created by 송혜경 on 10/10/2019.
//  Copyright © 2019 송혜경. All rights reserved.
//

#include <cstdio>
#include <vector>
#define MAX 1001

using namespace std;

//global variables
//1. 원래 그래프 배열
vector <int> Graph[MAX];
//2. 간선의 방향이 반대인 배열
vector <int> Reverse_Graph[MAX];
//3. 노드를 방문했는지 확인할 배열(방문하면 1로 저장)
int visited[MAX]={0, }; int visited2[MAX]={0, };
//4. 각 노드가 빠져나오는 시간을 저장할 배열과 시간을 표시할 변수
int pop_time[MAX];  int time_cnt=1;
//5. 노드들이 빠져나오는 순서를 알기 위한 배열(인덱스 번호가 커질수록 늦게빠져나온 노드이다)
//배열에는 노드들의 번호가 저장된다
//pop_idx를 하나씩 증가시킴
int pop_seq[MAX]; int pop_idx=0;
//6. 각 노드들의 그룹번호를 저장할 배열과 그룹번호를 카운팅 할 변수
int group[MAX]; int group_cnt=1;

void dfs_first(int Node){
    int i, j;
    
    visited[Node]=1;
    //방문 안한 인접 노드들에 대해 DFS함수 호출
    for(i=0; i<Graph[Node].size(); i++){
        if(visited[(Graph[Node][i])]==0)
            dfs_first(Graph[Node][i]);
    }
    pop_time[Node]=time_cnt;
    time_cnt++;
    pop_seq[pop_idx++]=Node;
    return;
}

void dfs_second(int Node){
    int i;
    
    group[Node]=group_cnt;
    visited2[Node]=1;
    for(i=0; i<Reverse_Graph[Node].size(); i++){
        if(visited2[(Reverse_Graph[Node][i])]==0)
            dfs_second((Reverse_Graph[Node][i]));
    }
}

int main() {
    int N, M, a, b;
    int i, j;
    
    scanf("%d %d", &N, &M);
    
    for(i=0; i<M; i++){
        scanf("%d %d", &a, &b);
        Graph[a].push_back(b);
        Reverse_Graph[b].push_back(a);
    }
    
    for(i=1; i<=N; i++){
        if(visited[i]==0)
            dfs_first(i);
    }
    
    for(i=pop_idx-1; i>=0; i--){
        if(visited2[pop_seq[i]]==0){
            dfs_second(pop_seq[i]);
            group_cnt++;
        }
    }
    printf("%d", group_cnt-1);
    return 0;
}
