//
//  main.cpp
//  PRN
//
//  Created by Isabella Lee on 12/29/16.
//  Copyright © 2016 Isabella Lee. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "Stack.h"
#include "Stack.c"

int main() {
    
    sqStack s;
    char c;
    double d, e;
    char str[MAXBUFFER];
    int i = 0;
    
    InitStack(&s);
    printf("Please input the operation expression: ");
    scanf("%c", &c);
    
    while (c != '#') //end with #
    {
        while (isdigit(c) || c == '.') {
            str[i++] = c;
            str[i] = '\0';
            if(i >= MAXBUFFER){
                printf("Error");
                return -1;
            }
            scanf("%c", &c);
            if(c ==' ')
            {
                d = atof(str);
                Push(&s, d);
                i = 0;
            }
        }
        switch (c) {
            case '+':
                Pop(&s, &e);
                Pop(&s, &d);
                Push(&s, d + e);
                break;
            case '-':
                Pop(&s, &e);
                Pop(&s, &d);
                Push(&s, d - e);
                break;
            case '*':
                Pop(&s, &e);
                Pop(&s, &d);
                Push(&s, d * e);
                break;
            case '/':
                Pop(&s, &e);
                Pop(&s, &d);
                if (e != 0) {
                     Push(&s, d / e);
                }else {
                    printf("Error.\n");
                    return -1;
                }
                break;
        }
        scanf("%c", &c);
    }
    
    Pop(&s, &d);
    printf("Result: %f\n", d);

    return 0;
}


