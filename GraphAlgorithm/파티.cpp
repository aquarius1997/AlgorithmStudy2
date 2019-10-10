//
//  파티.cpp
//  AJ
//
//  Created by 송혜경 on 10/10/2019.
//  Copyright © 2019 송혜경. All rights reserved.
//

#include <stdio.h>
#define MAX 1001
#define INF 98798798
//Floyd's algorithm(모든 정점쌍 간의 최단거리를 구할 수 있다)
//최단경로를 저장할 배열
int arr[MAX][MAX];
//간선의 가중치를 저장할 배열
int weight[MAX][MAX];

int main(void){
    int N, M, K, a, b, c;
    int i, j, k;
    int cost1, cost2;
    
    cost1=cost2=0;
    scanf("%d %d %d", &N, &M, &K);
    //간선의 가중치 배열을 초기화
    for(i=1; i<=N; i++){
        for(j=1; j<=N; j++){
            if(i==j)  //자기자신
                weight[i][j]=0;
            else  //갈 수 없는 노드일 경우
                weight[i][j]=INF;
        }
    }
    for(i=0; i<M; i++){
        scanf("%d %d %d", &a, &b, &c);
        //간선이 존재하는 정점간의 가중치 저장
        weight[a][b]=c;
    }
    
    //최단거리를 저장할 배열을 간선의 가중치로 초기화
    for(i=1; i<=N; i++)
        for(j=1; j<=N; j++)
            arr[i][j]=weight[i][j];
    //정점 i->j로 갈 때, 정점 K를 거치는경우와 거치지 않는경우가 있다. 둘 중 작은 값을 선택
    for(k=1; k<=N; k++)
        for(i=1; i<=N; i++)
            for(j=1; j<=N; j++)
                if(arr[i][k]+arr[k][j] < arr[i][j])
                    arr[i][j]=arr[i][k]+arr[k][j];
    
    for(i=1; i<=N; i++){
        if(i!=K)
            cost1+=arr[i][K];
        if(i==K){
            for(j=1; j<=N; j++){
                if(j!=K)
                    cost2+=arr[i][j];
            }
        }
    }
    printf("%d", cost1+cost2);
    return 0;
}
