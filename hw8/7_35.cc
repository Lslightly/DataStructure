#include "../Graph/DAG.h"

bool visited[MAX_VERTEX_NUM] = {false};

Status DFSDG(ALGraph G, int vi)
{
    visited[vi] = true;
    ArcNode *p = G.vertices[vi].firstarc;
    while (p)
    {
        if (!visited[p->adjvex])
            DFSDG(G, p->adjvex);
        p = p->nextarc;
    }
    return OK;
}

int RootDAG(ALGraph G)
{
    for (int i = 0; i < G.vexnum; i++)
        visited[i] = false;
    for (int i = 0; i < G.vexnum; i++)
    {
        if (!visited[i])
        {
            DFSDG(G, i);
            bool all_visited = true;
            for (int i = 0; i < G.vexnum; i++)
                if ((all_visited = all_visited && visited[i]) == false)
                    break;
            if (all_visited)
                return i;
        }
    }
    return -1;
}