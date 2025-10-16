#include<iostream>
using namespace std;

// 自己竟然全部实现错了，啊！

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

// 按值查找
node *find_by_val(node *head, int val){
    node *tmp=head;
    int cnt=0;
    while(tmp!=NULL){
        if(tmp->data==val){
            printf("The index is %d,we find it !\n",cnt);
            return tmp; //这里我们改变一直以来的方式，直接返回结点
        }
        tmp=tmp->next;
        cnt++;
    }
    return NULL; // 表示没找到
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

// 双向链表插入1[工作结点指向index]
void insert1_two_way_list(node *&head,int index,int val){
    // 建立新结点
    node *newnode=creat_newnode(val);
    // 找到index处结点
    node *tmp=find_by_index(head,index);
    if(tmp==NULL){
        delete newnode;
        return ;
    }
    // 插入处理
    node *p=tmp->prev; //前驱
    if(p==NULL){
        // 说明要插入位置将作为头结点
        head=newnode;
    }
    else{
        p->next=newnode;
    }
    newnode->prev=p; //新节点前驱指向p
    newnode->next=tmp;
    tmp->prev=newnode;
}

// 双向链表插入2[工作结点指向index-1]
void insert2_two_way_list(node *&head,int index,int val){
    node *newnode=creat_newnode(val);
    // 应当找到指向下标为index-1的结点
    node *tmp=find_by_index(head,index-1);
    if(tmp==NULL){
        delete newnode;
        return ;
    }
    // 插入处理
    node *p=tmp->next; //p为index结点
    tmp->next=newnode;
    newnode->prev=tmp;
    newnode->next=p;
    if(p!=NULL){
        p->prev=newnode;
    }
}

// 双向链表插入3[工作结点指向index+1]
void insert3_two_way_list(node *&head,int index,int val){
    node *newnode=creat_newnode(val);
    node *tmp=find_by_index(head,index+1);
    if(tmp==NULL){
        delete newnode;
        return ;
    }
    // 插入处理
    node *p=tmp->prev; //p表示index结点
    if(p->prev!=NULL){
        p->prev->next=newnode;
    }
    else{
        head=newnode;
    }
    newnode->prev=p->prev;
    newnode->next=p;
    p->prev=newnode;
}

// 双向链表删除1[工作结点指向index]
void delete1_two_way_list(node *&head,int index){
    node *tmp=find_by_index(head,index);
    if(tmp==NULL){
        return ;
    }
    // 找到index位置后
    if(index==0){ //没前驱
        head=head->next;
        delete tmp;
        return ;
    }
    if(tmp->next!=NULL){ //没后继
        tmp->next->prev=tmp->prev;
    }
    tmp->prev->next=tmp->next;
    delete tmp;
}

// 双向链表删除2[工作结点指向index-1]
void delete2_two_way_list(node *&head,int index){
    node *tmp=find_by_index(head,index-1);
    if(tmp==NULL){
        return ;
    }
    // 找到位置后
    if(index==1){ //没前驱
        head=head->next;
        delete tmp;
        return ;
    }
    if(tmp->next!=NULL){ //没后继
        tmp->next->prev=tmp->prev;
    }
    tmp->prev->next=tmp->next;
    delete tmp;
}

// 双向链表删除3[工作结点指向index+1]
void delete3_two_way_list(node *&head,int index){
    node *tmp=find_by_index(head,index+1);
    if(tmp==NULL){
        return ;
    }
    // 找到位置后
    // 找到index+1位置后
    if(index==-1){ //没前驱
        head=head->next;
        delete tmp;
        return ;
    }
    if(tmp->next!=NULL){ //没后继
        tmp->next->prev=tmp->prev;
    }
    tmp->prev->next=tmp->next;
    delete tmp;
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

int main(){
    node *head=NULL;
    for(int i=1;i<=5;i++){
        init_end(head,i);
    }
    list_print(head);
    int x=3;
    // 调试insert1
    // insert1_two_way_list(head,x,-521);
    // success
    // 调试insert2
    insert1_two_way_list(head,5,-521);
    // success
    // 调试insert3
    // insert3_two_way_list(head,x,-521);
    // success
    // delete3_two_way_list(head,x);
    // find_by_val(head,x);
    list_print(head);

    return 0;
}