#include "../SearchTable/DynamicSearchTable.h"
#include <stack>
#include <iostream>
using namespace std;

Status PrintGEx(BiTree T, int x)
{
    stack<BiTree> S;
    GEx(T, x, S);
    while (!S.empty())
    {
        cout << S.top()->data;
        S.pop();
    }
    return OK;
}

Status GEx(BiTree T, int x, stack<BiTree> &S)
{
    if (!T) return TRUE;
    GEx(T->lchild, x, S);
    if (LQ(x, T->data))
        S.push(T);
    GEx(T->rchild, x, S);
    return OK;
}