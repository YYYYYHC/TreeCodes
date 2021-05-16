#include<stdio.h>
#include<stdlib.h>
#define DataType char
typedef struct BinTreeNode
{
    DataType info;
    struct BinTreeNode * lchild;
    struct BinTreeNode * rchild;
    // struct BinTreeNode * parent; 
}BinTreeNode,*PBinTree;

// PBinTree CreateBinTree(DataType info )
// {
//     PBinTree root = (BinTreeNode*)malloc(sizeof(BinTreeNode));
//     root->lchild = NULL;
//     root->rchild = NULL;
//     return root;
// }

// void AddBinTreeNode(PBinTree parent,DataType linfo,DataType rinfo)
// {
//     PBinTree lchild = CreateBinTree(linfo);
//     PBinTree rchild = CreateBinTree(rinfo);
//     parent->lchild = lchild;
//     parent->rchild = rchild;
// }

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
        InOrderTraverse(T->rchild);
        printf("%c ",T->info);
    }
    return;
}
