//
//  접시.c
//  AJ
//
//  Created by 송혜경 on 03/10/2019.
//  Copyright © 2019 송혜경. All rights reserved.
//

#include <stdio.h>
#include <string.h>

typedef struct StackType {
    int top;
    char stack[30];
};

void push(StackType *s, char element) {
    s->stack[++(s->top)] = element;
}

void pop(StackType *s) {
    (s->top)--;
}

char peek(StackType *s) {
    return s->stack[s->top];
}

int main(void) {
    StackType s;
    char inputArr[30];
    char alphabet[30];  int idx = 0;
    int oper[100];  int opIdx = 0;
    int length;
    int i, j;
    
    scanf("%s", inputArr);
    
    length = strlen(inputArr);
    
    //알파벳 배열 초기화
    for(i=0; i<26; i++) {
        alphabet[i] = 'a' + i;
    }
    
    //스택 초기화
    s.top = -1;
    
    //입력으로 들어온 문자열에 대하여
    for(i=0; i<length; i++) {
        
        if(s.top == -1 || s.stack[s.top] != inputArr[i]) {
            if(s.top == -1) {
                if(idx >= length) {
                    printf("impossible"); return 0;
                }
                push(&s, alphabet[idx++]);
                oper[opIdx++] = 1;
            }
            while(s.stack[s.top] != inputArr[i]) {
                if(idx >= length) {
                    printf("impossible"); return 0;
                }
                push(&s, alphabet[idx++]);
                oper[opIdx++] = 1;
            }
            if(s.top == -1) {
                printf("impossible"); return 0;
            }
            pop(&s);
            oper[opIdx++] = 2;
        }else {
            if(s.top == -1) {
                printf("impossible"); return 0;
            }
            pop(&s);
            oper[opIdx++] = 2;
        }
    }
    
    if(s.top != -1){
        printf("impossible"); return 0;
    }
    
    for(i=0; i<opIdx; i++) {
        if(oper[i] == 1) {
            printf("push\n");
        }else {
            printf("pop\n");
        }
    }
    
    return 0;
}
