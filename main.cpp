//
//  Bin2Dec.c
//  Bin2Dec
//
//  Created by Isabella Lee on 12/28/16.
//  Copyright © 2016 Isabella Lee. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define STACK_INIT_SIZE 20
#define STACKINCREMENT 10

typedef char ElemType;
//ASCII 49 1 50 0

typedef struct{
    ElemType *base;
    ElemType *top;
    int stackSize;
}Stack;

void InitStack(Stack *s){
    s->base = (ElemType *)malloc(STACK_INIT_SIZE * sizeof(ElemType));
    if(!s->base) return;
    
    s->top = s->base;
    s->stackSize = STACK_INIT_SIZE;
}

void Push(Stack *s, ElemType e){
    //上溢出
    if(s->top - s->base >= s->stackSize){
        s->base = (ElemType *)realloc(s->base, (s->stackSize + STACKINCREMENT)*sizeof(ElemType));
        s->stackSize += STACKINCREMENT;
        if(!s->base)
            return;
    }
    
    *(s->top) = e;
    s->top++;
}

//how about return nothing?
//修改传指针，测试传变量值
void Pop(Stack *s, ElemType *e){
    //下溢出
    if(s->top == s->base) return;
    *e = *--(s->top);
    
}

//修改传指针，测试传变量值
int StackLen(Stack s){
    return (int)(s.top - s.base); //s.top - s.base is actually a value of long type
}


int main(){
    
    Stack s;
    InitStack(&s);
    ElemType c;
    int len, i, sum = 0;
    printf("Please input a binary value ending with #: ");
    scanf("%c", &c);
    /*
     if scanf("%d", d), say user inputs 1110000, 1110000 will be taken as a whole to read into the complier as a digit instead of seprate 1s and 0s.
     */
    while (c !='#') {
        Push(&s, c);
        scanf("%c", &c);
    }
    
    getchar(); // 把'\n'从缓冲区去掉
    
    len = StackLen(s);
    printf("The size of the stack is: %d\n", len);
    
    for(i = 0; i < len; i++) {
        Pop(&s, &c);
        sum = sum + (c-48)*pow(2, i);
    }
    
    printf("The decimal value is: %d\n", sum);
    
    return 0;
}


