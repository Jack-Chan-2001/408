/**
 * 实现了二叉树的层次建树，前序、中序、后续遍历，中序非递归遍历、递归遍历
 */
#include <iostream>
#include <stack>
#include <queue>
using namespace std;

typedef char ElemType;
typedef struct BiTNode {
    ElemType data;
    struct BiTNode* lchild, * rchild;
} BiTNode, * BiTree;

/**
 * 构建一个辅助队列用于层次建树
 * 辅助队列中存储二叉树结点的指针
 */
typedef struct tag {
    BiTree p;
    struct tag* pnext;
} tag_t, * ptag_t;

void preOrder(BiTree tree) {
    if (tree != nullptr) {
        cout << tree->data;
        preOrder(tree->lchild);
        preOrder(tree->rchild);
    }
}

/**
 * 递归形式的中序遍历
 */
void inOrder(BiTree tree) {
    if (tree != nullptr) {
        inOrder(tree->lchild);
        cout << tree->data;
        inOrder(tree->rchild);
    }
}

/**
 * 非递归形式的中序遍历
 * 使用栈作为辅助结构
 * 不为空 压栈       取其左孩子
 * 为空 弹栈并打印   取其右孩子
 */
void inOrder2(BiTree tree) {
    stack<BiTree> S;
    BiTree p = tree;
    while (p != nullptr || !S.empty()) {
        if (p) {
            S.push(p);
            p = p->lchild;
        } else {
            cout << S.top()->data;
            p = S.top()->rchild;
            S.pop();
        }
    }
}

void postOrder(BiTree tree) {
    if (tree != nullptr) {
        postOrder(tree->lchild);
        postOrder(tree->rchild);
        cout << tree->data;
    }
}

/**
 * 使用队列作为辅助结构实现
 */
void levelOrder(BiTree tree) {
    queue<BiTree> Q;
    BiTree p;
    Q.push(tree);
    while (!Q.empty()) {
        p = Q.front();
        Q.pop();
        if (p->lchild) {
            Q.push(p->lchild);
        }
        if (p->rchild) {
            Q.push(p->rchild);
        }
        cout << p->data;
    }
}

int main() {
    BiTree tree = nullptr;
    BiTree pnew = nullptr;
    ptag_t phead = nullptr, ptail = nullptr;
    ptag_t listpnew, pcurr;

    char c;
    while (scanf("%c", &c) != EOF) {
        if (c == '\n') {
            break;
        }
        pnew = (BiTree)calloc(1, sizeof(BiTNode)); // calloc申请空间并对空间进行初始化 赋值为0
        pnew->data = c;
        listpnew = (ptag_t)calloc(1, sizeof(tag_t)); // 申请辅助队列的空间
        listpnew->p = pnew;
        if (tree == nullptr) {
            tree = pnew;      // 树根
            phead = listpnew; // 队列头
            ptail = listpnew; // 队列尾
            pcurr = listpnew; // 始终指向插入结点的位置
            continue;         // 初始化不需要插入
        } else {
            ptail->pnext = listpnew; // 新结点尾插进入链表
            ptail = listpnew;
        }

        // 插入结点
        if (pcurr->p->lchild == nullptr) { // 插入结点没有左孩子
            pcurr->p->lchild = pnew;
        } else if (pcurr->p->rchild == nullptr) { // 插入结点有左孩子没有右孩子
            pcurr->p->rchild = pnew;
            pcurr = pcurr->pnext; // 有两个孩子后 pcurr指向下一个插入结点
        }
    }

    // preOrder(tree);
    inOrder(tree);
    postOrder(tree);
    levelOrder(tree);


    return 0;
}
