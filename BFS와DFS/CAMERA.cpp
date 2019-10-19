//
//  CAMERA.cpp
//  AJ
//
//  Created by 송혜경 on 17/10/2019.
//  Copyright © 2019 송혜경. All rights reserved.
//
// 터미널 노드부터(간선이 1개만 존재하는 노드)시작한다.
// 방문 안 한 터미널 노드의 부모노드(b)로 이동해, b와 연결된 모든 노드를 방문처리하며 count한다.
// 모두 방문할 때 까지 반복
//!! 문제 조건 중 또한 "회사에서 한 번 지나간 부서를 다시 들리기 위해서는 전에 지난 통로를 반드시 지나야하고 " -> Tree 형태임을 암시

#include <cstdio>
#include <vector>

using namespace std;

const int MAXN = 1002;
vector <int> Graph[MAXN];
int visited[MAXN] = {0, };
int D, P;

int main(void) {
    int a, b;
    int parent;
    int counting = 0;
    int i, j;
    
    scanf("%d %d", &D, &P);
    
    //그래프를 초기화
    for(i=0; i<P; i++) {
        scanf("%d %d", &a, &b);
        
        Graph[a].push_back(b);
        Graph[b].push_back(a);
    }
    
    for(i=0; i<D; i++) {
        //단말노드이면
        if(visited[i] == 0 && Graph[i].size() == 1) {
            parent = Graph[i][0];
            
            //단말노드의 부모노드와 인접한 노드들을 모두 방문처리
            visited[parent] = 1;
            for(j=0; j<Graph[parent].size(); j++) {
                visited[(Graph[parent][j])] = 1;
            }

            //카운팅
            counting++;
        }
    }
    
    //나머지 방문 안한 노드들에 대하여 인접노드들과 함께 방문처리
    for(i=0; i<D; i++) {
        if(visited[i] == 0) {
            
            visited[i] = 1;
            
            for(j=0; j<Graph[i].size(); j++) {
                visited[(Graph[i][j])] =1;
            }
            
            //카운팅
            counting++;

        }
    }
    
    printf("%d", counting);
    
    return 0;
}
