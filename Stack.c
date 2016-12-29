//
//  Stack.c
//  PRN
//
//  Created by Isabella Lee on 12/29/16.
//  Copyright © 2016 Isabella Lee. All rights reserved.
//
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "Stack.h"

sqStack InitStack(sqStack *s)
{
    s->base = (ElemType*) malloc(STACK_INIT_SIZE*sizeof(ElemType));
    if(!s->base)
        exit(0);
    
    s->top = s->base;
    s->stackSize = STACK_INIT_SIZE;
    return *s;
}

void Push(sqStack *s, ElemType e)
{
    if(s->top - s->base >= s->stackSize)
    {
        s->base = (ElemType *)realloc(s->base, (s->stackSize + STACKINCREMENT) * sizeof(ElemType));
        if(!s->base)
            exit(0);
        
        s->top = s->base + s->stackSize;
        s->stackSize = s->stackSize + STACKINCREMENT;
    }
    
    *(s->top) = e;
    s->top++;
}

void Pop(sqStack *s, ElemType *e)
{
    if(s->top == s->base)
        return;
    
    *e = *--(s->top);
}


int StackLen(sqStack s)
{
    return (int)(s.top - s.base);
}
