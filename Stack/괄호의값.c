//
//  괄호의값.c
//  AJ
//
//  Created by 송혜경 on 03/10/2019.
//  Copyright © 2019 송혜경. All rights reserved.
//

#include <stdio.h>
#include <string.h>

typedef struct StackType{
    int top;
    int stack[200];
};

void push(StackType *s, int element) {
    s->stack[++(s->top)] = element;
}

//스택이 비었는데 pop하려고 하는 경우 올바르지 않음을 -100로 리턴하여 표시한다
//pop한 요소를 리턴한다
int pop(StackType *s) {
    int retValue;
    
    if(s->top == -1) {
        retValue = -100;
    }else {
        retValue = s->stack[(s->top)];
        (s->top)--;
    }
    
    return retValue;
}

//(를 int형의 스택에 넣을 때, 숫자 -1로 표시한다
//[를 int형의 스택에 넣을 때, 숫자 -2로 표시한다
int main(void) {
    char inputArr[33];  int len;
    StackType s;
    int flag = 0; int ret, ret2;
    int i, j;
    
    //스택 초기화
    s.top = -1;
    
    //문자열을 입력받고 길이를 구함
    scanf("%s", inputArr);  len = strlen(inputArr);
    
    //우선 올바른 괄호열인지 검증한다
    for(i=0; i<len; i++) {
        
        if(inputArr[i] == '(') {
            push(&s, -1);
        } //end if
        else if(inputArr[i] == ')') {
            ret = pop(&s);
            if(ret != -1) {
                flag = 1; break;
            }
        } //end else if(inputArr[i] == ')')
        else if(inputArr[i] == '[') {
            push(&s, -2);
        } //end else if(inputArr[i] == '[')
        else {
            ret = pop(&s);
            if(ret != -2) {
                flag = 1; break;
            }
        } //end else
        
    } // end for(올바른 괄호열 검증)
    
    if(s.top != -1) {
        flag = 1;
    }
    
    //올바른 괄호열이 아니면 0 출력하고 종료
    if(flag == 1) {
        printf("0");  return 0;
    }
    
    //올바른 괄호열이면 괄호의 값을 구한다
    for(i=0; i<len; i++) {
        
        if(inputArr[i] == '(') {
            push(&s, -1);
        } //end if
        else if(inputArr[i] == ')') {
            
            ret = pop(&s);
            
            //스택의 top이 가리키는것이 괄호이면 괄호의 값인 2를 push
            if(ret == -1) {
                push(&s, 2);
            }//스택의 top이 가리키는 것이 괄호가 아니면(1이상)
            else {
                ret2 = pop(&s);
                
                //현재 스택에서 꺼낸 값이 여는괄호이면 숫자*2를 push한다
                if(ret2 == -1) {
                    push(&s, (ret*2));
                }//현재 스택에서 꺼낸 값이 숫자이면
                else {
                    while(1) {
                        push(&s, (ret+ret2));
                        ret = pop(&s);
                        ret2 = pop(&s);
                        if(ret2 == -1) {
                            push(&s, ret*2);  break;
                        }
                    }
                }
                
            }//end else (스택의 top이 가리키는 것이 괄호가 아니면)
            
            
            
        } //end else if(inputArr[i] == ')')
        else if(inputArr[i] == '[') {
            push(&s, -2);
        }
        else {
            
            ret = pop(&s);
            
            //스택의 top이 가리키는것이 괄호이면 괄호의 값인 3를 push
            if(ret == -2) {
                push(&s, 3);
            }//스택의 top이 가리키는 것이 괄호가 아니면(1이상)
            else {
                ret2 = pop(&s);
                
                //현재 스택에서 꺼낸 값이 여는괄호이면 숫자*2를 push한다
                if(ret2 == -2) {
                    push(&s, (ret*3));
                }//현재 스택에서 꺼낸 값이 숫자이면
                else {
                    while(1) {
                        push(&s, (ret+ret2));
                        ret = pop(&s);
                        ret2 = pop(&s);
                        if(ret2 == -2) {
                            push(&s, ret*3);  break;
                        }
                    }
                }
                
            }//end else (스택의 top이 가리키는 것이 괄호가 아니면)
            
        } //else
        
    }//end for(괄호의 값을 구한다)
    
    ret = 0;
    while(s.top != -1) {
        ret += pop(&s);
    }
    
    printf("%d", ret);
    
    return 0;
}
