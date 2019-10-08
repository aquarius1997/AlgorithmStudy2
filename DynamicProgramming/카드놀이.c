//
//  카드놀이.c
//  AJ
//
//  Created by 송혜경 on 08/10/2019.
//  Copyright © 2019 송혜경. All rights reserved.
//

#include <stdio.h>
#define MAXN(A, B)   (((A)>(B)) ? (A) : (B))

int main(void) {
    int T[100005] = {0, };  //T[i] : i개의 카드에서 얻을 수 있는 최대값
    int card[100005];   int num1, num2, num3;
    int N;
    int i;
    
    scanf("%d", &N);
    
    //카드 정보 입력받는다
    for(i=1; i<=N; i++) {
        scanf("%d", &card[i]);
    }
    
    //Base-case
    T[1] = card[1];
    T[2] = card[1] + card[2];
    T[3] = MAXN((card[1]+card[2]), (card[2]+card[3]));
    T[3] = MAXN(T[3], card[1]+card[3]);
    T[4] = MAXN((card[1]+card[2]+card[4]), (card[1]+card[3]+card[4]));
    T[4] = MAXN(T[4], card[2]+card[3]);
    
    //induction step
    for(i=5; i<=N; i++) {
        num1 = card[i] + T[i-2];
        num2 = card[i-1] + card[i] + T[i-3];
        num3 = card[i-2] + card[i-1] + T[i-4];
        
        T[i] = MAXN(num1, (MAXN(num2, num3)));
    }
    
    printf("%d", T[N]);
    
    return 0;
}
