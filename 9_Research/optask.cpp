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
    cout<<"Please input the elements:"<<endl;
    for(int i = 0; i < n; i++){
        cin>>data;
        Insert_BST(T, data);
    }
}

int main(){
    BiTree T = NULL;
    int n;
    cout<<"Please input how many elements?"<<endl;
    cin>>n;
    Create(T, n);
    int tmp;
    cout<<"Please input the element you want to find:"<<endl;
    cin>>tmp;
    BiTree p;
    if(Search_BST(T, tmp, NULL, p)){
        if(p->lchild && p->rchild)
            printf("The leftchild and rightchild of the element %d are: %d, %d\n", tmp, p->lchild->data, p->rchild->data);
        else if(p->lchild)
            printf("The element %d doesn't have rightchild, it's leftchild is: %d\n", tmp, p->lchild->data);
        else if(p->rchild)
            printf("The element %d doesn't have leftchild, it's rightchild is: %d\n", tmp, p->rchild->data);
        else
            printf("The element %d is a leafnode.\n", tmp);
    }
    else{
        cout<<"I can't find it."<<endl;
    }
    return 0;
}