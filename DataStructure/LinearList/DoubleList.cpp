/**
 * 双向链表
 */
#include <iostream>
using namespace std;

typedef int ElemType;
typedef struct DNode {
    ElemType data;
    struct DNode* prior;
    struct DNode* next;
} DNode, * DLinkedList;

void printList(DLinkedList DL) {
    DLinkedList tail = DL->next;
    while (tail != nullptr) {
        printf("%3d", tail->data);
        tail = tail->next;
    }
    printf("\n");
}

/**
 * 头插法建立双向链表
 */
DLinkedList createList1(DLinkedList& DL) {
    DL = new DNode();
    DL->prior = nullptr;
    DL->next = nullptr;

    DNode* newNode;
    int elem;
    cin >> elem;
    while (elem != -1) {
        newNode = new DNode();
        newNode->data = elem;
        newNode->prior = DL;
        newNode->next = DL->next;
        if (DL->next != nullptr) { // 插入第一个结点时，不需要进行
            DL->next->prior = newNode;
        }
        DL->next = newNode;
        cin >> elem;
    }
    return DL;
}

/**
 * 尾插法建立双向链表
 */
DLinkedList createList2(DLinkedList& DL) {
    DL = new DNode();
    DL->next = nullptr;
    DL->prior = nullptr;

    DNode* newNode;
    DNode* tail = DL;
    int elem;
    cin >> elem;
    while (elem != -1) {
        newNode = new DNode();
        newNode->data = elem;
        newNode->prior = tail;
        tail->next = newNode;
        tail = newNode;
        cin >> elem;
    }
    tail->next = nullptr;
    return DL;
}

/**
 * 按序号查找
 */
DNode* findKth(DLinkedList DL, int pos) {
    if (pos == 0) {
        return DL;
    }
    if (pos < 0) {
        return nullptr;
    }
    int i = 1;
    DNode* p = DL->next;
    while (i < pos && p != nullptr) {
        p = p->next;
        ++i;
    }
    return p;
}

bool insertElem(DLinkedList DL, int pos, ElemType elem) {
    DNode* p = findKth(DL, pos - 1);
    if (p == nullptr) {
        return false;
    }
    DNode* newNode = new DNode();
    newNode->data = elem;
    newNode->next = p->next;
    newNode->prior = p;
    p->next->prior = newNode;
    p->next = newNode;
    return true;

}

bool deleteKth(DLinkedList DL, int pos) {
    DNode* p = findKth(DL, pos - 1);
    if (p == nullptr) {
        return false;
    }
    DNode* trash = p->next;
    trash->next->prior = p;
    p->next = trash->next;
    delete trash;
    trash = nullptr; // 注意避免野指针
    return true;
}

int main() {
    DLinkedList DL;
    // createList1(DL);
    createList2(DL);
    printList(DL);

    int k = 2;
    printf("%d\n", findKth(DL, k)->data);

    if (insertElem(DL, 2, 99)) {
        printList(DL);
    } else {
        printf("insert failed.\n");
    }

    deleteKth(DL, 4);
    printList(DL);
    return 0;
}
