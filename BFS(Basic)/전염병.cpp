//
//  전염병.cpp
//  AJ
//
//  Created by 송혜경 on 09/10/2019.
//  Copyright © 2019 송혜경. All rights reserved.
//

#include <cstdio>
#include <queue>

using namespace std;

const int MAXN = 1000002;
int visited[MAXN] = {0, };
queue <int> Queue;
int counting = 0;
int N;

void bfs(int num) {
    int n;
    
    Queue.push(num);
    visited[num] = 1;
    counting++;
    
    while(!Queue.empty()) {
        n = Queue.front();  Queue.pop();
        
        if(n >= 3) {
            if(visited[n/3] == 0 && n/3 <= N) {
                visited[n/3] = 1;
                Queue.push(n/3);
                counting++;
            }
        }
        if(visited[n*2] == 0 && n*2 <= N) {
            visited[n*2] = 1;
            Queue.push(n*2);
            counting++;
        }
        
    }
}

int main(void) {
    int K;
    
    scanf("%d %d", &N, &K);
    
    bfs(K);
    
    printf("%d", N-counting);
    
    
    return 0;
}


