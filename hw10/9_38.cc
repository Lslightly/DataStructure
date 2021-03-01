#include "../SearchTable/DynamicSearchTable.h"

Status InsertBST(BiTree &T, BiTree src_T)
{
    if (src_T)
    {
        InsertBST(T, {src_T->data});
        InsertBST(T, T->lchild);
        InsertBST(T, T->rchild);
    }
    return OK;
}

Status MergeBSTree(BiTree T1, BiTree T2, BiTree &T)
{
    InsertBST(T, T1);
    InsertBST(T, T2);
    return OK;
}