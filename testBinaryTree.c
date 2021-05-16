#include "binaryTree_Linked.c"


void test()
{
    PBinTree testTree = (PBinTree)malloc(sizeof(BinTreeNode));
    testTree = InputBinTree(testTree);
    InOrderTraverse(testTree);
}

int main()
{
    test();
    while(1);
    return 0;
}