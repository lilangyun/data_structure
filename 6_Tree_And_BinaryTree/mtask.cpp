#include<iostream>
#include<math.h>
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
    if(it!=endchar){  //如果不等于空格
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
int calculate_leafnode(BiTree&T,int *cnt){  //注意这里用指针传递
    if(T!=NULL){
        if(T->lchild==NULL&&T->rchild==NULL){
            *cnt=*cnt+1;
        }
        else if(T->lchild!=NULL&&T->rchild==NULL){
            calculate_leafnode(T->lchild,cnt);
        }
        else if(T->lchild==NULL&&T->rchild!=NULL){
            calculate_leafnode(T->rchild,cnt);
        }
        else{
            calculate_leafnode(T->lchild,cnt);
            calculate_leafnode(T->rchild,cnt);
        }
    }
    return *cnt;
}

int depth_bitnode(BiTree&T,int depth){
    // 找到叶子结点
    // 肯定需要维护两个分支的最大值
    if(T!=NULL){
        if(T->lchild==NULL&&T->rchild==NULL){
            return depth;
        }
        else if(T->lchild!=NULL&&T->rchild!=NULL){
            depth++;  //说明还有下一层次
            return max(depth_bitnode(T->lchild,depth),depth_bitnode(T->rchild,depth));
        }
        else if(T->lchild!=NULL&&T->rchild==NULL){
            depth++;
            return depth_bitnode(T->lchild,depth);
        }
        else{
            depth++;
            return depth_bitnode(T->rchild,depth);
        }
    }
    cout<<"The tree is NULL  -----depth-bitnode"<<endl;
    return -1;  //我们尽量不去把空结点传入
}

void destroy_tree(BiTree&T){
    if(T!=NULL){
        destroy_tree(T->lchild);
        destroy_tree(T->rchild);
        delete[] T;
    }
}

int main(){
    BiTree T=NULL;
    creatBiTree(T);
    print_inorder(T);
    int *cnt=new int;
    *cnt=0;
    cout<<endl;
    cout<<calculate_leafnode(T,cnt)<<endl;
    cout<<depth_bitnode(T,1)<<endl;
    delete cnt;
    destroy_tree(T);
    return 0;
}