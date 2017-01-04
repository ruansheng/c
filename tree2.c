#include<stdio.h>
#include<stdlib.h>

typedef int DataType;
typedef struct Node {
    DataType data;
    struct Node *LChild;
    struct Node *RChild;
}BitNode,*BitTree;

//用扩展先序遍历序列创建二叉树，如果是#当前树根置为空，否则申请一个新节点//
void CreatBiTree(BitTree *bt) {
    char ch;
    ch=getchar();
    if(ch=='.') {
        *bt = NULL;
    } else {
        *bt=(BitTree)malloc(sizeof(BitNode));
        (*bt)->data=ch;
        CreatBiTree(&((*bt)->LChild));
        CreatBiTree(&((*bt)->RChild));
    }
}

//访问根节点
void Visit(char ch){
    printf("%c  ",ch);
}

void  PreOrder(BitTree root) {
    if (root!=NULL) {
        Visit(root ->data);
        PreOrder(root ->LChild);
        PreOrder(root ->RChild);
    }
}

void  InOrder(BitTree root) {
    if (root!=NULL) {
        InOrder(root ->LChild);
        Visit(root ->data);
        InOrder(root ->RChild);
    }
}

void  PostOrder(BitTree root) {
    if(root!=NULL) {
        PostOrder(root ->LChild);
        PostOrder(root ->RChild);
        Visit(root ->data);
    }
}

//后序遍历求二叉树的高度递归算法//
int PostTreeDepth(BitTree bt) {
    int hl,hr,max;
    if(bt!=NULL) {
        hl=PostTreeDepth(bt->LChild);  //求左子树的深度
        hr=PostTreeDepth(bt->RChild);  //求右子树的深度
        max=hl>hr?hl:hr;              //得到左、右子树深度较大者
        return(max+1);               //返回树的深度
    } else {
        return(0);    //如果是空树，则返回0
    }
}

//按竖向树状打印的二叉树 //
void PrintTree(BitTree Boot,int nLayer) {
    int i;
    if(Boot==NULL) return;
    PrintTree(Boot->RChild,nLayer+1);
    for(i=0;i<nLayer;i++) {
        printf("  ");
    }
    printf("%c\n",Boot->data);
    PrintTree(Boot->LChild,nLayer+1);
}

int main() {
    BitTree T;
    int h;
    int layer;
    int treeleaf;
    layer=0;
    printf("请输入二叉树中的元素(以扩展先序遍历序列输入,其中.代表空子树):\n");
    CreatBiTree(&T);
    printf("先序遍历序列为:");
    PreOrder(T);
    printf("\n中序遍历序列为:");
    InOrder(T);
    printf("\n后序遍历序列为:");
    PostOrder(T);
    h=PostTreeDepth(T);
    printf("此二叉树的深度为:%d\n", h);
    printf("此二叉树的横向显示为：\n");
    PrintTree(T,layer);
    return 0;
}