#include "../Tree/BiTree.h"

int leaves_BiTree(BiTree T)
{
    if (!T)
        return 0;
    if (!T->lchild && !T->rchild)
        return 1;
    else
        return leaves_BiTree(T->lchild) + leaves_BiTree(T->rchild);
}