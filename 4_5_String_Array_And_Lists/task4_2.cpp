/*
* 必做题4(2)·源代码
*/
#include<iostream>
#include "task4_2.h"
using namespace std;

int main(){
    TsMatrix *M=new TsMatrix;
    create_TsMatrix(M);
    printTsMatrix(M);
    TsMatrix *T=transpose_TsMatrix(M);
    cout<<"--------------The original matrix is transposed---------------"<<endl;
    printTsMatrix(T);
    // 十字链表版本
    cout<<"--------------The crosslist version---------------"<<endl;
    CrossList *R=new CrossList;
    creatCrossList(R);
    printCrossLink(R);
    cout<<"--------------The original matrix is transposed---------------"<<endl;
    CrossList*K=transpose_CrossList(R);
    printCrossLink(K);
    return 0;
}

void create_TsMatrix(TsMatrix*&M){
    int mu,nu,tu;
    cout<<"Please input your matrix's row,column and non-zero number:"<<endl;
    cin>>mu>>nu>>tu;
    M->mu=mu;M->nu=nu;M->tu=tu;
    cout<<"OK! Now,input your elements by row-major sequence:"<<endl;
    for(int t=1;t<=tu;t++){
        // 这里注意要以行为主序进行输入
        int i,j,val;
        cin>>i>>j>>val;
        M->data[t].i=i;M->data[t].j=j;M->data[t].val=val;
    }
    cout<<"You have created a TsMatrix M."<<endl;
}

TsMatrix* transpose_TsMatrix(TsMatrix*M){
    TsMatrix *T=new TsMatrix;
    T->nu=M->mu;T->mu=M->nu;T->tu=M->tu;
    int e=1;
    for(int y=1;y<=M->nu;y++){
        for(int t=1;t<=M->tu;t++){
            if(M->data[t].j==y){
                T->data[e].i=M->data[t].j;
                T->data[e].j=M->data[t].i;
                T->data[e].val=M->data[t].val;
                e++;
            }
        }
    }
    return T;  //教材上介绍的最朴素的一种算法
}

void printTsMatrix(TsMatrix *M){
    int mu=M->mu,nu=M->nu,tu=M->tu;
    cout<<"The matrix's non-zero elements are followed by:"<<endl;
    for(int t=1;t<=tu;t++){
        cout<<M->data[t].i<<"  "<<M->data[t].j<<"  "<<M->data[t].val<<endl;
    }
}

void creatCrossList(CrossList*M){
    cout<<"Please create your array elements!"<<endl;
    int mu,nu,tu;
    cout<<"Input your mu,nu and tu:"<<endl;
    cin>>mu>>nu>>tu;
    M->mu=mu;M->nu=mu;M->tu=tu;
    if(!(M->rhead=(OLink*)malloc((mu+1)*sizeof(OLink)))||!(M->chead=(OLink*)malloc((nu+1)*sizeof(OLink)))){
        cout<<"The OLink can not be created!-----"<<endl;
        exit(0);
    }
    for(int i=0;i<=mu;i++){
        M->rhead[i]=NULL;
    }
    for(int i=0;i<=nu;i++){
        M->chead[i]=NULL;
    }
    int i,j,val;
    cout<<"Next,input your i,j and val:"<<endl;
    int cnt=0;
    while(cnt<tu){
        cin>>i>>j>>val;
        // 这里还可以添加对i,j,val的进一步有效检验
        OLNode *temp;
        if(!(temp=(OLNode*)malloc(sizeof(OLNode)))){
            cout<<"The OLNode can not be malloc!-----"<<endl;
            exit(0);
        }
        temp->down=temp->right=NULL;
        temp->i=i;temp->j=j;temp->val=val;
        // 这里分类讨论
        if(M->rhead[i]==NULL||M->rhead[i]->j>j){
            temp->right=M->rhead[i];
            M->rhead[i]=temp;
        }
        else{
            OLNode *tt=M->rhead[i];
            while(tt->right!=NULL&&tt->right->j<j){
                tt=tt->right;
            }
            temp->right=tt->right;
            tt->right=temp;
        }
        if(M->chead[j]==NULL||M->chead[j]->i>i){
            temp->down=M->chead[j];
            M->chead[j]=temp;
        }
        else{
            OLNode *tt=M->chead[j];
            while(tt->down!=NULL&&tt->down->i<i){
                tt=tt->down;
            }
            temp->down=tt->down;
            tt->down=temp;
        }
        cnt++;
    }
}

CrossList *transpose_CrossList(CrossList *M){
    CrossList *T=new CrossList;
    T->mu=M->nu;
    T->nu=M->mu;
    T->tu=M->tu;
    if(!(T->rhead=(OLink*)malloc((T->mu+1)*sizeof(OLink)))||!(T->chead=(OLink*)malloc((T->nu+1)*sizeof(OLink)))){
        cout<<"The OLink can not be created!-----"<<endl;
        exit(0);
    }
    for(int i=0;i<=T->mu;i++){
        T->rhead[i]=NULL;
    }
    for(int i=0;i<=T->nu;i++){
        T->chead[i]=NULL;
    }
    for(int i=1;i<=T->mu;i++){
        // 以列为主序遍历十字链表M
        OLNode *tmp=M->chead[i];
        OLNode *tend=T->rhead[i];  //这里维护T的最后一个非零元位置
        while(tmp!=NULL){
            OLNode *node=new OLNode;
            node->i=tmp->j;
            node->j=tmp->i;
            int j=node->j;
            node->val=tmp->val;
            node->down=node->right=NULL;
            if(tend==NULL){
                T->rhead[i]=node;
                tend=node;
            }
            else{
                tend->right=node;
                tend=node;
            }
            if(T->chead[j]==NULL||T->chead[j]->i>node->i){
                node->down=T->chead[j];
                T->chead[j]=node;
            }
            else{
                OLNode *tt=T->chead[j];
                while(tt->down!=NULL&&tt->down->i<node->i){
                    tt=tt->down;
                }
                node->down=tt->down;
                tt->down=node;
            }
            tmp=tmp->down;
        }
    }
    return T;
}

void printCrossLink(CrossList*M){
    cout<<"The crosslink is : "<<endl;
    for(int i=1;i<=M->mu;i++){
        OLNode *temp=M->rhead[i];
        while(temp!=NULL){
            cout<<i<<"  "<<temp->j<<"  "<<temp->val<<"  "<<endl;  //这里报错说明值没有输入进去
            temp=temp->right;
        }
    }
}