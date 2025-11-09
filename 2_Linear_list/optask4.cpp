/*
* 选做任务4
*/

// 题目来源:https://www.luogu.com.cn/problem/P1996#ide

#include<iostream>
using namespace std;

// 循环链表
typedef struct node{
    int data;
    node *next;
}node;

// 头指针初始化
void init(node *&h){
    h=NULL;
}

// 创建新节点
node *creat_node(int data){
    node *nd=new node;
    nd->data=data;
    nd->next=NULL;
    return nd;
}

// 默认尾插法
void input(node *&h,int data){
    node *nd=creat_node(data);
    if(h==NULL){
        h=nd;
        nd->next=nd;  //next指针指向自己
        return ;
    }

    node *t=h;
    while(t->next!=h){
        t=t->next;
    }
    t->next=nd;
    nd->next=h;
}

// 删除t结点
void node_delete(node *&h,node *p){
    if(h==NULL){
        fprintf(stderr,"null list\n");
        return ;
    }
    node *t=h;
    while(t->next!=p){
        t=t->next;
    }
    if(p==h){
        h=p->next;
    }
    t->next=p->next;
    delete p;
}

// 用循环链表模拟约瑟夫问题
void joesphus(int n,int k){
    node *h;
    init(h);
    for(int i=1;i<=n;i++){
        input(h,i);
    }
    int cnt=n;
    node *t=h;
    while(cnt){
        for(int i=1;i<k;i++){
            t=t->next;
        }
        node *p=t;
        cout<<p->data<<" ";
        t=t->next;
        node_delete(h,p);
        cnt--;
    }
    cout<<endl;
}

int main(){
    int n,k;
    cin>>n>>k;
    joesphus(n,k);
    return 0;
}