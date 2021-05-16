#define MAXNODE 100
#define DataType int
typedef struct  SeqBTree
{
    DataType nodelist[MAXNODE+1];
    int n;
}SeqBTree,*PSeqBTree;

