#include "../Tree/Tree.h"
#include <iostream>
using namespace std;

Status PrintCSTree(CSTree T, int num_space = 0)
{
    if (!T)
        return OK;
    string space = "";
    for (int i = 0; i < num_space; i++)
        space += " ";
    while (T)
    {
        cout << space << T->data << endl;
        PrintCSTree(T->firstchild, num_space + 1);
        T = T->nextsibling;
    }
    return OK;
}