/*
* 必做题4·源代码
*/
#include<iostream>
#include<stdarg.h>
using namespace std;

#define OVERFLOW 3
#define UNDERFLOW 4
#define MAXDIM 8

typedef struct{
    int *base;  //数组基址
    int dim;  //是几维数组
    int *bouds;  //每个维度有多少个元素值
    int *constants;  //用于计算偏移量
}Array;

int InitiArray(Array *A,int dim,...){
    // 这是我第一次接触省略号的可变参数
    if(dim<1||dim>MAXDIM){
        return -1;
    }
    A->dim=dim;
    A->bouds=new int[dim];
    if(!A->bouds){
        exit(OVERFLOW);  //说明上溢，无法分配空间了
    }
    int count=1,i;
    va_list ap;
    va_start(ap,dim);
    for(i=0;i<dim;i++){
        A->bouds[i]=va_arg(ap,int);
        if(A->bouds[i]<0){
            exit(UNDERFLOW);  //说明想申请的维数为负数，出错
        }
        count*=A->bouds[i];
    }
    va_end(ap);
    A->base=new int[count];  //为所有元素分配空间
    if(!A->base){
        exit(OVERFLOW);  //这样的检查应该是个不错的习惯
    }
    // 倒序求constant
    A->constants=new int [dim];
    A->constants[dim-1]=1;
    int j;
    for(j=dim-2;j>=0;j--){
        A->constants[j]=A->constants[j+1]*A->bouds[j+1];
    }
    return 0;
}

int DestroyArray(Array *A){
    if(A->base){
        delete A->base;
        A->base=NULL;
    }
    else{
        return -1;
    }
    if(A->bouds){
        delete A->bouds;
        A->bouds=NULL;
    }
    else{
        return -1;
    }
    if(A->constants){
        delete A->constants;
        A->constants=NULL;
    }
    else{
        return -1;
    }
    return 0;
}

int Locate(){

}

int Value(Array *A,int *val,...){  //取值操作
    va_list ap;
    int off;  //相对于基地址的偏移量
    int dim=A->dim;
    int i;
    va_start(ap,val);
    for(i=0;i<dim;i++){
        int ind=va_arg(ap,int);
        off+=A->constants[i]*ind;
    }
    va_end(ap);
    *val=A->base[off];
    return 0;
}

int Assign(Array *A,int val,...){  //赋值操作
    va_list ap;
    int off;
    int dim=A->dim;
    int i;
    for(i=0;i<dim;i++){
        int ind=va_arg(ap,int);  //这里还需要补充错误情况的处理
        off+=A->constants[i]*ind;
    }
    va_end(ap);
    A->base[off]=val;
    return 0;
}

int main(){
    
    return 0;
}