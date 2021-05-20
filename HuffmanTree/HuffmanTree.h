//数据结构设计
#include<stdlib.h>
#include<stdio.h>
#include<string.h>

typedef struct HuffmanNode{
    int weight;
    char info;
    char* code;
    struct HuffmanNode* lchild;
    struct HuffmanNode* rchild;
    struct HuffmanNode* parent;
}HmNode,*HmTree;

int FindLeastWeight(char s[],int w[],int len) //len代表数组里的元素数
{
    int index = 0;
    int num = w[0];
    for(int i=0;i<len;i++)
    {
        if(w[i]<num){
            num = w[i];
            index = i;
        }
    }
    return index; //返回最小值在数组里的索引
}

void Del(char s[],int w[],int n,int index)//删除字符数组的元素
{
    if(n==1) return;
    else{
        for(int i=index;i<n-1;i++){
            s[i]=s[i+1];
            w[i]=w[i+1];
        }
    }
    return ;
}

HmTree GenerateATree(HmTree lchild, HmTree rchild)
{
    HmTree parent = (HmTree)malloc(sizeof(HmNode));
    parent->lchild = lchild;
    parent->rchild = rchild;
    parent->weight = lchild->weight + rchild->weight;
    return parent;
}

HmTree GenerateHuffmanTree(char s[],int w[],int n) //输入字符、权重、字符个数，编码生成一棵Huffman树
{
    int loop = 1; //循环次数，从1到n
    int leastWeightIndex = -1;//最小权重的索引
    int preWeight = 0;//记录上一棵Huffman树的权和
    HmTree HT = (HmTree)malloc(sizeof(HmNode));
    HmTree newHT = (HmTree)malloc(sizeof(HmNode));
    HmTree lastHT = (HmTree)malloc(sizeof(HmNode));
    //找两个元素生成一棵基本的Huffman树,借用一下已有的三个tree实例
    leastWeightIndex = FindLeastWeight(s,w,n-loop+1);
    newHT->info = s[leastWeightIndex];
    newHT->weight = w[leastWeightIndex];
    newHT->lchild = NULL;
    newHT->rchild = NULL;
    Del(s,w,n-loop+1,leastWeightIndex);
    loop++;
    leastWeightIndex = FindLeastWeight(s,w,n-loop);
    lastHT->info = s[leastWeightIndex];
    lastHT->weight = w[leastWeightIndex];
    lastHT->lchild = NULL;
    lastHT->rchild = NULL;
    Del(s,w,n-loop+1,leastWeightIndex);
    loop++;
    HT = GenerateATree(newHT,lastHT);
    lastHT = HT;
    //至此，取了两个最小元素，生成了三个结点的最小Huffman树，其根记录在lastHT里

    //下面进行后序处理，每次循环内生成一个新结点，把它加入到生成的Huffman树里
    while(loop <= n)
    {
        //生成新结点
        newHT = (HmTree)malloc(sizeof(HmNode));
        leastWeightIndex = FindLeastWeight(s,w,n-loop+1);    
        newHT->info = s[leastWeightIndex];
        newHT->weight = w[leastWeightIndex];
        newHT->lchild = NULL;
        newHT->rchild = NULL;
        Del(s,w,n-loop+1,leastWeightIndex);
        //判断左右,生成新树
        HT = (newHT->weight < lastHT->weight ? GenerateATree(newHT,lastHT) : GenerateATree(lastHT,newHT));
        //记录在lastHT里
        lastHT = HT;
        loop++;
    }
    return HT;
}

// char ** Encoder(HmTree HT,int n)//对n个字符进行编码,结果存在一个n行的2维字符数组里
// {   
//     HmTree tHT = HT;
//     int flag = 1; //flag标记是否已经找到某一个字符
//     for(int i=0;i<n;i++){
//         while (flag)
//         {   
//             if()
//         }
        
        
//     }
// }

char* addChar(char * origin,int tag)
{
    if(origin==NULL) origin = (char*)malloc(sizeof(char));
    char *t = (char*)malloc(sizeof(char));
    t = strcpy(t,origin);
    if(tag==0)
        t = strcat(t,"0");
    else
        t = strcat(t,"1");
    return t;
}

void Encoder(HmTree HT)//计算并记录每一个叶子的编码
{
    if(HT->lchild!=NULL){
        HT->lchild->code = addChar(HT->code,0);
        Encoder(HT->lchild);
        HT->rchild->code = addChar(HT->code,1);
        Encoder(HT->rchild);
    }
    return ;
}

void GetEncoding(HmTree HT,char ** hashLabel) //得到n个字符的编码对应，用哈希映射到字符串数组里
{
    if(HT!=NULL){
        if(HT->lchild==NULL) hashLabel[(int)HT->info]=HT->code;
        GetEncoding(HT->lchild,hashLabel);
        GetEncoding(HT->rchild,hashLabel);
    }
    return ;
}

void EncodeAndPrint(char* s,int n,char** hashLabel)
{
    for(int i=0;i<n;i++){
        for(int j=0;j<strlen(hashLabel[(int)s[i]]);j++){
            printf("%c",hashLabel[(int)s[i]][j]);
        }
        printf(" ");
    }
}

void InOrderPrintTheTree(HmTree HT)
{
    if(HT!=NULL)
    {
        InOrderPrintTheTree(HT->lchild);
        printf("%c",HT->info);
        InOrderPrintTheTree(HT->rchild);
    }
    return;
}