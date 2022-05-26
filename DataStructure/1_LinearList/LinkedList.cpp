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

int main() {
    LinkedList L; // 链表头
    // createList1(L);
    createList2(L);
    printList(L);
    return 0;
}
