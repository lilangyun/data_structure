/*
* 必做题4(1)·头文件
*/
#define OVERFLOW 3
#define UNDERFLOW 4
#define MAXDIM 8

typedef struct{
    int *base;  //数组基址
    int dim;  //是几维数组
    int *bouds;  //每个维度有多少个元素值
    int *constants;  //用于计算偏移量
}Array;

int InitiArray(Array *&A,int dim,...);

int DestroyArray(Array *&A);

int Value(Array *&A,int *val,...);

int Assign(Array *&A,int val,...);