// 利用链表进行多项式的构建、加减、乘除
#include<iostream>
#include<math.h>
using namespace std;

#define zerodegree 1e-3 //判断浮点数是否为0

typedef struct term{
    float coef; //系数
    int expn; //指数
    term *next; //书中竟然没有next,这使我对它的参考价值低看了
}term;

// 指数比较
int cmp(int e1,int e2){
    // e1表示要插入元素,e2表示链表中元素
    if(e1>e2){
        return 1; //继续向后搜索
    }
    if(e1<e2){
        return -1; //插入这个元素之前
    }
    return 0; //系数相加,注意判断是否需要销毁
}

// 这里初始化一个有序链表
term *init_polyn(){
    term *head=new term;
    head->coef=0.0;
    head->expn=-1;
    head->next=NULL;
    return head;
}

// 有序创建链表
void creat_polyn(term *&head,float x,int y){
    // 有序链表，不仅仅是尾插头插，我们要去找到cmp==-1的位置，在其前面插入
    term *newnode=new term;
    newnode->coef=x;
    newnode->expn=y;
    newnode->next=NULL;
    term *tmp=head; //相当于有头结点
    while(tmp->next!=NULL){
        int t=cmp(y,tmp->next->expn);
        if(t<0){
            newnode->next=tmp->next;
            tmp->next=newnode;
            return ;
        }
        if(t==0){
            tmp->next->coef+=newnode->coef;
            if(fabs(tmp->next->coef)<zerodegree){
                // 考虑销毁改结点
                // 我们之后写一个函数
                term *q=tmp->next;
                tmp->next=q->next;
                delete q;
            }
            delete newnode; 
            return ;
        }
        tmp=tmp->next;
    }
    // 如果未满足t<=0条件,那么只能在末尾插入，说明该节点指数已经最大了
    tmp->next=newnode;
}

// 销毁链表
void list_free(term *&list){
     // 释放链表
    term *cur=list;
    while(cur!=NULL){
        term *p=cur;
        cur=p->next;
        delete p;
    }
}

// 实现多项式的加减
// 其实思路与创建类似,并不困难
void add_polyn(term *&a,term *&b){
    // 我们默认多项式a为结果多项式
    term *tmp1=a;
    term *tmp2=b;
    // 在最初，tmp1和2均指向头结点,故while循环需要->next
    while(tmp1->next!=NULL&&tmp2->next!=NULL){
        term *newnode=new term;
        newnode->coef=tmp2->next->coef;
        newnode->expn=tmp2->next->expn;
        // 复制b->next结点
        int t=cmp(tmp2->next->expn,tmp1->next->expn);
        // 请容许我先考虑最简单的情况
        if(t==0){
            tmp1->next->coef+=tmp2->next->coef;
            if(fabs(tmp1->next->coef)<zerodegree){
                term *p=tmp1->next;
                tmp1->next=p->next;
                delete p;
            }
            term *q=tmp2->next;
            tmp2->next=q->next;
            delete q;
            continue;
        }
        // 如果b指数小于a指数
        else if(t<0){
            // 把b写在a之前
            newnode->next=tmp1->next;
            tmp1->next=newnode;
            term *r=tmp2->next;
            tmp2->next=r->next;
            delete r;
        }
        tmp1=tmp1->next;
    }
    // 我们默认是a移动至最后一个有效位
    // 那么接下来只要将b链整体添加至a之后即可
    if(tmp2->next!=NULL){
        term *t=tmp2->next;
        tmp1->next=t;
        t=NULL;
    }
    // 至此，新链已成
    delete tmp2;
}

// 减法只需要将加法中b的->coen变为负号即可
// 如果需要，可以将两个函数合并为一个
void sub_polyn(term *&a,term *&b){
    // 我们默认多项式a为结果多项式
    term *tmp1=a;
    term *tmp2=b;
    // 在最初，tmp1和2均指向头结点,故while循环需要->next
    while(tmp1->next!=NULL&&tmp2->next!=NULL){
        term *newnode=new term;
        newnode->coef=-tmp2->next->coef;
        newnode->expn=tmp2->next->expn;
        // 复制b->next结点
        int t=cmp(tmp2->next->expn,tmp1->next->expn);
        // 请容许我先考虑最简单的情况
        if(t==0){
            tmp1->next->coef-=tmp2->next->coef;
            if(fabs(tmp1->next->coef)<zerodegree){
                term *p=tmp1->next;
                tmp1->next=p->next;
                delete p;
            }
            term *q=tmp2->next;
            tmp2->next=q->next;
            delete q;
            continue;
        }
        // 如果b指数小于a指数
        else if(t<0){
            // 把b写在a之前
            newnode->next=tmp1->next;
            tmp1->next=newnode;
            term *r=tmp2->next;
            tmp2->next=r->next;
            delete r;
        }
        tmp1=tmp1->next;
    }
    // 我们默认是a移动至最后一个有效位
    // 那么接下来只要将b链整体添加至a之后即可
    if(tmp2->next!=NULL){
        term *t=tmp2->next;
        tmp1->next=t;
        t=NULL;
    }
    delete tmp2; //满足将b完全删除的条件
    // 至此，新链已成
}

// 实现乘法，基本思路是通过逐个乘实现目的
void multi_polyn(term *&a,term *&b){
    term *ans=init_polyn();
    term *tmp1=a;
    term *tmp2=b;
    // 枚举a的各结点，依次遍历b
    while(tmp1->next!=NULL){
        float x=tmp1->next->coef;
        int y=tmp1->next->expn;
        tmp2=b;
        while(tmp2->next!=NULL){
            float g=tmp2->next->coef*x;
            int h=tmp2->next->expn+y;
            creat_polyn(ans,g,h);
            tmp2=tmp2->next;
        }
        tmp1=tmp1->next;
    }
    list_free(a);
    list_free(b);
    a=ans;
}

// 精致地打印我们构造的链表
void print_polyn(term *&head){
    if(head->next==NULL){
        printf("This is a empty polynorminal!Good bye sir!!\n");
        return ;
    }
    term *tmp=head;
    int cnt=0; //计数器
    printf("The polynorminal is :");
    while(tmp->next!=NULL){
        // 非空的默认应该都是系数非0的(我们之前在创建时已将0删去)
        if(tmp->next->next!=NULL){
            printf(" %.3fx^%d +",tmp->next->coef,tmp->next->expn);
        }
        else{
            printf(" %.3fx^%d .\n",tmp->next->coef,tmp->next->expn);
        }
        tmp=tmp->next;
    }
}

int main(){
    term *a=init_polyn();
    term *b=init_polyn();
    for(int i=2;i<=4;i+=2){
        creat_polyn(a,i,i);
    }
    print_polyn(a);
    // for(int i=1;i<=3;i++){
    //     creat_polyn(a,-i,i);
    // }
    // print_polyn(a);
    for(int i=1;i<=2;i++){
        creat_polyn(b,i,i);
    }
    print_polyn(b);

    // test
    // sub_polyn(a,b);

    // // 打印
    // print_polyn(a);
    // print_polyn(b);

    // test multiply
    multi_polyn(a,b);

    print_polyn(a);

    // 销毁多项式
    list_free(a);
    // b在加减操作中已经销毁
    return 0;
}