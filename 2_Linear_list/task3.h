/*
* 必做任务3,头文件
*/

typedef struct node{
    int data;
    node *next;
}ndoe;  //单链表

void init_from_end(node *&list, int val);  //尾插法创建链表
void list_print(node *list);  //打印函数
void list_reverse(node *&list);  //reverse算法
void list_free(node *&list);  //销毁链表