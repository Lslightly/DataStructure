#include "../Graph/Graph.h"

bool visited[MAX_VERTEX_NUM] = {false};
bool complete[MAX_VERTEX_NUM] = {false};
int finished[MAX_VERTEX_NUM] = {0};
int count = 0;

//  以vi为尾进行遍历
Status DFS_Tail(OLGraph G, int vi)
{
    visited[vi] = true;
    ArcBox *p = G.xlist[vi].firstout;
    while (p)
    {
        if (!visited[p->headvex])
            DFS_Tail(G, p->headvex);
        p = p->tlink;
    }
    finished[count++] = vi;
    return OK;
}

Status DFS_Head(OLGraph G, int vi)
{
    complete[vi] = true;
    cout << vi << " ";
    ArcBox *p = G.xlist[vi].firstin;
    while (p)
    {
        if (visited[p->tailvex] && !complete[p->tailvex])
            DFS_Head(G, p->tailvex);
        p = p->hlink;
    }
    return OK;
}

Status StrongComponent(OLGraph G)
{
    int i = 0, j = 0;
    for (i = 0; i < G.vexnum; i++)
        complete[i] = visited[i] = false;
    for (i = 0; i < G.vexnum; i++)
    {
        count = 0;
        if (!visited[i])
            DFS_Tail(G, i);
        for (j = count - 1; j >= 0; j--)
            if (!complete[i])
            {
                DFS_Head(G, i);
                cout << endl;
            }
    }
    return OK;
}