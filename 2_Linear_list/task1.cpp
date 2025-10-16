#include<iostream>
#include<stdlib.h>
using namespace std;

#define capacity 100
#define datatype int

typedef struct{
    datatype *head;
    int len;
}SqList;

// 创建顺序表
void init_SqList(SqList &sqlist){
    // 没有头结点的顺序表
    sqlist.head=(datatype*)malloc(capacity*sizeof(datatype));
    sqlist.len=0;
}

// 在下标为index元素前面插入元素
void insert_SqList(SqList&sqlist,int index,datatype data){
    datatype *tmp=sqlist.head;
    int len=sqlist.len;
    if(index<0||index>len){
        printf("Index is invalid!!\n");
        return ;
    }
    if(len==capacity){
        printf("Now sqlist is full,can't insert!!\n");
        return ;
    }
    // 先移动下标为index及之后的元素
    for(int i=len-1;i>=index;i--){
        *(tmp+i+1)=*(tmp+i);
    }
    *(tmp+index)=data;
    sqlist.len++;
}

// 删除下标为index的元素
void delete_SqList(SqList&sqlist,datatype index){
    datatype *tmp=sqlist.head;
    int len=sqlist.len;
    if(index<0||index>=len){
        printf("Index is invalid!!\n");
        return ;
    }
    if(len==0){
        printf("Now sqlist is empty,can't delete!!\n");
        return ;
    }
    for(int i=index;i<len-1;i++){
        *(tmp+i)=*(tmp+i+1);
    }
    sqlist.len--;
}

// 按值查找顺序表中的元素
int find_by_val(SqList&sqlist,datatype val){
    int len=sqlist.len;
    datatype *tmp=sqlist.head;
    for(int i=0;i<len;i++){
        if(*(tmp+i)==val){
            return i;
        }
    }
    printf("I'm sorry,Find by val is failed!!\n");
    return -1;
}

// 按索引查找元素
datatype find_by_index(SqList&sqlist,int index){
    int len=sqlist.len;
    datatype *tmp=sqlist.head;
    if(index<0||index>=len){
        printf("Index is invalid!!\n");
        return -1;
    }
    return *(tmp+index);
}

// 输出顺序表中的元素
void print_elem(SqList&sqlist){
    int len=sqlist.len;
    datatype *tmp=sqlist.head;
    for(int i=0;i<len;i++){
        // 这里先默认datatype为int
        printf("NO.%d : %d\n",i,*(tmp+i));
    }
}

// 求平均值并插入
void get_average(SqList&sqlist){
    int len=sqlist.len;
    datatype *tmp=sqlist.head;
    if(len==0){
        printf("Now sqlist is empty,can't calculate average!!\n");
        return ;
    }
    long long sum=0;
    for(int i=0;i<len;i++){
        sum+=*(tmp+i);
    }
    datatype average=sum/len;
    int pos=(len-1)/2;
    printf("Now average is %d.\n",average);
    insert_SqList(sqlist,pos,average);
}

// 测试
int main(){
    SqList a;
    init_SqList(a);
    for(int i=1;i<=5;i++){
        insert_SqList(a,0,i);
    }
    print_elem(a);
    datatype x=find_by_index(a,2);
    cout<<x<<endl;
    int ans=find_by_val(a,3);
    cout<<ans<<endl;
    // get_average(a);
    // print_elem(a);
    delete_SqList(a,(a.len-1)/2);
    print_elem(a);
}