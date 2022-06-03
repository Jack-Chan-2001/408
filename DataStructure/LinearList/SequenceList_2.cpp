/**
 * 线性表的顺序表实现
 * 动态分配数组
 */
#include <iostream>
using namespace std;

const int Init_Size = 10;
typedef struct {
    int* data;      // 动态分配数组
    int length;     // 线性表当前长度
    int MaxSize;    // 顺序表的最大长度
} SeqList;

void InitList(SeqList& L);
void ListIncrease(SeqList& L, const int len);
bool isEmpty(const SeqList& L);
bool isFull(const SeqList& L);
bool InsertElem(SeqList& L, const int pos, const int elem);
bool DeleteElem(SeqList& L, const int pos, int& elem);
int GetElem(const SeqList& L, const int pos);
int LocateElem(const SeqList& L, const int elem);
void DestroyList(SeqList& L);
ostream& operator<<(ostream& out, const SeqList& L);

void InitList(SeqList& L) {
    L.data = (int*)malloc(sizeof(int) * Init_Size);
    L.length = 0;
    L.MaxSize = Init_Size;
}

void ListIncrease(SeqList& L, const int len) {
    int* p = L.data;
    L.data = (int*)malloc(sizeof(int) * (len + L.MaxSize));
    L.MaxSize += len;                   // 顺序表最大长度增加 len
    for (int i = 0; i < L.length; ++i) {
        L.data[i] = p[i];               // 复制数据到新区域
    }
    free(p);                            // 释放原空间
}

bool isEmpty(const SeqList& L) {
    return L.length == 0;
}

bool isFull(const SeqList& L) {
    return L.length == L.MaxSize;
}

bool InsertElem(SeqList& L, const int pos, const int elem) {
    // 先判断合法性
    if (pos < 1 || pos > L.length + 1 || isFull(L)) {
        return false;
    }
    for (int i = L.length; i >= pos; i--) {
        L.data[i] = L.data[i - 1];
    }
    L.data[pos - 1] = elem;
    L.length++;
    return true;
}

bool DeleteElem(SeqList& L, const int pos, int& elem) {
    // 先判断合法性
    if (pos < 1 || pos > L.length || isEmpty(L)) {
        return false;
    }
    for (int i = pos; i < L.length; ++i) {
        L.data[i - 1] = L.data[i];
    }
    L.length--;
    return true;
}

int GetElem(const SeqList& L, const int pos) {
    if (pos < 1 || pos > L.length) {
        return -1;
    }
    return L.data[pos - 1];
}

int LocateElem(const SeqList& L, const int elem) {
    for (int i = 0; i < L.length; ++i) {
        if (L.data[i] == elem) {
            return i + 1;
        }
    }
    return 0;
}

ostream& operator<<(ostream& out, const SeqList& L) {
    for (int i = 0; i < L.length; ++i) {
        out << L.data[i] << " ";
    }
    return out;
}

int main() {
    SeqList L;
    InitList(L);
    ListIncrease(L, 5);

    InsertElem(L, 1, 3);
    InsertElem(L, 1, 6);
    InsertElem(L, 1, 9);
    InsertElem(L, 1, 12);
    cout << L << endl;

    int del;
    if (DeleteElem(L, 1, del)) {
        cout << "delete successfully." << endl;
    } else {
        cout << "failed to delete." << endl;
    }
    cout << L << endl;

    for (int i = 0; i < 100; ++i) {
        if (GetElem(L, i) != -1) {
            cout << i << ": " << GetElem(L, i) << ", ";
        }
    }
    cout << endl;

    for (int i = 0; i < 100; ++i) {
        if (LocateElem(L, i)) {
            cout << LocateElem(L, i) << ": " << i << ", ";
        }
    }
    return 0;
}
