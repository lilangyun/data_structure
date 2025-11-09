/*
* 必做任务4,头文件
*/
#ifndef TASK4_H
#define TASK4_H

typedef struct node{
    node *prev; //前驱
    int data;
    node *next; //后继
}node;  // 双向链表

node *creat_newnode(int val);  // 创建新节点
void init_end(node *&head,int val);  // 尾插法
node *find_by_val(node *head, int val);  // 按值查找
node *find_by_index(node *head,int index);  // 按下标查找
void insert1_two_way_list(node *&head,int index,int val);  // 双向链表插入1[工作结点指向index]
void insert2_two_way_list(node *&head,int index,int val);  // 双向链表插入2[工作结点指向index-1]
void insert3_two_way_list(node *&head,int index,int val);  // 双向链表插入3[工作结点指向index+1]
void delete1_two_way_list(node *&head,int index);  // 双向链表删除1[工作结点指向index]
void delete2_two_way_list(node *&head,int index);  // 双向链表删除2[工作结点指向index-1]
void delete3_two_way_list(node *&head,int index);  // 双向链表删除3[工作结点指向index+1]
void list_print(node *list);  // 打印函数
void list_free(node *&list);  // 销毁链表

#endif