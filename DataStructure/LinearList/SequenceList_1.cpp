/**
 * 线性表的顺序表实现
 * 静态分配数组
 */
#include <iostream>
using namespace std;

typedef int ElemType;
#define MAX_SIZE 50
typedef struct SequenceList {
    ElemType data[MAX_SIZE];
    int len;
} SeqList;

void InitList(SeqList& L) {
    L.len = 0;
}

/**
 * 直接用流输出，便于调试
 */
ostream& operator<<(ostream& out, const SeqList& L) {
    for (int i = 0; i < L.len; ++i) {
        out << L.data[i] << " ";
    }
    return out;
}

bool ListInsert(SeqList& L, int pos, ElemType elem) {
    // 判断插入位置是否合法
    if (pos < 1 || pos > L.len + 1 || pos >= MAX_SIZE) {
        return false;
    }
    for (int i = L.len; i >= pos; i--) {
        L.data[i] = L.data[i - 1];
    }
    L.data[pos - 1] = elem;
    L.len++;
    return true;
}

/**
 * 删除线性表在 pos 位置的元素，并把值输出到 del
**/
bool ListDelete(SeqList& L, int pos, ElemType& del) {
    // 判断删除位置是否合法
    if (pos < 1 || pos > L.len || L.len == 0) {
        return false;
    }
    del = L.data[pos - 1];
    for (int i = pos; i < L.len; ++i) {
        L.data[i - 1] = L.data[i];
    }
    L.len--;
    return true;
}

/**
 * 查找元素 elem 是否在线性表内
 * 查找成功则返回元素在线性表内的位置
 * 查找失败，返回0
 */
int LocateElem(SeqList& L, const ElemType& elem) {
    int i = 0;
    while (i < L.len - 1) {
        if (L.data[i] == elem) {
            return i + 1;
        }
        i++;
    }
    return 0;
}

int main() {
    SeqList L;
    InitList(L);
    L.data[0] = 1;
    L.data[1] = 2;
    L.data[2] = 3;
    L.len = 3;
    cout << L << endl;
    bool ret = ListInsert(L, 2, 60);
    if (ret) {
        cout << "insert successfully" << endl;
    } else {
        cout << "insert failed." << endl;
    }
    cout << L << endl;

    ElemType del;
    ret = ListDelete(L, 2, del);
    cout << L << endl;

    ElemType locate_elem = 60;
    int locate = LocateElem(L, locate_elem);
    if (locate) {
        cout << "locate " << locate_elem << " in " << locate << endl;
    } else {
        cout << "can not locate " << locate_elem << endl;
    }
    cout << L << endl;

    return 0;
}


