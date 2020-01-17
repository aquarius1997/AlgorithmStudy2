//
//  TREEHW.cpp
//  AJ
//
//  Created by 송혜경 on 17/10/2019.
//  Copyright © 2019 송혜경. All rights reserved.
//

#include <stdio.h>

//함수 선언
int treeCount(int node);

//트리의 노드 타입
typedef struct TreeNode {
    int height; //현재 노드의 높이정보
    int parent;
    int leftChild;
    int rightChild;
    int col;
}TreeNode;

const int MAXN = 1002;
int N;
TreeNode tree[MAXN];    //트리
int T[MAXN][MAXN];

//배열에 이진트리 정보를 조건에 맞춰서 만든다
void makeT(int node) {

    //node의 왼쪽 자식 위치는 (루트위치 - 왼쪽자식의 오른쪽 서브트리노드수 - 1)
    int leftnode = tree[node].leftChild;
    if(leftnode != -1){
        tree[leftnode].col = tree[node].col - treeCount(tree[leftnode].rightChild) - 1;
        T[(tree[leftnode].height)][(tree[leftnode].col)] = tree[node].leftChild;
    }
    
    //node의 오른쪽 자식 위치는 (루트위치 + 오른쪽 자식의 왼쪽 서브트리 노드수)
    int rightnode = tree[node].rightChild;
    if(rightnode != -1) {
        tree[rightnode].col = tree[node].col + treeCount(tree[rightnode].leftChild) + 1;
        T[(tree[rightnode].height)][(tree[rightnode].col)] = tree[node].rightChild;
    }
    
    if(tree[node].leftChild != -1) {
        makeT(tree[node].leftChild);
    }
    
    if(tree[node].rightChild != -1) {
        makeT(tree[node].rightChild);
    }
    
}

//입력으로 들어온 (노드 + 자식 개수)를 리턴
int treeCount(int node) {
    int left, right;
    
    left = right = 0;
    
    if(node == -1) {
        return 0;
    }else{
    
        left = treeCount(tree[node].leftChild);
        right = treeCount(tree[node].rightChild);
    
        return (1+left+right);
    }
}

int main(void) {
    int c, a, b;
    int maxHeight = 1;
    int firstNode, lastNode;
    int level, width;
    int count;
    int i, j;
    
    scanf("%d", &N);
    
    //트리 정보 초기화
    for(i=1; i<=N; i++) {
        scanf("%d %d %d", &a, &b, &c);
        tree[a].leftChild = b;
        tree[a].rightChild = c;
        if(b != -1)
            tree[b].parent = a;
        if(c != -1)
            tree[c].parent = a;
    }
    //루트노드의 높이 1
    tree[1].height = 1;
    tree[1].parent = -1;
    for(i=2; i<=N; i++) {
        tree[i].height = tree[(tree[i].parent)].height + 1;
        if(tree[i].height > maxHeight)
            maxHeight = tree[i].height;
    }

    
    //루트 노드의 위치를 먼저 구한다
    
    //왼쪽 subTree의 노드 개수를 구한다
    int leftCount = treeCount(tree[1].leftChild);
    
    //node의 위치
    T[(tree[1].height)][leftCount+1] = 1;
    tree[1].col = leftCount + 1;

    //트리 모양을 만든다
    makeT(1);

    level = 1;
    width = 1;
    for(i=1; i<=maxHeight; i++) {
        for(j=1; j<=N; j++) {
            if(T[i][j] != 0) {
                firstNode = T[i][j];
                break;
            }
        }
        for(j=N; j>=1; j--) {
            if(T[i][j] != 0) {
                lastNode = T[i][j];
                break;
            }
        }
        
        if(tree[lastNode].col - tree[firstNode].col + 1 > width) {
            width = tree[lastNode].col - tree[firstNode].col + 1;
            level = i;
        }
    }
    
    printf("%d %d", level, width);
    
    return 0;
    
}
