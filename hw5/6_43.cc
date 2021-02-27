#include "../Tree/BiTree.h"

Status SwapBiTree(BiTree &T)
{
    if (!T) return TRUE;
    BiTree temp;
    SwapBiTree(T->lchild);
    SwapBiTree(T->rchild);
    temp = T->lchild;
    T->lchild = T->rchild;
    T->rchild = temp;
    return TRUE;
}