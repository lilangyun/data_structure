#include<iostream>
using namespace std;

#define MAXLENGTH 10

// 顺序结构线性表
// 这里的顺序表示的应为存储结构
struct List{
    int data[MAXLENGTH];
    int length;
};

void mov_list(List *&list,int n){
    // 将表头结点作为引用传入
    int len=list->length;
    // 可以运用%len的方法去移动
    while(n--){ //n表示移动次数
        int t=*(list->data+len-1);
        // t表示表尾结点
        for(int i=len-2;i>=0;i--){
            *(list->data+i+1)=*(list->data+i);
        }
        *list->data=t;
    }
}

// 输出顺序表中的元素
void print_elem(List *&list){
    int len=list->length;
    for(int i=0;i<len;i++){
        printf("NO.%d is %d!\n",i,list->data[i]);
    }
}

int main(){
    int n;
    cin>>n;
    List *list=new List;
    list->length=0;
    for(int i=0;i<=4;i++){
        list->data[i]=i+1;
        list->length++;
        // 这里还需要改进，要加入插入算法
    }
    print_elem(list);
    mov_list(list,n);
    print_elem(list);
    delete list;
    return 0;
}