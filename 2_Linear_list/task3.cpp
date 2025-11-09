/*
* 必做任务3,源代码
*/
#include<iostream>
#include "task3.h"
using namespace std;

// 尾插法创建链表
void init_from_end(node *&list, int val){
    node *newnode=new node;
    newnode->data=val;
    newnode->next=NULL;
    if(list==NULL){
        list=newnode;
        return ;
    }
    node *tmp=list;
    while(tmp->next!=NULL){
        tmp=tmp->next;
    }
    tmp->next=newnode;
}

// 打印函数
void list_print(node *list){
    node *tmp=list;
    int cnt=0;
    if(tmp!=NULL){
        printf("Hello , I'm a haha listnode ,you can see my number :\n");
    }
    while(tmp!=NULL){
        printf("NO.%d : %d\n",cnt,tmp->data);
        tmp=tmp->next;
        cnt++;
    }
}

// 设计算法
// 大体思路：只要另一个链表用头插法建立即可
void list_reverse(node *&list){ //注意指针传递不行，需要指针引用传递才能改变指针，否则只能改变指针指向的值
    node *newlist=NULL;
    node *mov=list;
    while(mov!=NULL){
        node *tmp=mov->next; //tmp维护链表后继
        mov->next=newlist;
        newlist=mov;
        mov=tmp;
    }
    list=newlist;
}

// 销毁链表
void list_free(node *&list){
     // 释放链表
    node *cur=list;
    while(cur){
        node *next=cur->next;
        delete cur;
        cur=next;
    }
}

int main(){
    node *list=NULL;
    for(int i=1;i<=5;i++){
        init_from_end(list,i);
    }
    list_print(list);
    list_reverse(list);
    list_print(list);
    list_free(list);
    return 0;
}