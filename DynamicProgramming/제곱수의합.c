//
//  제곱수의합.c
//  AJ
//
//  Created by 송혜경 on 08/10/2019.
//  Copyright © 2019 송혜경. All rights reserved.
//

#include <stdio.h>
#include <math.h>

int main(void) {
    int T[100005] = {0, };
    int sqrtR, d;
    int min;
    int n;
    int i, j;
    
   // sqrtR = (int)(sqrt(4)*10);
    
    scanf("%d", &n);
    
    //base-case
    T[1] = 1;
    T[2] = 2;
    
    for(i=3; i<=n; i++) {
        min = 987987987;
        sqrtR = (int)(sqrt(i));
        for(j=sqrtR; j>=1; j--) {
            d = i - (j*j);
            
            if(d == 0) {
                min = 1;    break;
            }
            
            if(1+T[d] < min) {
                min = 1 + T[d];
            }
        }
        T[i] = min;
    }
    
    printf("%d", T[n]);
    
    return 0;
}
