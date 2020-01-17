//
//  특정최단거리.cpp
//  AJ
//
//  Created by 송혜경 on 10/10/2019.
//  Copyright © 2019 송혜경. All rights reserved.
//

#include <cstdio>
#include <vector>
#define MAX 1001
#define INF 98798798
using namespace std;

vector <int> Graph[MAX];
vector <int> Cost[MAX];
//S집합 : 최단거리가 확정된 노드들의 최단거리 값을 가진다. 집합에 노드가 포함되지 않으면 값 0을 가짐
int S[MAX]={0, };
//Q집합 : 최단거리가 확정되지 않는 노드들의 relaxing과정이 이루어진다.
//값이 -1인 노드는 Q집합에서 빠진것을 의미
//Q=V-S
//초기화시 시작 정점을 0, 나머지는 INF로 저장
int Q[MAX];

int main() {
    int N, M, a, b, c, A, B;
    int i, j;
    long long a_to_b, b_to_a;
    int min_node, min;
    a_to_b=b_to_a=0;
    
    scanf("%d %d", &N, &M);
    for(i=0; i<M; i++){
        scanf("%d %d %d", &a, &b, &c);
        Graph[a].push_back(b);
        Graph[b].push_back(a);
        Cost[a].push_back(c);
        Cost[b].push_back(c);
    }
    scanf("%d %d", &A, &B);
    
    //1번 정점에서 A까지 최단거리를 구한다
    Q[1]=0;
    for(i=2; i<=N; i++)
        Q[i]=INF;
    
    //정점의 개수만큼 실행
    for(i=1; i<=N; i++){
        min=987987987;
        for(j=1; j<=N; j++){
            //최소값을 가지는 노드를 알아낸다
            if(Q[j]!=-1 && Q[j]<min){
                min=Q[j];
                min_node=j;
            }
        }
        //min_node를 집합 S에 추가
        S[min_node]=Q[min_node];
        //min_node의 인접정점들에 대해 relaxing과정을 구생한다
        for(j=0; j<Graph[min_node].size(); j++){
            if(Q[(Graph[min_node][j])]>Q[min_node]+Cost[min_node][j])
                Q[(Graph[min_node][j])]=Q[min_node]+Cost[min_node][j];
        }
        //집합 Q에서 해당 노드를 뺀다
        Q[min_node]=-1;
    }
    
    //1->A->B->N 중 1->A의 값을 더함
    a_to_b+=S[A];
    //1->B->A->N 중 1->B의 값을 더함
    b_to_a+=S[B];
    //---------------------------------------------------------
    //A가 시작정점일 경우를 구하기 위해 S, Q집합 다시 초기화
    for(i=0; i<=N; i++)
        S[i]=0;
    for(i=1; i<=N; i++){
        if(i==A)
            Q[i]=0;
        else
            Q[i]=INF;
    }
    //정점의 개수만큼 실행
    for(i=1; i<=N; i++){
        min=987987987;
        for(j=1; j<=N; j++){
            //최소값을 가지는 노드를 알아낸다
            if(Q[j]!=-1 && Q[j]<min){
                min=Q[j];
                min_node=j;
            }
        }
        //min_node를 집합 S에 추가
        S[min_node]=Q[min_node];
        //min_node의 인접정점들에 대해 relaxing과정을 구생한다
        for(j=0; j<Graph[min_node].size(); j++){
            if(Q[(Graph[min_node][j])]>Q[min_node]+Cost[min_node][j])
                Q[(Graph[min_node][j])]=Q[min_node]+Cost[min_node][j];
        }
        //집합 Q에서 해당 노드를 뺀다
        Q[min_node]=-1;
    }
    //1->A->B->N 중 A->B거리와 1->B->A->N 중 B->A의 거리
    a_to_b+=S[B];
    b_to_a+=S[B];
    //1->B->A->N 중 A->N거리
    b_to_a+=S[N];
    
    //---------------------------------------------------------
    //B가 시작정점일 경우를 구하기 위해 S, Q집합 다시 초기화
    for(i=0; i<=N; i++)
        S[i]=0;
    for(i=1; i<=N; i++){
        if(i==B)
            Q[i]=0;
        else
            Q[i]=INF;
    }
    //정점의 개수만큼 실행
    for(i=1; i<=N; i++){
        min=987987987;
        for(j=1; j<=N; j++){
            //최소값을 가지는 노드를 알아낸다
            if(Q[j]!=-1 && Q[j]<min){
                min=Q[j];
                min_node=j;
            }
        }
        //min_node를 집합 S에 추가
        S[min_node]=Q[min_node];
        //min_node의 인접정점들에 대해 relaxing과정을 구생한다
        for(j=0; j<Graph[min_node].size(); j++){
            if(Q[(Graph[min_node][j])]>Q[min_node]+Cost[min_node][j])
                Q[(Graph[min_node][j])]=Q[min_node]+Cost[min_node][j];
        }
        //집합 Q에서 해당 노드를 뺀다
        Q[min_node]=-1;
    }
    //1->A->B->N 중 B->end의 거리
    a_to_b+=S[N];
    
    if(a_to_b<b_to_a)
        printf("%lld", a_to_b);
    else
        printf("%lld", b_to_a);
    return 0;
}
