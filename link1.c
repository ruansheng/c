//
// Created by ruansheng on 16/12/28.
//

#include <stdio.h>
#include <stdlib.h>

struct Node {
    char *key;
    int val;
    struct Node *next;
};

struct Node *initLinkList();
void insertLinkList(struct Node *link, char key[], int val);
void displayLinkList(struct Node *link);
void freeLinkList(struct Node *link);

struct Node *initLinkList() {
    struct Node *link = (struct Node *)malloc(sizeof(struct Node));
    if(NULL == link) {
        return NULL;
    }
    link->next = NULL;
    printf("%p\n", link);
    return link;
}

void displayLinkList(struct Node *link) {
    struct Node *tmp = link->next;
    printf("display start \n");
    while(NULL != tmp) {
        printf("%d \n", tmp->val);
        tmp = tmp->next;
    }
    printf("display end \n\n");
}

void insertLinkList(struct Node *link, char key[], int val) {
    struct Node *tmp = link;
    while(NULL != tmp->next) {
        tmp = tmp->next;
    }

    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    if(NULL == node) {
        return;
    }
    node->key = key;
    node->val = val;
    node->next = NULL;
    tmp->next = node;
}

void freeLinkList(struct Node *link) {
    struct Node *tmp = link->next;
    struct Node *pnode;
    while(NULL != tmp) {
        pnode = tmp;
        tmp = tmp->next;
        free(pnode);
    }

    free(link);
}

int main() {
    struct Node * node;
    printf("%p\n", node);
    // 初始化头结点
    node = initLinkList();
    if(NULL == node) {
        exit(0);
    }
    printf("%p\n", node);

    // 遍历链表
    displayLinkList(node);

    // 插入结点
    insertLinkList(node, "a", 10);
    insertLinkList(node, "b", 20);
    insertLinkList(node, "c", 30);

    // 遍历链表
    displayLinkList(node);

    // 释放内存
    freeLinkList(node);

    // 遍历链表
    //displayLinkList(node);

    return 0;
}