#include <iostream>
using namespace std;

typedef int ElemType;
const int MAX_SIZE = 50;
typedef struct {
    ElemType data[MAX_SIZE];
    int top;
} SqStack;

void initStack(SqStack& S) {
    S.top = -1;
}

bool isEmpty(const SqStack& S) {
    return (S.top == -1);
}

bool push(SqStack& S, ElemType elem) {
    if (S.top == MAX_SIZE - 1) {
        return false;
    }
    S.data[++S.top] = elem;
    return true;
}

/**
 * 获取栈顶元素
 */
bool peek(const SqStack& S, ElemType& topElem) {
    if (isEmpty(S)) {
        return false;
    }
    topElem = S.data[S.top];
    return true;
}

bool pop(SqStack& S, ElemType& elem) {
    if (isEmpty(S)) {
        return false;
    }
    elem = S.data[S.top--];
    return true;
}

ostream& operator<<(ostream& out, SqStack S) {
    ElemType elem;
    while (!isEmpty(S)) {
        out << S.data[S.top] << " ";
        pop(S, elem);
    }
    return out;
}

int main() {
    SqStack S;
    ElemType topElem;
    initStack(S);

    push(S, 3);
    push(S, 4);
    push(S, 5);
    cout << S << endl;

    if (peek(S, topElem)) {
        cout << "The top element is " << topElem << endl;
    }

    ElemType popElem;
    while (!isEmpty(S)) {
        pop(S, popElem);
        cout << S << endl;
    }
    
    return 0;
}
