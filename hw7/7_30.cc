#include "../Graph/Graph.h"

bool visited[MAX_VERTEX_NUM] = {false};

bool CycleComplete = true;

int Cycle_start;

Status inCycle(MGraph G, int v_i)
{
    visited[v_i] = true;
    for (int i = 0; i < G.vexnum; i++)
    {
        if (i == v_i || G.arcs[v_i][i].adj == 0)
            continue;
        if (visited[i])
        {
            Cycle_start = i;
            CycleComplete = false;
            return TRUE;
        }
        else
        {
            if (inCycle(G, i) == TRUE)
            {
                if (!CycleComplete)
                {
                    cout << i << endl;
                    if (Cycle_start == i)
                        CycleComplete = true;
                }
                else
                    visited[i] = false;
                return TRUE;
            }
        }
    }
    visited[v_i] = false;
    return FALSE;
}

Status Cycle(MGraph G)
{
    for (int i = 0; i < G.vexnum; i++)
        visited[i] = false;
    for (int i = 0; i < G.vexnum; i++)
        if (inCycle(G, i) == TRUE)
            return TRUE;
    return FALSE;
}
