
#include <stdio.h>

const int MAXN = 5;
int T[MAXN] = {0, };

void dfs(int n, int idx) {
    int i;
    
    if(idx == n) {
        for(i=0; i<idx; i++) {
            printf("%d", T[i]);
        }
        printf("\n");
    }else {
        for(i=0; i<5; i++) {
            T[idx] = i+1;
            dfs(n, idx+1);
        }
    }
}

int main(void) {
    
    for(int n=1; n<=5; n++) {
        dfs(n, 0);
    }
    
    return 0;
}
