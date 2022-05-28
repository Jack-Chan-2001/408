#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

typedef int ElemType;
typedef struct {
    ElemType* elem;
    int len;
} table;

void initTable(table& T, int len) {
    T.len = len + 1; // 额外申请一个哨兵位置
    // T.elem = (ElemType*)malloc((T.len) * sizeof(ElemType));
    T.elem = new ElemType[T.len];
    srand(time(NULL)); // 为了验证排序 生成一个随机序列
    for (int i = 0; i < T.len; ++i) {
        T.elem[i] = rand() % 100;
    }
}

int seqSearch(table T, ElemType elem) {
    T.elem[0] = elem; // 0号元素作为哨兵
    int i;
    for (i = T.len - 1; T.elem[i] != elem; --i);
    return i;
}

int biSearch(const table& T, ElemType elem) {
    int low = 0, high = T.len - 1, mid;
    while (low <= high) {
        mid = (low + high) / 2;
        if (T.elem[mid] == elem) {
            return mid;
        } else if (T.elem[mid] < elem) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return -1;
}

ostream& operator<<(ostream& out, const table& T) {
    out << "len: " << T.len << endl;
    for (int i = 0; i < T.len; i++) {
        out << T.elem[i] << " ";
    }
    return out;
}

int compare(const void* left, const void* right) {
    return *(ElemType*)left - *(ElemType*)right;
}

int main() {
    table T;
    initTable(T, 10);
    cout << T << endl;
    qsort(T.elem, T.len, sizeof(ElemType), compare);
    cout << T << endl;
    for (int i = 0; i < 100; ++i) {
        int j = biSearch(T, i);
        if (j != -1) {
            cout << i << ": " << j << endl;
        }
    }
    return 0;
}
