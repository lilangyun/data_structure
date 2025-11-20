/*
* 必做任务·源代码
*/
#include<iostream>
#include<algorithm>
#include"mtask.h"
using namespace std;

int main(){
    BiTree T=NULL;
    creatBiTree(T);
    print_inorder(T);
    cout<<endl;
    cout<<calculate_leafnode(T)<<endl;
    cout<<depth_bitnode(T)<<endl;
    destroy_tree(T);
    return 0;
}

// 按先序序列创建二叉树
void creatBiTree(BiTree&T){
    ELEMTYPE it;
    cin>>it;
    if(it!=ENDCHAR){
        T=new BiTNode;
        T->lchild=NULL;
        T->rchild=NULL;
        T->data=it;
        creatBiTree(T->lchild);
        creatBiTree(T->rchild);
    }
    else{
        T=NULL;
    }
}

// 打印先序遍历结果
void print_preorder(BiTree&T){
    if(T!=NULL){
        cout<<T->data<<" ";
        print_preorder(T->lchild);
        print_preorder(T->rchild);
    }
}

// 打印中序遍历结果
void print_inorder(BiTree&T){
    if(T!=NULL){
        print_inorder(T->lchild);
        cout<<T->data<<" ";
        print_inorder(T->rchild);
    }
}

// 打印后序遍历结果
void print_postorder(BiTree&T){
    if(T!=NULL){
        print_postorder(T->lchild);
        print_postorder(T->rchild);
        cout<<T->data<<" ";
    }
}


// 计算叶子结点数
int calculate_leafnode(BiTree&T){
    if(T!=NULL){
        if(T->lchild==NULL&&T->rchild==NULL){
            return 1;
        }
        return calculate_leafnode(T->lchild)+calculate_leafnode(T->rchild);
    }
    return 0;
}

int depth_bitnode(BiTree&T){
    // 找到叶子结点
    // 肯定需要维护两个分支的最大值
    if(T!=NULL){
        if(T->lchild==NULL&&T->rchild==NULL){
            return 1;
        }
        else{
            return 1+max(depth_bitnode(T->lchild),depth_bitnode(T->rchild));
        }
    }
    return 0;
}

void destroy_tree(BiTree&T){
    if(T!=NULL){
        destroy_tree(T->lchild);
        destroy_tree(T->rchild);
        delete T;
        T=NULL;
    }
}