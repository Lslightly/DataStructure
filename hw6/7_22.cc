#include "../Graph/Graph.h"

bool visited[MAX_VERTEX_NUM];

Status AnyPathDG(ALGraph G, int v_i, int w_i)
{
    ArcNode *p = G.vertices[v_i].firstarc;
    visited[v_i] = true;
    while (p)
    {
        if (p->adjvex == w_i) return TRUE;
        if (visited[p->adjvex] == false)
        {
            if (AnyPathDG(G, p->adjvex, w_i) == TRUE) return TRUE;
        }
        p = p->nextarc;
    }
    visited[v_i] = false;
    return FALSE;
}

Status AnyPathDG(ALGraph G, VertexType v, VertexType w)
{
    int v_i = LocateVex(G, v);
    int w_i = LocateVex(G, w);
    for (int i = 0; i < G.vexnum; i++)
        visited[i] = false;
    return AnyPathDG(G, v_i, w_i);
}