#include"HuffmanTree.h"

int main()
{
    int n,w[100];
    char s[100];
    int _;
    scanf("%d",&n);
    scanf("%c",&_);
    for(int i=0;i<n;i++)
    {
        scanf("%c",&s[i]);
        scanf("%c",&_);
    }
    for(int i=0;i<n;i++)
    {
        scanf("%d",&w[i]);
    }
    char* ts = (char*)malloc(sizeof(char));
    ts = strcpy(ts,s);

    HmTree testTree =  GenerateHuffmanTree(ts,w,n);

    Encoder(testTree);
    char ** hashLabel = (char**)malloc(sizeof(char*)*1000);
    GetEncoding(testTree,hashLabel);
    EncodeAndPrint(s,n,hashLabel);
    scanf("%d",&n);
    return 0;
}