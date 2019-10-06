//
//  거듭제곱구하기L.c
//  AJ
//
//  Created by 송혜경 on 06/10/2019.
//  Copyright © 2019 송혜경. All rights reserved.
//

#include <stdio.h>

long long recursive_f(int n, long long m) {
    long long num;
    int result;
    
    if(m == 1) {
        return n;
    }else{
    
        num = recursive_f(n, m/2) % 10007;
        
        result = (num * num) % 10007;
        
        //m이 홀수일 경우
        if(m % 2 == 1) {
            result = ((long long)result * n) % 10007;
        }
        
        return result;
    }
}

int main(void) {
    int n;
    long long m;
    
    scanf("%d %lld", &n, &m);
    
    printf("%lld", recursive_f(n, m));
    
    return 0;
}
