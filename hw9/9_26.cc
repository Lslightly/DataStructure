#include "../SearchTable/StaticSearchTable.h"

int Search_Bin_recursion(SSTable ST, KeyType key)
{
}

int Search_Bin_recursion(SSTable ST, KeyType key, int low, int high)
{
    if (low > high) return -1;
    int temp;
    int mid = (low + high) / 2;
    if (EQ(ST.elem[mid].key, key))
        return mid;
    else if (LT(ST.elem[mid].key, key))
        return Search_Bin_recursion(ST, key, mid+1, high);
    else
        return Search_Bin_recursion(ST, key, low, mid-1);
}