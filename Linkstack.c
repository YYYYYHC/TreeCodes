#include<stdio.h>
#include<stdlib.h>
#include"binaryTree_Linked.h"

PLinkStack createEmptyStack_link()
{
    PLinkStack plstack;
    plstack = (struct Linkstack*)malloc(sizeof(struct Linkstack));
    if(plstack == NULL)
        printf("OUt of Space!\n");
    else
        plstack->top = NULL;
    return plstack;
}

int isEmptyStack_link(PLinkStack plstack)
{
    return (plstack->top == NULL);
}

void push_link(PLinkStack plstack,PBinTree x)
{
    struct Node *p;
    p = (struct Node *)malloc(sizeof(struct Node));
    if(p==NULL)
        printf("Out of Space!\n");
    else{
        p->info = x;
        p->link = plstack->top;
        plstack->top = p;
    }
    return;
}

void push_link_b(PLinkStack plstack,PBinTree x,char tag)
{
    struct Node *p;
    p = (struct Node *)malloc(sizeof(struct Node));
    if(p==NULL)
        printf("Out of Space!\n");
    else{
        p->info = x;
        p->tag = tag;
        p->link = plstack->top;
        plstack->top = p;
    }
    return;
}

PBinTree pop_link(PLinkStack plstack)
{
    struct Node *p;
    PBinTree elem;
    if(isEmptyStack_link(plstack))
        printf("Empty stack pop\n");
    else{
        p = plstack->top;
        elem = p->info;
        plstack->top = plstack->top->link;
        free(p);
    }

    return elem;
}

struct Node * pop_link_b(PLinkStack plstack)
{
    struct Node *p;
    PBinTree elem;
    if(isEmptyStack_link(plstack))
        printf("Empty stack pop\n");
    else{
        p = plstack->top;
        plstack->top = plstack->top->link;
        return p;
        free(p);
    }
    return NULL;
}

PBinTree top_link(PLinkStack plstack)
{
    if(isEmptyStack_link(plstack))
        printf("Empty Stack!\n");
    else{
        return plstack->top->info;
    }
    return 0;
}