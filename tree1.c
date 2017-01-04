#include <stdio.h>
#include <stdlib.h>

//二叉树的的
#define MAXSIZE 100 //二叉树中最多的结点数　
typedef char TElemType;
typedef struct BiTNode{
    TElemType data;
    struct BiTNode *lchild,*rchild;
}BiTNode,*BiTree;

//定义函数指针
typedef void(* Visit)(BiTree);

//二叉树的初始化
void Init_BiTree(BiTree *T){
    *T = NULL;
}

//判断二叉树是否为空,返回1
int IsEmpty_BiTree(BiTree *T){
    return *T == NULL;
}

//创建二叉树
void Create_BiTree(BiTree *T) {
    char ch;
    //ch = getchar();
    scanf("%c", &ch);
    //当输入的是"#"时，认为该子树为空
    if (ch == '#'){
        *T = NULL;
        //创建树结点
    }else{
        *T = (BiTree)malloc(sizeof(BiTNode));
        (*T)->data = ch; //生成树结点
        //生成左子树
        Create_BiTree(&(*T)->lchild);
        //生成右子树
        Create_BiTree(&(*T)->rchild);
    }
}

//输出结点的值
void Print_BiTreeNode(BiTree T){
    printf("%c\t",T->data);

}

//先序遍历二叉树
void PreOrder_BiTree(BiTree T,Visit visit){
    if(!IsEmpty_BiTree(&T)){
        visit(T);
        PreOrder_BiTree(T->lchild,visit);
        PreOrder_BiTree(T->rchild,visit);
    }
}
//中序遍历二叉树
void InOrder_BiTree(BiTree T,Visit visit){
    if(!IsEmpty_BiTree(&T)){
        InOrder_BiTree(T->lchild,visit);
        visit(T);
        InOrder_BiTree(T->rchild,visit);
    }
}

//后序遍历二叉树　
void PostOrder_BiTree(BiTree T,Visit visit){
    if(!IsEmpty_BiTree(&T)){
        PostOrder_BiTree(T->lchild,visit);
        PostOrder_BiTree(T->rchild,visit);
        visit(T);
    }
}

//层次遍历二叉树　
void LevelOrder_BiTree(BiTree T,Visit visit){
    //用一个队列保存结点信息,这里的队列采用的是顺序队列中的数组实现
    int front = 0;
    int rear = 0;
    BiTree BiQueue[MAXSIZE];
    BiTree tempNode;
    if(!IsEmpty_BiTree(&T)){
        //将根结点加入到队列中　
        BiQueue[rear++] = T;

        while(front != rear){
            //取出队头元素，并使队头指针向后移动一位　
            tempNode = BiQueue[front++];
            //判断左右子树是否为空,若为空，则加入队列　
            if(!IsEmpty_BiTree(&(tempNode->lchild)))
                BiQueue[rear++] = tempNode->lchild;

            if(!IsEmpty_BiTree(&(tempNode->rchild)))
                BiQueue[rear++] = tempNode->rchild;

            //输出队头结点元素　
            //Vist_BiTreeNode(tempNode->data);
            visit(tempNode);
        }
    }
}

int main(){
    BiTree T;
    //将二叉树初始为一个空的二叉树
    Init_BiTree(&T);
    //创建二叉树
    Create_BiTree(&T);
    //先序遍历
    printf("\n先序遍历结果：");
    PreOrder_BiTree(T,Print_BiTreeNode);
    //中序遍历二叉树
    printf("\n中序遍历结果：");
    InOrder_BiTree(T,Print_BiTreeNode);
    //后序遍历二叉树　
    printf("\n后序遍历结果：");
    PostOrder_BiTree(T,Print_BiTreeNode);
    //层次遍历二叉树　
    printf("\n层次遍历结果：");
    LevelOrder_BiTree(T,Print_BiTreeNode);
    return 0;
}


/*
 1247###5#8##36###

先序遍历结果：1        2       4       7       5       8       3       6
中序遍历结果：7        4       2       5       8       1       6       3
后序遍历结果：7        4       8       5       2       6       3       1
层次遍历结果：1        2       3       4       5       6       7       8
 */