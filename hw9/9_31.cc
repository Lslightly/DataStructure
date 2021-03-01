#include "../SearchTable/DynamicSearchTable.h"

Status isBSTree(BiTree T)
{
    if (!T) return TRUE;
    if (T->rchild)
    {
        if (!isBSTree(T->rchild)) return FALSE;
        if (LT(T->rchild->data, T->data)) return FALSE;
    }
    if (T->lchild)
    {
        if (!isBSTree(T->lchild)) return FALSE;
        if (LT(T->data, T->lchild->data)) return FALSE;
    }
    return TRUE;
}