#include <iostream>
using namespace std;

typedef int KeyType;
typedef struct BSTNode {
    KeyType key;
    struct BSTNode* lchild, * rchild;
} BSTNode, * BiTree;

bool insert(BiTree& T, KeyType elem) {
    if (T == nullptr) {
        T = new BSTNode();
        T->key = elem;
        T->lchild = nullptr;
        T->rchild = nullptr;
        return true;
    } else if (T->key < elem) {
        insert(T->rchild, elem);
    } else if (T->key > elem) {
        insert(T->lchild, elem);
    }
    return false;
}

void createBST(BiTree& T, KeyType elems[], int n) {
    T = nullptr;
    int i = 0;
    while (i < n) {
        insert(T, elems[i]);
        ++i;
    }
}

/**
 * BST查找的递归实现
 * 比较简单但是效率低
 */
BiTree BSTsearch_recur(const BiTree& T, KeyType elem) {
    if (T != nullptr) {
        if (T->key == elem) {
            return T;
        } else if (T->key < elem) {
            return BSTsearch_recur(T->rchild, elem);
        } else {
            return BSTsearch_recur(T->lchild, elem);
        }
    }
    return nullptr;
}

/**
 * BST查找的迭代实现
 * 复杂高效
 * p存储要找的结点的父结点
 */
BiTree BSTsearch_iter(BiTree T, KeyType elem, BiTree& parent) {
    parent = nullptr;
    while (T != nullptr && elem != T->key) {
        parent = T;
        if (elem < T->key) {
            T = T->lchild;
        } else {
            T = T->rchild;
        }
    }
    return T;
}

void deleteElem(BiTree& T, KeyType elem) {
    if (T == nullptr) {
        return;
    }
    if (T->key < elem) {
        deleteElem(T->rchild, elem);
    } else if (T->key > elem) {
        deleteElem(T->lchild, elem);
    } else { // find this elem
        BiTree trash = T;
        if (T->lchild == nullptr) {
            T = T->rchild;
            delete trash;
        } else if (T->rchild == nullptr) {
            T = T->lchild;
            delete trash;
        } else {
            // 左子树的最大数据 代替要删除的结点 然后删除左子树里"那个"位置的结点
            BiTree temp = T->lchild;
            while (temp->rchild != nullptr) {
                temp = temp->rchild;
            }
            T->key = temp->key;
            deleteElem(T->lchild, temp->key); // 递归思想
        }

    }
}

void inOrder(const BiTree T) {
    if (T) {
        inOrder(T->lchild);
        cout << T->key << " ";
        inOrder(T->rchild);
    }
}

int main() {
    BiTree T = nullptr;
    BiTree parent;
    BiTree search;
    KeyType elems[] = {54, 20, 66, 40, 28, 79, 58};
    createBST(T, elems, 7);
    inOrder(T);
    cout << endl;
    // for (int i = -20; i < 120; ++i) {
    //     search = BSTsearch_recur(T, i);
    //     if (search) { // 递归实现
    //         cout << "T BSTsearch_recur " << i << endl;
    //     }
    //     search = BSTsearch_iter(T, i, parent);
    //     if (search) { // 迭代实现
    //         cout << "T BSTsearch_recur " << i << endl;
    //     }
    // }

    deleteElem(T, 54);
    inOrder(T);
    cout << endl;

    return 0;
}
