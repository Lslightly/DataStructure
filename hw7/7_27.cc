#include "../Graph/Graph.h"

bool visited[MAX_VERTEX_NUM] = {false};

Status k_easy_path(ALGraph G, int u_i, int v_i, int k)
{
    visited[u_i] = true;
    ArcNode *p = G.vertices[u_i].firstarc;
    while (p)
    {
        if (visited[p->adjvex])
            p = p->nextarc;
        else if (p->adjvex == v_i && k == 1)
            return TRUE;
        else if (k > 1)
            if (k_easy_path(G, p->adjvex, v_i, k-1) == TRUE) return TRUE;
        p = p->nextarc;
    }
    visited[u_i] = false;
    return FALSE;
}

Status k_easy_path(ALGraph G, VertexType u, VertexType v, int k)
{
    int u_i = LocateVex(G, u), v_i = LocateVex(G, v);
    for (int i = 0; i < G.vexnum; i++)
        visited[i] = false;
    return k_easy_path(G, u_i, v_i, k);
}
