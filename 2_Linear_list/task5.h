/*
* 必做任务5,头文件
*/
#ifndef TASK5_H
#define TASK5_H
#define zerodegree 1e-3 //判断浮点数是否为0

typedef struct term{
    float coef; //系数
    int expn; //指数
    term *next; //书中竟然没有next,这使我对它的参考价值低看了
}term;  // 有序链表

int cmp(int e1,int e2);  // 指数比较
term *init_polyn();  //初始化一个有序链表
void creat_polyn(term *&head,float x,int y);  // 有序创建链表
void list_free(term *&list);  // 销毁链表
void add_polyn(term *&a,term *&b);  //多项式的加法
void sub_polyn(term *&a,term *&b);  //多项式的减法
void multi_polyn(term *&a,term *&b);  //多项式的乘法
void print_polyn(term *&head);  //打印链表

#endif