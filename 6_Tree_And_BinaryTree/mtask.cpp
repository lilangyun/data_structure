#include<iostream>
using namespace std;

#define elemtype char  //还可以是char类型,string类等
#define endnum -1
#define endchar '0'

typedef struct BiTNode{
    elemtype data;
    BiTNode *lchild,*rchild;
}BiTNode,*BiTree;

// 按先序序列创建二叉树
void creatBiTree(BiTree&T){
    T=new BiTNode;
    T->lchild=NULL;
    T->rchild=NULL;
    // cout<<"Welcome to establish your own Binary Tree!"<<endl;
    // cout<<"Please input your elemnet by preroot order :"<<endl;
    elemtype it;
    cin>>it;
    if(it!=endchar){  //这种方式需要输入大量的endchar，如果数据量大的话会很复杂
        T->data=it;
        creatBiTree(T->lchild);
        creatBiTree(T->rchild);
    }
    else{
        free(T);
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
int calculate_leafnode(){

}

int depth_bitnode(){

}



int main(){
    BiTree T=NULL;
    creatBiTree(T);
    print_postorder(T);
    return 0;
}