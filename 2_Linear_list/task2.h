/*
* 必做任务2,头文件
*/
#ifndef TASK2_H
#define TASK2_H

#define datatype int

typedef struct node{
    datatype data;
    node *next;
}node;  // 单链表

void init_from_head(node *head, int val);  // 头插法
void init_from_end(node *head, int val);  // 尾插法
void insert_elem(node *head, int val, int index);  // 插入元素：在位置 index 处插入（0 表示第一个数据节点）
void delete_elem(node *head,int index);  // 删除元素
int find_by_val(node *head, datatype val);  // 按值查找
datatype find_by_index(node *head,int index);  // 按下标查找
void list_print(node *head);  // 打印
void list_free(node *&list);  // 销毁链表

#endif