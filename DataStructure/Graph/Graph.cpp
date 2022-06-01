/**
 * 图的邻接链表表示
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int MAX_VNUM = 10;
typedef struct ENode {
    int iV;                     // 该边所指向顶点的位置
    struct ENode* next_edge;
} ENode;

typedef struct VNode {
    char data;
    ENode* fitst_edge;
} VNode;

typedef struct LGraph {
    int VNums;
    int ENums;
    VNode V[MAX_VNUM];
} LGraph;

/**
 * 返回内容为 ch 的顶点在图中的下标
 */
int get_position(const LGraph* pG, char ch) {
    for (int i = 0; i < pG->VNums; ++i) {
        if (pG->V[i].data == ch) {
            return i;
        }
    }
    return -1;
}

/**
 * 尾插
 */
void link_last(ENode* list, ENode* newE) {
    ENode* p = list;
    while (p->next_edge) {
        p = p->next_edge;
    }
    p->next_edge = newE;
}

LGraph* create_example_lgraph() {
    LGraph* pG = (LGraph*)calloc(1, sizeof(LGraph));
    if (pG == nullptr) {
        return nullptr;
    }
    char Vs[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G'};
    char Es[][2] = {
        {'A', 'C'},
        {'A', 'D'},
        {'A', 'F'},
        {'B', 'C'},
        {'C', 'D'},
        {'E', 'G'},
        {'F', 'G'}};
    int VNums = sizeof(Vs) / sizeof(Vs[0]);
    int ENums = sizeof(Es) / sizeof(Es[0]);
    pG->ENums = ENums;
    pG->VNums = VNums;
    for (int i = 0; i < pG->VNums; ++i) {
        pG->V[i].data = Vs[i];
        pG->V[i].fitst_edge = nullptr;
    }
    int pos1, pos2;
    ENode* E1, * E2;
    for (int i = 0; i < pG->VNums; ++i) {
        pos1 = get_position(pG, Es[i][0]);
        pos2 = get_position(pG, Es[i][1]);

        E1 = (ENode*)malloc(sizeof(ENode));
        E1->iV = pos2;
        if (pG->V[pos1].fitst_edge == nullptr) {
            pG->V[pos1].fitst_edge = E1;
        } else {
            link_last(pG->V[pos1].fitst_edge, E1);
        }

        E2 = (ENode*)malloc(sizeof(ENode));
        E2->iV = pos1;
        if (pG->V[pos2].fitst_edge == nullptr) {
            pG->V[pos2].fitst_edge = E2;
        } else {
            link_last(pG->V[pos2].fitst_edge, E2);
        }
    }
    return pG;
}

void print_graph(const LGraph& G) {
    ENode* node;
    for (int i = 0; i < G.VNums; ++i) {
        printf("%d(%c): ", i, G.V[i].data);
        node = G.V[i].fitst_edge;
        while (node) {
            printf("%d(%c) ", node->iV, G.V[node->iV].data);
            node = node->next_edge;
        }
        printf("\n");
    }
}

void DFSHelper(const LGraph& G, int i, bool* visited) {
    ENode* node;
    visited[i] = true;
    printf("%c ", G.V[i].data);
    node = G.V[i].fitst_edge;
    while (node != nullptr) {
        if (!visited[node->iV]) {
            DFSHelper(G, node->iV, visited);
        }
        node = node->next_edge;
    }
}

void DFS(const LGraph& G) {
    int i;
    bool visited[MAX_VNUM];
    for (int i = 0; i < MAX_VNUM; ++i) {
        visited[i] = false;
    }
    for (int i = 0; i < G.VNums; ++i) {
        if (!visited[i]) {
            DFSHelper(G, i, visited);
        }
    }
    printf("\n");
}

void BFS(const LGraph G) {
    // 辅助队列
    int queue[MAX_VNUM];
    int head = 0, tail = 0;
    int j, k;
    bool visited[MAX_VNUM];
    ENode* node;

    for (int i = 0; i < G.VNums; ++i) {
        visited[i] = false;
    }
    for (int i = 0; i < G.VNums; ++i) {
        if (!visited[i]) {
            visited[i] = true;
            printf("%c ", G.V[i].data);
            queue[tail++] = i;          // 入队
        }
        while (head != tail) {
            j = queue[head++];          // 出队
            node = G.V[j].fitst_edge;
            while (node != nullptr) {
                k = node->iV;
                if (!visited[k]) {
                    visited[k] = true;
                    printf("%c ", G.V[k].data);
                    queue[tail++] = k;
                }
                node = node->next_edge;
            }
        }
    }
    printf("\n");
}

int main() {
    LGraph* pG = create_example_lgraph();
    print_graph(*pG);
    DFS(*pG);
    BFS(*pG);
    return 0;
}
