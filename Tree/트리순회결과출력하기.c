//
//  트리순회결과출력하기.c
//  AJ
//
//  Created by 송혜경 on 06/10/2019.
//  Copyright © 2019 송혜경. All rights reserved.
//

#include <stdio.h>

typedef struct TreeNode {
    int leftChild, rightChild;
}TreeNode;

//Root -> L -> R
void pre_order(TreeNode tree[] , int node) {
    if(node == -1) {
        return;
    }else {
        printf("%d ", node);
        pre_order(tree, tree[node].leftChild);
        pre_order(tree, tree[node].rightChild);
    }
}

//L -> Root -> R
void in_order(TreeNode tree[], int node) {
    if(node == -1) {
        return;
    }else {
        in_order(tree, tree[node].leftChild);
        printf("%d ", node);
        in_order(tree, tree[node].rightChild);
    }
}

//L -> R -> Root
void post_order(TreeNode tree[], int node) {
    if(node == -1) {
        return;
    }else {
        post_order(tree, tree[node].leftChild);
        post_order(tree, tree[node].rightChild);
        printf("%d ", node);
    }
}

int main(void) {
    TreeNode tree[102];
    int n, a, b, c;
    int i;
    
    scanf("%d", &n);
    
    for(i=0; i<n; i++) {
        scanf("%d %d %d", &a, &b, &c);
        tree[a].leftChild = b;
        tree[a].rightChild = c;
    }
    
    pre_order(tree, 0);
    printf("\n");
    in_order(tree, 0);
    printf("\n");
    post_order(tree, 0);
    
    return 0;
}
