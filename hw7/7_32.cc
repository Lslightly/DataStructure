#include "../Graph/Graph.h"
#include "../Tree/Tree.h"

typedef struct
{
    int adjvex;
    int lowcost;
} Closedge;
Closedge closedge[MAX_VERTEX_NUM];

bool visited[MAX_VERTEX_NUM] = {false};

int minimum(ALGraph G)
{
    int min = INFINITY;
    int mink = 0;
    for (int i = 0; i < G.vexnum; i++)
        if (closedge[i].lowcost == 0)
            continue;
        else if (closedge[i].lowcost < min)
        {
            min = closedge[i].lowcost;
            mink = i;
        }
    return mink;
}

CSTree LocateCSNode(CSTree T, TElemType data)
{
    CSTree p;
    if (!T)
        return nullptr;
    else if (T->data == data)
        return T;
    else if (p = LocateCSNode(T->firstchild, data))
        return p;
    else
        return LocateCSNode(T->nextsibling, data);
}

Status AddChild(CSTree T, TElemType data)
{
    if (!T)
        return ERROR;
    else if (!T->firstchild)
    {
        T->firstchild = (CSTree)malloc(sizeof(CSNode));
        T->firstchild->data = data;
        T->firstchild->firstchild = nullptr;
        T->firstchild->nextsibling = nullptr;
    }
    else
    {
        CSTree p = T->firstchild;
        while (p->nextsibling)
            p = p->nextsibling;
        p->nextsibling = (CSTree)malloc(sizeof(CSNode));
        p->nextsibling->data = data;
        p->nextsibling->firstchild = nullptr;
        p->nextsibling->nextsibling = nullptr;
    }
    return OK;
}

Status MiniPrimSpan_Tree(ALGraph G, VertexType u, CSTree &T)
{
    int k, j, i, u_i = LocateVex(G, u);
    CSTree parent;

    k = u_i;
    visited[u_i] = true;
    for (j = 0; j < G.vexnum; j++)
        closedge[j] = {j, INFINITY};
    closedge[u_i].adjvex = -1;
    closedge[u_i].lowcost = 0;
    T = (CSTree)malloc(sizeof(*T));
    T->data = u_i;
    T->firstchild = nullptr;
    T->nextsibling = nullptr;
    for (int i = 1; i < G.vexnum; i++)
    {
        visited[k] = true;
        ArcNode *p = G.vertices[k].firstarc;
        while (p)
        {
            if (*(p->info) < closedge[p->adjvex].lowcost)
            {
                closedge[p->adjvex].lowcost = *(p->info);
                closedge[p->adjvex].adjvex = k;
            }
            p = p->nextarc;
        }
        k = minimum(G);
        if (closedge[k].lowcost == INFINITY)
            return FALSE;
        parent = LocateCSNode(T, closedge[k].adjvex);
        AddChild(parent, k);
        closedge[k].lowcost = 0;
    }
    return OK;
}

CSTree MiniPrimSpan_Forest(ALGraph G)
{
    CSTree T;
    CSTree p = T;
    CSTree parent;
    int i = 0;
    for (i = 0; i < G.vexnum; i++)
        visited[i] = false;
    MiniPrimSpan_Tree(G, 0, T);
    parent = T;
    for (i = 1; i < G.vexnum; i++)
        if (!visited[i])
        {
            MiniPrimSpan_Tree(G, i, p);
            parent->nextsibling = p;
            parent = p;
        }
    return OK;
}
