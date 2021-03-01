#include "../Graph/DAG.h"
#include <stack>


void FindInDegree(ALGraph G, int indegree[MAX_VERTEX_NUM])
{
    int count;
    for (int i = 0; i < G.vexnum; i++) indegree[i] = 0;
    for (int i = 0; i < G.vexnum; i++)
    {
        ArcNode *p = G.vertices[i].firstarc;
        while (p)
        {
            indegree[p->adjvex]++;
            p = p->nextarc;
        }
    }
}

Status TopologicalCode(ALGraph &G)
{
    int indegree[MAX_VERTEX_NUM] = {0};
    int i, count = 0, k;
    ArcNode *p;
    FindInDegree(G, indegree);
    stack<int> S;
    for (i = 0; i < G.vexnum; i++)
        if (indegree[i] == 0)
            S.push(i);
    int k = G.vexnum-1;
    while (!S.empty())
    {
        i = S.top();
        count++;
        S.pop();
        G.vertices[i].data = k--;
        p = G.vertices[i].firstarc;
        while (p)
        {
            if ((--indegree[p->adjvex]) == 0)
                S.push(p->adjvex);
            p = p->nextarc;
        }
    }
    if (count != G.vexnum) return ERROR;
    return OK;
}