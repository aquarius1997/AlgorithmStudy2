//
//  숫자만들기.c
//  AJ
//
//  Created by 송혜경 on 08/10/2019.
//  Copyright © 2019 송혜경. All rights reserved.
//

#include <stdio.h>
#define MOD 1000007

int main(void) {
    int T[100002] = {0, };  //T[i] : 숫자 1, 2, 3으로 만들 수 있는 경우의 수
    int N;
    int i;
    
    scanf("%d", &N);
    
    //base condition
    T[1] = 1;
    T[2] = 2;
    T[3] = 4;
    
    for(i=4; i<=N; i++) {
        T[i] = (T[i-1] + T[i-2] + T[i-3]) % MOD;
    }
    
    printf("%d", T[N]);
    return 0;
}

