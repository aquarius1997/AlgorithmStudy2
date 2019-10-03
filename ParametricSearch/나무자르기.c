#include <stdio.h>
#define ARRLEN  1000002
//적어도 M이상을 가져갈 수 있을 때의 최대 절단기 높이
long maxHeight = 0;
int N, M;

//이진탐색을 활용하여 나무 자르기를 수행한다
void binary_search(int tree[1000002], int start, int end) {
    long mid;
    long sum;
    int i;
    
    if(end <= start) {
        //처음 호출되었을 경우 가장 높은 나무 기준의 중간 위치에서 시작하게 된다
        mid = (start + end) / 2;
        
        sum = 0;
        
        //mid높이에서 나무를 자른다
        for(i=0; i<N; i++) {
            //잘려진 나무가 있으면
            if(tree[i] - mid > 0) {
                sum += (tree[i] - mid);
            }
        }
        
        
        if(sum == M) {
            maxHeight = mid;
        }else if(sum > M) {
            //maxHeight 업데이트
            if(mid > maxHeight) {
                maxHeight = mid;
            }
            //절단기의 높이를 높인다
            binary_search(tree, start, mid+1);
        }else {
            //절단기의 높이를 낮춘다
            binary_search(tree, mid-1, end);
        }
    }
}

int main(void) {
    int tree[1000002];
    int maxTree = 0;
    int i;
    
    scanf("%d %d", &N, &M);
    
    for(i=0; i<N; i++) {
        scanf("%d", &tree[i]);
        //가장 높은 나무의 높이를 알아낸다
        if(tree[i] > maxTree) {
            maxTree = tree[i];
        }
    }
    
    binary_search(tree, maxTree, 0);
    
    printf("%d", maxHeight);
    
    return 0;
}
