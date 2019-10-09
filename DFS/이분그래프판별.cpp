//
//  이분그래프판별.cpp
//  AJ
//
//  Created by 송혜경 on 09/10/2019.
//  Copyright © 2019 송혜경. All rights reserved.
//

/*
 방문 안한 인접 정점이면 다른 집합을 표시하고 재귀함수 호출을 한다
 
 방문 한 인접 정점이면 인접 정점이 자신과 다른 집합에 속하는지 검증한다
*/

#include <cstdio>
#include <vector>

using namespace std;

const int MAXN = 1003;
int set[MAXN] = {0, };  //set[i] == 0 : 아직 방문 안한 노드임
vector <int> Graph[MAXN];
int flag = 0;

void dfs(int node) {
    int w;
    int i;
    
    for(i=0; i<Graph[node].size(); i++) {
        w = Graph[node][i];
        
        //방문안한 인접노드는 다른 집합으로 표시한다
        if(set[w] == 0) {
            if(set[node] == 1) {
                set[w] = 2;
            }else {
                set[w] = 1;
            }
            dfs(w);
        }else {
            //방문한 인접노드는 자신과 다른 집합인지 검증한다
            if(set[node] == 1) {
                if(set[w] == 1) {
                    flag = 1;
                }
            }else {
                if(set[w] == 2) {
                    flag = 1;
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
    
    //정점 1번은 집합1에 속해있다고 초기화한다음에 dfs 함수 호출을 한다
    set[1] = 1;
    dfs(1);
    
    if(flag == 0) {
        printf("Yes");
    }else {
        printf("No");
    }
    return 0;
}
