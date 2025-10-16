#define datatype int

typedef struct node{
    datatype data;
    node *next;
}node;

// 注：这里的打印是带表头结点的打印和销毁函数
// 打印
void list_print(node *);
// 销毁链表
void list_free(node *&);