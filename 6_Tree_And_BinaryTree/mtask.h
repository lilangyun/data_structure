/*
* 必做任务·头文件
*/

#define ELEMTYPE int  //元素数据类型：{int, char, string, ...}
#define ENDNUM -1
#define ENDCHAR '0'

typedef struct BiTNode{
    ELEMTYPE data;
    BiTNode *lchild,*rchild;
}BiTNode,*BiTree;  // 二叉树节点

// 按先序序列创建二叉树
void creatBiTree(BiTree&T);

// 打印先序遍历结果
void print_preorder(BiTree&T);

// 打印中序遍历结果
void print_inorder(BiTree&T);

// 打印后序遍历结果
void print_postorder(BiTree&T);

// 计算叶子结点数
int calculate_leafnode(BiTree&T);

// 计算树的深度
int depth_bitnode(BiTree&T);

// 释放树
void destroy_tree(BiTree&T);