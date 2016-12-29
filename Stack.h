//
//  Stack.h
//  PRN
//
//  Created by Isabella Lee on 12/29/16.
//  Copyright © 2016 Isabella Lee. All rights reserved.
//

#ifndef Stack_h
#define Stack_h

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdio.h>

#define STACK_INIT_SIZE 20
#define STACKINCREMENT  10
#define MAXBUFFER       10

typedef double ElemType;
typedef struct
{
    ElemType *base;
    ElemType *top;
    int stackSize;
}sqStack;

sqStack InitStack(sqStack *s);
void Push(sqStack *s, ElemType e);
void Pop(sqStack *s, ElemType *e);
int StackLen(sqStack s);

#endif /* Stack_h */
