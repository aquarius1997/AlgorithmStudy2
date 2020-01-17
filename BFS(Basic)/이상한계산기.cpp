//
//  이상한계산기.cpp
//  AJ
//
//  Created by 송혜경 on 09/10/2019.
//  Copyright © 2019 송혜경. All rights reserved.
//

#include <cstdio>
#include <queue>

using namespace std;

const int MAXN = 99999;
//arr[i] : 숫자 i를 만들기 위한 최소 버튼 클릭 횟수
int arr[MAXN] = {0, };
int visited[MAXN] = {0, };
queue <int> Queue;
int N;

void bfs(int num) {
    int n;
    
    Queue.push(num);
    visited[num] = 1;
    arr[num] = 0;
    
    while(!Queue.empty()) {
        n = Queue.front();  Queue.pop();
        
        if(n == N)
            break;
        
        if(n >= 3) {
            if(visited[n/3] == 0 && n/3 <= MAXN) {
                arr[n/3] = arr[n]+1;
                visited[n/3] = 1;
                Queue.push(n/3);
            }
        }
        if(visited[n*2] == 0 && n*2 <= MAXN) {
            arr[n*2] = arr[n]+1;
            visited[n*2] = 1;
            Queue.push(n*2);
        }
        
    }
}

int main(void) {
    scanf("%d", &N);
    
    bfs(1);
    
    printf("%d", arr[N]);
    
    return 0;
}


