/*
* 必做任务1,头文件
*/
#ifndef TASK1_H
#define TASK1_H

#define capacity 100
#define datatype int

typedef struct{
    datatype *head;
    int len;
}SqList;  // 顺序表

void init_SqList(SqList &sqlist);  // 创建顺序表
void insert_SqList(SqList&sqlist,int index,datatype data);  // 在下标为index元素前面插入元素
void delete_SqList(SqList&sqlist,datatype index);  // 删除下标为index的元素
int find_by_val(SqList&sqlist,datatype val);  // 按值查找顺序表中的元素，返回索引
datatype find_by_index(SqList&sqlist,int index);  // 按索引查找元素，返回值
void print_elem(SqList&sqlist);  // 输出顺序表中的元素
void get_average(SqList&sqlist);  // 求平均值并插入

#endif