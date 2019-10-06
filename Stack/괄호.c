//
//  괄호.c
//  AJ
//
//  Created by 송혜경 on 03/10/2019.
//  Copyright © 2019 송혜경. All rights reserved.
//
#include <stdio.h>
#include <string.h>

typedef struct StackType {
    int top;
    char stack[60];
};

void push(StackType *s, char element) {
    s->stack[++(s->top)] = element;
}

//pop할 요소가 없을 경우 -1 리턴
int pop(StackType *s) {
    if(s->top == -1) {
        return -1;
    }else {
        (s->top)--;
        return 1;
    }
}

int main(void) {
    char inputArr[55];
    StackType s;
    int length; int VPS;
    int i;  int flag = 0;
    
    scanf("%s", inputArr);
    
    length = strlen(inputArr);
    
    
    //스택 초기화
    s.top = -1;
    
    for(i=0; i<length; i++) {
        if(inputArr[i] == '(') {
            push(&s, inputArr[i]);
        }else {
            VPS = pop(&s);
            if(VPS == -1) {
                flag = 1; break;
            }
        }
    }
    
    if(s.top != -1) {
        flag = 1;
    }
    
    if(flag == 1) {
        printf("NO");
    }else {
        printf("YES");
    }
    
    return 0;
}
