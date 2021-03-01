#include "../Graph/Graph.h"

bool visited[MAX_VERTEX_NUM] = {false};

void k_paths(MGraph G, int i, int j, int k, int &nums)
{
    visited[i] = true;
    for (int m = 0; m < G.vexnum; m++)
    {
        if (m == i)
            continue;
        if (G.arcs[i][m].adj == 1)
        {
            if (k == 1 && m == j)
                nums++;
            else if (k > 1)
            {
                k_paths(G, m, j, k - 1, nums);
            }
        }
    }
    visited[i] = false;
    return;
}

int num_k_paths(MGraph G, int i, int j, int k)
{
    for (int m = 0; m < G.vexnum; m++)
        visited[m] = false;
    int nums = 0;
    k_paths(G, i, j, k, nums);
    return nums;
}
