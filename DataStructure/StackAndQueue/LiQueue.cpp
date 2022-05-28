#include <iostream>
using namespace std;

typedef int ElemType;
typedef struct LiNode {
    ElemType data;
    struct LiNode* next;
} LiNode;

typedef struct {
    LiNode* front, * rear;
} LinkQueue;

void initQueue(LinkQueue& Q) {
    Q.front = (LiNode*)malloc(sizeof(LiNode));
    Q.front->next = nullptr;
    Q.rear = Q.front;
}

bool enqueue(LinkQueue& Q, ElemType elem) {
    LiNode* newNode = new LiNode();
    if (newNode == nullptr) {
        return false;
    }
    newNode->data = elem;
    newNode->next = nullptr;
    Q.rear->next = newNode;
    Q.rear = newNode;
    return true;
}

bool isEmpty(const LinkQueue& Q) {
    return Q.front == Q.rear;
}

bool dequeue(LinkQueue& Q, ElemType& elem) {
    if (isEmpty(Q)) {
        return false;
    }
    LiNode* trash = Q.front->next;
    elem = trash->data;
    Q.front->next = trash->next;
    if (Q.rear == trash) {
        Q.rear = Q.front;
    }
    delete trash;
    return true;
}


bool getFrontElem(const LinkQueue& Q, ElemType& elem) {
    if (isEmpty(Q)) {
        return true;
    }
    elem = Q.front->next->data;
    return true;
}

ostream& operator<<(ostream& out, LinkQueue Q) {
    ElemType elem;
    while (!isEmpty(Q)) {
        Q.front = Q.front->next;
        cout << Q.front->data << " ";
    }
    return out;
}

int main() {
    LinkQueue Q;
    initQueue(Q);
    ElemType elem;

    enqueue(Q, 3);
    cout << Q << endl;
    enqueue(Q, 4);
    cout << Q << endl;
    enqueue(Q, 5);
    cout << Q << endl;

    return 0;
}
