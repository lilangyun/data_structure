#include<iostream>
using namespace std;


// 我们先默认数据类型为int类型
typedef struct node{
    node *prev; //前驱
    int data;
    node *next; //后继
}node;
// 默认双向链表无头结点

// 尾插法
void init_end(node *&head,int val){
    node *newnode=new node;
    newnode->data=val;
    newnode->prev=NULL;
    newnode->next=NULL;
    if(head==NULL){
        head=newnode;
        return ;
    }
    node *tmp=head;
    while(tmp!=NULL){
        if(tmp->next==NULL){
            break;
        }
        tmp=tmp->next;
    }
    // 此时tmp指向最后一个元素
    tmp->next=newnode;
    newnode->prev=tmp;
}

// 双向链表插入1[工作结点指向index]
void insert1_two_way_list(node *&head,int index,int val){
    if(!head||index<0){
        printf("Invalid parameters to insert_elem\n");
        return;
    }
    // 建立新结点
    node *newnode=new node;
    newnode->data=val;
    newnode->prev=NULL;
    newnode->next=NULL;
    // 考虑index为0的情况
    if(index==0){
        newnode->next=head;
        head->prev=newnode;
        head=newnode;
        return ;
    }
    // 应当找到指向下标为index-1的结点
    node *tmp=head;
    for(int i=0;i<index-1;i++){
        if(tmp->next==NULL){
            // 这里默认index太大插到末尾
            printf("The index is big,so we have to insert %d into the end!\n",val);
            break;
        }
        tmp=tmp->next;
    }
    // 找到位置后
    node *q=tmp->next;
    tmp->next=newnode;
    newnode->prev=tmp;
    newnode->next=q;
    // 考虑q指向null的情况
    if(q!=NULL){
        q->prev=newnode;
    }
}

// 双向链表插入2[工作结点指向index-1]
void insert2_two_way_list(node *&head,int index,int val){
    if(!head||index<=0){ //注意这里0是不允许的
        printf("Invalid parameters to insert_elem\n");
        return;
    }
    node *newnode=new node;
    newnode->data=val;
    newnode->prev=NULL;
    newnode->next=NULL;
    // 新结点建立完毕

    if(index==1){ //考虑插在head之前情况
        head->prev=newnode;
        newnode->next=head;
        head=newnode;
        return ;
    }

    // 应当找到指向下标为index的结点
    node *tmp=head;
    for(int i=0;i<index-2;i++){
        if(tmp->next==NULL){
            printf("The index is big,so we have to insert %d into the end!\n",val);
            break;
        }
        tmp=tmp->next;
    }
    // 找到位置后
    node *q=tmp->next;
    tmp->next=newnode;
    newnode->prev=tmp;
    newnode->next=q;
    if(q!=NULL){
        q->prev=newnode;
    }
}

// 双向链表插入3[工作结点指向index+1]
void insert3_two_way_list(node *&head,int index,int val){
    if(!head||index<-1){ //这里又变为-1
        printf("Invalid parameters to insert_elem\n");
        return;
    }
    node *newnode=new node;
    newnode->data=val;
    newnode->prev=NULL;
    newnode->next=NULL;

    // 做同样的工作
    if(index==-1){
        newnode->next=head;
        head->prev=newnode;
        head=newnode;
        return ;
    }

    node *tmp=head;
    // 应当找到指向下标为index的结点
    for(int i=0;i<index;i++){
        if(tmp->next==NULL){
            printf("The index is big,so we have to insert %d into the end!\n",val);
            break;
        }
        tmp=tmp->next;
    }
    // 找到位置后
    node *q=tmp->next; //q维护原index下标的结点
    tmp->next=newnode;
    newnode->prev=tmp;
    newnode->next=q;
    if(q!=NULL){
        q->prev=newnode;
    }
}

// 双向链表删除1[工作结点指向index]
void delete1_two_way_list(node *&head,int index){
    if(!head||index<0){
        printf("Invalid parameters to insert_elem --Delete1!\n");
        return;
    }
    node *tmp=head;
    for(int i=0;i<index;i++){
        if(tmp->next==NULL){
            printf("Index is large,we can't delete!!\n");
            return ;
        }
        tmp=tmp->next;
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
    if(!head||index<=0){
        printf("Invalid parameters to insert_elem --Delete2!\n");
        return;
    }
    node *tmp=head;
    // 应当找到指向下标为index的结点
    for(int i=0;i<index-1;i++){
        if(tmp->next==NULL){
            printf("Index is large,we can't delete!!\n");
            return ;
        }
        tmp=tmp->next;
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
    if(!head||index<-1){
        printf("Invalid parameters to insert_elem --Delete3!\n");
        return;
    }
    node *tmp=head;
    for(int i=0;i<index+1;i++){
        if(tmp->next==NULL){
            printf("Index is large,we can't delete!!\n");
            return ;
        }
        tmp=tmp->next;
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

// 按值查找
int find_by_val(node *head, int val){
    if(!head)return -1;
    node *tmp=head;
    int cnt=0;
    while(tmp!=NULL){
        if(tmp->data==val){
            printf("The index is %d,we find it !\n",cnt);
            return cnt;
        }
        tmp=tmp->next;
        cnt++;
    }
    return -1; // 表示没找到
}

// 按下标查找
int find_by_index(node *head,int index){
    if(!head)return -1;
    node *tmp=head;
    int cnt=0;
    while(tmp!=NULL){
        if(cnt==index){
            printf("The value is %d,we find it !\n",tmp->data);
            return tmp->data;
        }
        tmp=tmp->next;
        cnt++;
    }
    printf("The index is false,we can't find!\n");
    return -1; //表示找不到
}

// 打印函数
void list_print(node *list){
    node *tmp=list;
    int cnt=0;
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
    int x;
    cin>>x;
    // 调试insert1
    // insert1_two_way_list(head,x,-521);
    // success
    // 调试insert2
    // insert2_two_way_list(head,x,-521);
    // success
    // 调试insert3
    // insert3_two_way_list(head,x,-521);
    // success
    // delete3_two_way_list(head,x);
    find_by_val(head,x);
    list_print(head);

    return 0;
}