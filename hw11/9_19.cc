#include <iostream>

#define MAX_NUM_KEY 100

bool visited[MAX_NUM_KEY] = {false};

int d(int k, int i)
{
    return  i*((7 * k) % 10 + 1);
}

int H(int k, int h[MAX_NUM_KEY])
{
    int hk = (3 * k) % 11;
    int i = 1;
    int try_hk = hk;
    while (visited[try_hk])
    {
        try_hk = (hk + d(k, i++)) % 11;
    }
    visited[try_hk] = true;
    h[try_hk] = k;
    return 0;
}

int main(void)
{
    int k[8] = {22, 41, 53, 46, 30, 13, 1, 67};
    int h[11] = {0};
    for (int i = 0; i < 10; i++)
        visited[i] = false;
    for (int i = 0; i < 8; i++)
        H(k[i], h);
    for (int i = 0; i < 11; i++)
        std::cout << i << " "<< h[i] << std::endl;
    return 0;
}
