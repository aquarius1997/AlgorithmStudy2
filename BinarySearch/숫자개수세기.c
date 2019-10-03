//
//  숫자개수세기.c
//  AJ
//
//  Created by 송혜경 on 03/10/2019.
//  Copyright © 2019 송혜경. All rights reserved.
//

#include <stdio.h>

int main(void) {
    //arr[i] : i숫자의 개수를 저장하고 있는다
    int arr[100002] = {0, };
    int n, q, num;
    int i;
    
    scanf("%d %d", &n, &q);
    
    for(i=0; i<n; i++) {
        scanf("%d", &num);
        arr[num]++;
    }
    
    for(i=0; i<q; i++) {
        scanf("%d", &num);
        printf("%d\n", arr[num]);
    }
    
    return 0;
}
