//
//  공통조상찾기.c
//  AJ
//
//  Created by 송혜경 on 06/10/2019.
//  Copyright © 2019 송혜경. All rights reserved.
//

#include <stdio.h>

typedef struct TreeNode {
    int parent;
}TreeNode;

int main(void) {
    TreeNode tree[1002];
    int visited[1002] = {0, };
    int n, X, Y, a, b;
    int i;
    
    scanf("%d %d %d", &n, &X, &Y);
    
    for(i=0; i<n-1; i++) {
        scanf("%d %d", &a, &b);
        
        tree[b].parent = a;
    }
    
    for(i=X; i>0; i = tree[i].parent) {
        visited[(tree[i].parent)] = 1;
    }
    
    for(i=Y; i>0; i = tree[i].parent) {
        if(visited[(tree[i].parent)] == 1) {
            printf("%d", tree[i].parent);
            break;
        }
    }
    
    return 0;
}
