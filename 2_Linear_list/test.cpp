/*
* 测试文件,用于智慧树算法设计题
*/
#include<iostream>
using namespace std;

void reverse(Queue &Q){
    Stack S;int d;  //默认数据类型为int
    while(!isQueueEmpty(Q)){
        getFront(Q,d);
        deQueue(Q);
        push(S,d);  //依次将队列Q中元素放入栈S中
    }
    while(!isStackEmpty(S)){
        getTop(S,d);
        pop(S);
        enQueue(Q,d);
    }
}