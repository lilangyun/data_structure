#include<iostream>
using namespace std;

#define datatype int

typedef struct node{
    datatype data;
    node *next;
}node;

// 头插法
void init_from_head(node *head, int val){
    if(!head)return;
    node *tmp=new node;
    tmp->data=val;
    tmp->next=head->next;
    head->next=tmp;
}

// 尾插法
void init_from_end(node *head, int val){
    if(!head) return;
    node *tmp=head;
    while(tmp->next!=NULL){
        tmp=tmp->next;
    }
    node *newnode=new node;
    newnode->data=val;
    newnode->next=NULL;
    tmp->next=newnode;
}

// 插入元素：在位置 index 处插入（0 表示第一个数据节点）
void insert_elem(node *head, int val, int index){
    if(!head||index<0){
        printf("Invalid parameters to insert_elem\n");
        return;
    }
    node *tmp=head;
    for(int i=0;i<index;i++){
        // 默认如果index超出范围自动从末尾插入
        if(tmp->next==NULL){
            break;
        }
        tmp=tmp->next;
    }
    node *p=new node;
    p->data=val;
    p->next=tmp->next;
    tmp->next = p;
}

// 删除元素
void delete_elem(node *head,int index){
    // 同样先找到指向下标为index-1的指针
    node *tmp=head;
    for(int i=0;i<index;i++){
        if(tmp->next==NULL){
            printf("The index is false!Can't delete!!\n");
        }
        tmp=tmp->next;
    } 
    if(tmp->next==NULL){
        printf("The index is false!Can't delete!!\n");
    }
    node *p=tmp->next;
    tmp->next=p->next;
    delete p;
}

// 按值查找
int find_by_val(node *head, datatype val){
    if(!head)return -1;
    node *tmp=head->next;
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
datatype find_by_index(node *head,int index){
    if(!head)return -1;
    node *tmp=head->next;
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

// 打印
void list_print(node *head){
    node *tmp=head->next;
    int cnt=0;if(tmp->next!=NULL){
        printf("Hello , I'm a haha listnode ,you can see my number :\n");
    }
    while(tmp!=NULL){
        printf("NO.%d : %d\n",cnt,tmp->data);
        tmp=tmp->next;
        cnt++;
    }
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
    node *head = new node;
    head->next = NULL;
    int x;
    printf("Please input your number : ");
    for(int i=0;i<7;i++){
        scanf("%d",&x);
        init_from_end(head,x);
    }
    list_print(head);

    insert_elem(head,8,3);
    list_print(head);

    delete_elem(head,3);
    list_print(head);

    int ans=find_by_index(head,4);
    if(ans!=-1){
        printf("The number is : %d\n",ans);
    }
    // 释放链表
    list_free(head);
    return 0;
}