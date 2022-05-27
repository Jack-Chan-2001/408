/**
 * 循环队列
 */
#include <iostream>
using namespace std;

typedef int ElemType;
const int MAX_SIZE = 6;
typedef struct {
    ElemType data[MAX_SIZE]; // 存储 MAX_SIZE-1 个元素
    int front, rear;
} SqQueue;

void initQueue(SqQueue& Q) {
    Q.front = 0;
    Q.rear = 0;
}

bool isEmpty(const SqQueue& Q) {
    return (Q.rear == Q.front);
}

bool enqueue(SqQueue& Q, ElemType elem) {
    // 判断队满
    if ((Q.rear + 1) % MAX_SIZE == Q.front) {
        return false;
    }
    // 入队
    Q.data[Q.rear] = elem;
    Q.rear = (Q.rear + 1) % MAX_SIZE;
    return true;
}

bool dequeue(SqQueue& Q, ElemType& elem) {
    if (isEmpty(Q)) {
        return false;
    }
    elem = Q.data[Q.front];
    Q.front = (Q.front + 1) % MAX_SIZE;
    return true;
}

ostream& operator<<(ostream& out, SqQueue Q) {
    while (!isEmpty(Q)) {
        out << Q.data[Q.front] << " ";
        Q.front = (Q.front + 1) % MAX_SIZE;
    }
    return out;
}
int main() {
    SqQueue Q;
    ElemType elem;

    initQueue(Q);

    while (cin >> elem) {
        enqueue(Q, elem);
        cout << Q << endl;
    }
}
