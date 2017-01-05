#include<stdio.h>
#include<stdlib.h>

typedef struct TreeNode {
     char data;
     struct TreeNode *lchild, *rchild;
} TreeNode, *BiTree;

/*前序创建树*/
TreeNode *createPreOrderBiTree();
/*中序创建树*/
TreeNode *createMidOrderBiTree();
/*后序创建树*/
TreeNode *createPostOrderBiTree();

/*前序遍历树*/
void preOrderDisplayBiTree(BiTree T);
/*中序遍历树*/
void midOrderDisplayBiTree(BiTree T);
/*后序遍历树*/
void postOrderDisplayBiTree(BiTree T);

TreeNode *createPreOrderBiTree() {
    char data;
    BiTree T;
    
    scanf("%c", &data);
    if(data == '#') {
       T = NULL;
    } else {
       T = (BiTree)malloc(sizeof(TreeNode));
       T->data = data;
       T->lchild = createPreOrderBiTree();
       T->rchild = createPreOrderBiTree();
    }
    return T;
}

void preOrderDisplayBiTree(BiTree T) {
    if(T) {
       printf("%c", T->data);
       preOrderDisplayBiTree(T->lchild);
       preOrderDisplayBiTree(T->rchild);
    }
}

int main() {
    BiTree T = createPreOrderBiTree();
    preOrderDisplayBiTree(T);

    return 0;
}
