/*
* 必做题4(2)·头文件
*/
#define MAXSIZE 1200

typedef struct{
    int i,j;
    int val;
}Triple;

typedef struct{
    Triple data[MAXSIZE+1];
    int mu,nu,tu;  //行、列、非零元个数 
}TsMatrix;  //三元组矩阵

typedef struct OLNode{
    int i,j;
    int val;
    struct OLNode*down,*right;
}OLNode,*OLink;

typedef struct{
    OLink *rhead,*chead;  //row_head and column_head
    int mu,nu,tu;
}CrossList;  //十字链表

void create_TsMatrix(TsMatrix*&M);

TsMatrix* transpose_TsMatrix(TsMatrix*M);

void printTsMatrix(TsMatrix *M);

void creatCrossList(CrossList*M);

CrossList *transpose_CrossList(CrossList *M);

void printCrossLink(CrossList*M);