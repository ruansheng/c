#include <stdio.h>
#include <stdlib.h>

/*二叉链表存储结构*/
typedef struct Node {
    char data;
    struct Node *lchild, *rchild;
}BiTree;

/*创建二叉表--递归算法*/
BiTree * createBiTree(void){
    char ch;
    BiTree *T;
    
    ch = getchar();
    if(ch == '#') {
        return NULL;        /*递归结束*/
    } else {
        T = (BiTree *)malloc(sizeof(BiTree));
        T->data = ch;                    /*数据域赋值*/
        T->lchild = createBiTree();        /*递归调用*/
        T->rchild = createBiTree();
        return T;    
    }
}

/*前序遍历二叉树--递归算法*/
void preOrder(BiTree *T){
    if(T){
        printf("%c",T->data);        /*访问根节点*/
        preOrder(T->lchild);        /*前序遍历左子树*/
        preOrder(T->rchild);        /*前序遍历右子树*/
    }
}

int main(void){
    BiTree *root;
    printf("\n输入结点的前序序列创建二叉树（ABC##FG###D#E##）#表示空：\n > ");
    root = createBiTree();
    printf("\n前序遍历二叉树--递归：\n");
    preOrder(root);    
    printf("\n");
}

