#include <iostream>
using namespace std;

typedef int ElemType;
typedef struct LNode {
    ElemType data;
    struct LNode* next;
} LNode, * LinkedList;

/**
 * 头插法新建链表
 **/
LinkedList createList1(LinkedList& L) {
    L = new LNode(); // 带头结点的链表
    L->next = nullptr;

    LNode* newNode;
    int elem;
    cin >> elem;
    while (elem != -1) {
        newNode = new LNode();
        newNode->data = elem;
        newNode->next = L->next;
        L->next = newNode;
        cin >> elem;
    }
    return L;
}

/**
 * 尾插法新建链表
 **/
LinkedList createList2(LinkedList& L) {
    L = new LNode(); // 带头结点的链表
    L->next = nullptr;

    LinkedList tail = L;
    LNode* newNode;
    int elem;
    cin >> elem;
    while(elem != -1) {
        newNode = new LNode();
        newNode->data = elem;
        tail->next = newNode;
        tail = newNode; // 指向新的表尾结点
        cin >> elem;
    }
    tail->next = nullptr; // 尾结点的next赋值为nullptr
    return L;
}

void printList(LinkedList L) {
    L = L->next;
    while (L != nullptr) {
        cout << L->data << " ";
        L = L->next;
    }
    cout << endl;
}

/**
 * 按序号查找结点值
 **/
LNode* findKth(LinkedList L, int pos) {
    LNode* p = L->next;
    if (pos == 0) {
        return L;
    } 
    if (pos < 0) {
        return nullptr;
    }
    int i = 1;
    while (p != nullptr && i < pos) {
        p = p->next;
        i++;
    }
    return p;
}

/**
 * 按值查找
 **/
LNode* locateElem(LinkedList L, ElemType elem) {
    LNode* p = L->next;
    while (p != nullptr && elem != p->data) {
        p = p->next;
    }
    return p;
}

bool insertElem(LinkedList L, int pos, ElemType elem) {
    LinkedList p = findKth(L, pos - 1); // 获取前一个结点的地址
    if (p == nullptr) {
        return false;
    }
    LNode* newNode = new LNode();
    // 或者写为
    // LNode* newNode = (LNode*)malloc(sizeof(LNode));
    newNode->data = elem;
    newNode->next = p->next;
    p->next = newNode;
    return true;
}

bool deleteKth(LinkedList L, int pos) {
    LinkedList p = findKth(L, pos - 1); // 获取前一个结点的地址
    if (p == nullptr) {
        return false;
    }
    LNode* trash = p->next;
    p->next = trash->next;
    delete trash;
    trash = nullptr; // 避免野指针
    // 或者写为
    // free(trash);
    // trash = NULL;
    return true;
}

int main() {
    LinkedList L; // 链表头
    // createList1(L);
    createList2(L);
    printList(L);
    
    int k = 3;
    cout << findKth(L, k)->data << endl;

    int number = 3;
    LNode* search = locateElem(L, number);
    if (search != nullptr) {
        cout << "find " << search->data << " successfully" << endl;
    } else {
        cout << "failed to find " << number << endl;
    }

    insertElem(L, 5, 50);
    printList(L);

    deleteKth(L, 1);
    printList(L);

    deleteKth(L, 1);
    printList(L);

    return 0;
}
