/*
* 选做任务2
*/

#include<iostream>
using namespace std;

#define MAXSIZE 20

// 用静态链表实现
typedef struct{
    int data;  //数据域
    int next;  //模拟指针域
}component,SLinklist[MAXSIZE];

// 先将MAXSIZE个元素形成一个链表统一起来,不涉及到数据域
void init_slinklist(SLinklist &list){
    // 这里我们规定list[0]即list是头结点
    for(int i=0;i<MAXSIZE;i++){
        list[i].next=i+1;
    }
    // 这里教材上将尾结点的指针位设置为0，可以用做表尾的标志
    list[MAXSIZE-1].next=0;
}

void input_elem(SLinklist &list,int data,int index){
    // index表示元素插入后的下标
    if(index<=0||index>=MAXSIZE){
        // 按照csapp中格式化输出错误
        fprintf(stderr,"The index is illegal!\n");
        return ;
    }
    // 相比于单链表，静态链表可直接通过下标访问
    list[index].data=data;
}

void mov_list(SLinklist list,int n){
    // 链表右移n位函数
    int head=list[0].next;
    int prev,cur;
    while(n--){
        prev=0;
        cur=head;
        while(list[cur].next!=0){
            prev=cur;
            cur=list[cur].next;
        }
        list[cur].next=head;
        list[prev].next=0;
        head=cur;
    }
    list[0].next=head;
}

void print_slinklist(SLinklist list){
    int head=list[0].next;
    int tmp=head;
    while(tmp!=0){
        fprintf(stdout,"%d ",list[tmp].data);
        tmp=list[tmp].next;
    }
    cout<<endl;
}

int main(){
    SLinklist list;
    int n;
    fflush(stdout);
    fprintf(stdout,"Please input the number you want to move : \n");
    fflush(stdout);
    cin>>n;
    int i;
    init_slinklist(list);
    for(i=1;i<=5;i++){
        input_elem(list,i,i);
    }
    list[5].next=0;  //将尾巴结点的next置为0，表示结束

    print_slinklist(list);
    mov_list(list,n);
    print_slinklist(list);
    return 0;
}