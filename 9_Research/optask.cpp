/*
*  选做任务·源代码
*/
#include<iostream>
using namespace std;

#define ELEMTYPE int
#define STATUS int

typedef struct BST{
    ELEMTYPE data;
    struct BST *lchild, *rchild;
}BiTNode, *BiTree;   // 二叉排序树

STATUS Search_BST(BiTree T, ELEMTYPE key, BiTree f,BiTree &p){
    // T指向当前子树;f指向T的双亲结点;p为返回参数-指向访问的最后一个结点

    if(!T){
        p = f;
        return false;
    }
    if(T->data == key){
        p = T;
        return true;
    }
    if(T->data < key){
        return Search_BST(T->rchild, key, T, p);
    }
    if(T->data > key){
        return Search_BST(T->lchild, key, T, p);
    }
}

STATUS Insert_BST(BiTree &T, ELEMTYPE key){
    BiTree p;
    if(!Search_BST(T, key, NULL, p)){
        BiTree s = new BiTNode;
        s->data = key;
        s->lchild = s->rchild = NULL;
        if(!p){
            T = s;
        }
        else if(p->data < key){
            p->rchild = s;
        }
        else if(p->data > key){
            p->lchild = s;
        }
        return true;
    }
    return false;
}

// 创建二叉排序树
void Create(BiTree &T, int n){
    ELEMTYPE data;
    cout<<"请输入数据"<<endl;
    for(int i = 0; i < n; i++){
        cin>>data;
        Insert_BST(T, data);
    }
}

int main(){
    BiTree T = NULL;
    int n;
    cout<<"请输入该查找表有多少数字元素"<<endl;
    cin>>n;
    Create(T, n);
    int tmp;
    cout<<"请输入待查找元素"<<endl;
    cin>>tmp;
    BiTree p;
    if(Search_BST(T, tmp, NULL, p)){
        if(p->lchild && p->rchild)
            printf("%d 的左右子分别为：%d, %d\n", tmp, p->lchild->data, p->rchild->data);
        else if(p->lchild)
            printf("%d 无右子，它的左子为：%d\n", tmp, p->lchild->data);
        else if(p->rchild)
            printf("%d 无左子，它的右子为：%d\n", tmp, p->rchild->data);
        else
            printf("%d 是一个叶子结点\n");
    }
    else{
        cout<<"没找到"<<endl;
    }
    return 0;
}