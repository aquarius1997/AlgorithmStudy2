//
//  히스토그램에서가장큰직사각형찾기.cpp
//  AJ
//
//  Created by 송혜경 on 03/10/2019.
//  Copyright © 2019 송혜경. All rights reserved.
//

#include <stdio.h>
typedef struct StackType{
    int top = -1;
    int arr[100000];
    
    void push(int element){
        arr[++top] = element;
    }
    
    void pop(){
        top--;
    }
}Stacktype;

int main(void){
    int N;  StackType s;
    int histogram[100005];
    int i, temp;
    int max=0;
    int index;
    
    scanf("%d", &N);
    
    for(i=0; i<N; i++)
        scanf("%d", &histogram[i]);
    
    
    s.push(0);
    
    for(i=1; i<N; i++){
        if(histogram[i] > histogram[s.arr[s.top]]){
            s.push(i);
        }else{
            while(s.top != -1){
                index = s.arr[s.top];
                if(histogram[i] > histogram[index])
                    break;
                
                s.pop();
                
                if(s.top == -1){
                    temp = histogram[index] * i;
                    if(temp > max)
                        max = temp;
                }else{
                    temp = histogram[index] * (i-s.arr[s.top]-1);
                    if(temp > max)
                        max = temp;
                }
                
            }
            
            s.push(i);
        }
    }
    
    while(s.top != -1){
        index = s.arr[s.top];
        s.pop();
        
        if(s.top == -1){
            temp = histogram[index] * N;
            if(temp > max)
                max = temp;
        }else{
            temp = histogram[index] * (N-s.arr[s.top]-1);
            if(temp > max)
                max = temp;
        }
    }
    
    printf("%d", max);
    return 0;
}

