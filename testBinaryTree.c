#include "binaryTree_Linked.c"


void test()
{
    PBinTree testTree = (PBinTree)malloc(sizeof(BinTreeNode));
    testTree = InputBinTree(testTree);
    // inOrderTraverse(testTree);
    // PreOrderTraverse_stack(testTree);
    // InOrderTraverse(testTree);
    PostOrderTraverse_stack(testTree);
}

int main()
{
    int x;
    test();
    scanf("%d",&x);
    return 0;
}