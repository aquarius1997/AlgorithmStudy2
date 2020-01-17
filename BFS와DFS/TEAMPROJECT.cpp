//
//  TEAMPROJECT.cpp
//  AJ
//
//  Created by 송혜경 on 15/10/2019.
//  Copyright © 2019 송혜경. All rights reserved.
//

#include <stdio.h>

int node[100004] = {0, };   //node[i] : i번 학생이 선택한 학생의 번호, !!인덱스는 1부터 시작함을 유의
int visited[100004] = {0, };
int team[100004] = {0, };   //팀에 속하면 1 아니면 0
int n;

void makeTeam(int num);

void dfs(int num) {
    int nextNode;
    
    visited[num] = 1;
    
    //번호가 num인 학생이 선택한 학생의 번호
    nextNode = node[num];
    
    if(visited[nextNode] == 0) {
        dfs(nextNode);
    }
    //cycle을 형성(=팀 형성)하므로 팀을 만드는 함수를 호출한다
    if(visited[nextNode] == 1 && team[nextNode] == 0) {
        makeTeam(nextNode);
    }
    //방문 노드가 팀에 속하지 않는 노드일 경우 -1로 값을 저장하여 표시한다
    if(team[num] == 0) {
        team[num] = -1;
    }
}

void makeTeam(int num) {
    int nextNode;
    
    team[num] = 1;
    
    nextNode = node[num];
    
    if(team[nextNode] == 0) {
        makeTeam(nextNode);
    }
}

int main(void) {
    int counting = 0;
    int i;
    
    scanf("%d", &n);
    
    for(i=1; i<=n; i++) {
        scanf("%d", &node[i]);
    }
    
    for(i=1; i<=n; i++) {
        if(visited[i] == 0) {
            dfs(i);
        }
    }
    

    for(i=1; i<=n; i++) {
        if(team[i] == -1) {
            counting++;
        }
    }
    
    printf("%d", counting);
    
    return 0;
}
