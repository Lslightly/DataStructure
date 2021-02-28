#include "../Tree/Tree.h"
#include <iostream>
using namespace std;

Status PrintCSTree_format(CSTree T)
{
    if (!T) return OK;
    while (T)
    {
        cout << T->data;
        if (T->firstchild)
        {
            cout << "(";
            PrintCSTree_format(T->firstchild);
            cout << ")";
        }
        if (T->nextsibling)
            cout << ",";
        T = T->nextsibling;
    }
    return OK;
}