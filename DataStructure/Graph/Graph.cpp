#include <stdio.h>
const int MaxVertexNum = 100;

typedef char VertexType; // 顶点的数据类型
typedef int EdgeType;    // 带权图中边上权值的数据类型

/**
 * 邻接表图定义
 */
typedef struct {
    VertexType Vertex[MaxVertexNum];
    EdgeType Edge[MaxVertexNum][MaxVertexNum];
    int vexnum, arcnum; //当前顶点数和弧数
} MGraph;

/**
 * 邻接矩阵图定义
 */


int main() {
    return 0;
}
