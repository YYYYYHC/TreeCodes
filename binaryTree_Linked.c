#include<stdio.h>
#include<stdlib.h>
#include"Linkstack.c"

int GetBinTreeNodeNum(PBinTree T)
{
    if(T==NULL)
        return 0;
    else
        return 1+GetBinTreeNodeNum(T->lchild)+GetBinTreeNodeNum(T->rchild);

}

int GetBinTreeDepth(PBinTree T)
{
    if(T==NULL)
        return 0;
    else
        return 1+myMax(GetBinTreeDepth(T->lchild),GetBinTreeDepth(T->rchild));
}

PBinTree InputBinTree(PBinTree T)
{
    DataType input = getchar();
    if(input == '@') 
    {   
        T=NULL;
        return T;
    }
    else{
        T = (PBinTree)malloc(sizeof(BinTreeNode));
        T->info = input;

        T->lchild = InputBinTree(T->lchild);
        
        T->rchild = InputBinTree(T->rchild);
    }
    return T;
}

void PrintNode(BinTreeNode* n)
{
    printf("info=%c,lchild=%d,rchild=%d\n",n->info,(n->lchild!=NULL),(n->rchild!=NULL));
}

void InOrderTraverse(PBinTree T)
{
    if(T!=NULL){
        
        InOrderTraverse(T->lchild);
        printf("%c ",T->info);
        InOrderTraverse(T->rchild);
        
    }
    return;
}

void PreOrderTraverse_stack(PBinTree T)
{
    PBinTree TT = T;
    PLinkStack TS = createEmptyStack_link();
    do{
        while(TT!=NULL){
            printf("%c",TT->info);
            push_link(TS,TT);
            TT = TT->lchild;
        }
        if(!isEmptyStack_link(TS)){
            TT = pop_link(TS);
            TT = TT->rchild;
        }
    }while(TT!=NULL||!isEmptyStack_link(TS));
}

void InOrderTraverse_stack(PBinTree T)
{
    PBinTree TT = T;
    PLinkStack TS = createEmptyStack_link();
    do{
        while(TT!=NULL){
            push_link(TS,TT);
            TT = TT->lchild;
        }
        if(!isEmptyStack_link(TS)){
            TT = pop_link(TS);
            printf("%c",TT->info);
            TT = TT->rchild;
        }
    }while(TT!=NULL||!isEmptyStack_link(TS));
}

void PostOrderTraverse_stack(PBinTree T)
{
    PBinTree TT = T;
    struct Node* TN = (struct Node * )malloc(sizeof(struct Node));
    TN->tag = 'L';
    PLinkStack TS = createEmptyStack_link();
    do
    {
        while (TT!=NULL)
        {
            if (TN->tag!='R') push_link_b(TS,TT,'L');
            TT = TT->lchild;
        }
        int continueNum = 1;
        while (continueNum && !isEmptyStack_link(TS))
        {
            TN = pop_link_b(TS);
            TT = TN->info;
            switch (TN->tag)
            {
            case 'L':
                continueNum = 0;
                push_link_b(TS,TT,'R');
                TT = TT->rchild;//!!!!!
                break;
            case 'R':
                printf("%c",TT->info);
                break;
            }
        }
    } while (TT!=NULL||!isEmptyStack_link(TS));
    

}