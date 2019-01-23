#include <stdio.h>

#define uchar unsigned char
#define uint unsigned int

// 节点结构体
typedef struct {
    uint id;
    SingleLinkedNode *next;
} SingleLinkedNode;

// 链表结构体
typedef struct {
    uint length;
    SingleLinkedNode *head;
} SingleLinkedList;

// 创建链表
SingleLinkedList * createSingleLinkedlist () {
    SingleLinkedList linkedlist = { 0, NULL };
    return &linkedlist;
};

// 插入 node 到链表中的指定位置
SingleLinkedList * insertNodeToSingleLinkedlist (SingleLinkedList * list, SingleLinkedNode * node, uint pos) {
    if (!list || !node) {
        return NULL;
    }

    uint cur = 0;
    uint listLen = list->length;
    SingleLinkedNode *p = list->head;

    // 修正插入位置：pos
    if (pos > listLen) {
        pos = listLen;
    }

    // 如果没有一个 node，则直接插入第一个位置
    if (!p || listLen == 0) {
        list->head = node;
        return list;
    }

    // 移动指针位置
    while (p->next && cur < pos-1) {
        p = p->next;
        ++cur;
    }

    if (pos == listLen) {
        // 如果要插入最后一个位置
        p->next = node;
    } else {
        // 如果是要插入到中间
        node->next = p->next;
        p->next = node;
    }

    // 链表长度 + 1 
    list->length += 1;
    return list;
}

// 删除链表中指定位置的节点
SingleLinkedList * deleteNodeFromLinkedlist (SingleLinkedList * list, uint pos) {
    if (!list || !list->head) {
        return NULL;
    }

    uint cur = 0;
    uint listLen = list->length;
    SingleLinkedNode *p = list->head;
    SingleLinkedNode *deleted = NULL;

    // 修正 pos
    if (pos > listLen) {
        pos = listLen;
    }

    // 移动指针位置
    while (p->next && cur < pos-1) {
        p = p->next;
        ++cur;
    }

    if (pos == 0) {
        list->head = p->next;
        p->next = NULL; 
        p = NULL;
    } else {
        p->next = p->next->next;
        
    }
    
}

int main () {

}


