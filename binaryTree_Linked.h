#define DataType char


typedef struct Linkstack
{
    struct Node *top;
}LinkStack,*PLinkStack;

int myMax(int a,int b)
{
    return (a>b?a:b);
}

typedef struct BinTreeNode
{
    DataType info;
    struct BinTreeNode * lchild;
    struct BinTreeNode * rchild;
    // struct BinTreeNode * parent; 
}BinTreeNode,*PBinTree;

struct  Node
{
    PBinTree info;
    char tag;
    struct Node * link;
};
