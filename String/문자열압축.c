//
//  문자열압축.c
//  AJ
//
//  Created by 송혜경 on 03/10/2019.
//  Copyright © 2019 송혜경. All rights reserved.
//

#include <stdio.h>
#include <string.h>

int main(void) {
    char str[1002];
    int idx = 0;
    int len;
    int count;
    int i;
    
    scanf("%s", str);
    
    len = strlen(str);
    
    for(i=0; i<len; i=i+count) {
        count = 1;
        while(str[i] == str[i+count]) {
            count++;
        }
        if(count != 1) {
            printf("%d", count);
        }
        printf("%c", str[i]);
    }
    
    return 0;
}
