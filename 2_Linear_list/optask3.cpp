/*
* 选做任务3 
*/

#include<iostream>
using namespace std;

// 我们先默认数据类型为int类型
typedef struct node{
    node *prev; //前驱
    int data;
    node *next; //后继
}node;
// 默认双向链表无头结点

// 我们把创建新节点封装成一个函数，减少代码量
node *creat_newnode(int val){
    node *newnode=new node;
    newnode->data=val;
    newnode->prev=NULL;
    newnode->next=NULL;
    return newnode;
}

// 尾插法
void init_end(node *&head,int val){
    node *newnode=creat_newnode(val);
    // 建立新节点
    if(head==NULL){
        head=newnode;
        return ;
    }
    // 如果双向链表为空，就将新的结点作为首结点
    node *tmp=head;
    while(tmp!=NULL){
        if(tmp->next==NULL){
            // 如果tmp为最后一个元素，就退出循环将元素插至tmp之后
            break;
        }
        // 否则就一直向后移动
        tmp=tmp->next;
    }
    // 此时tmp指向最后一个元素
    tmp->next=newnode;
    newnode->prev=tmp;
}

// 按下标查找
node *find_by_index(node *head,int index){
    node *tmp=head;
    int cnt=0;
    while(tmp!=NULL){
        if(cnt==index){
            // printf("The value is %d,we find it !\n",tmp->data);
            return tmp;
        }
        tmp=tmp->next;
        cnt++;
    }
    printf("The index is false,we can't find!\n");
    return NULL; //表示找不到
}

// 打印函数
void list_print(node *list){
    node *tmp=list;
    while(tmp!=NULL){
        printf("%d ",tmp->data);
        tmp=tmp->next;
    }
    cout<<endl;
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

void find_game(node *first,int n){
    node *tmp=find_by_index(first,n-1);
    if(tmp->prev==NULL){
        fprintf(stdout,"The prev : NULL\n");
    }
    else{
        fprintf(stdout,"The prev : %d\n",tmp->prev->data);
    }
    if(tmp->next==NULL){
        fprintf(stdout,"The next : NULL\n");
    }
    else{
        fprintf(stdout,"The next : %d\n",tmp->next->data);
    }
}

int main(){
    node *first=NULL;
    for(int i=0;i<5;i++){
        init_end(first,i+1);
    }
    list_print(first);
    int n;
    cout<<"Please input your 'n' :"<<endl;
    cin>>n;
    find_game(first,n);
    return 0;
}