#include "../SearchTable/DynamicSearchTable.h"

Status DeleteBST(BiTree &T)
{
    if (T)
    {
        DeleteBST(T->lchild);
        DeleteBST(T->rchild);
        free(T);
    }
    return OK;
}

//  删掉T下大于等于x的节点，并让T指向相应的节点
Status DeleteBSTGEx(BiTree &T, KeyType x)
{
    if (!T) return OK;
    if (LQ(x, T->data))
    {
        DeleteBST(T->rchild);
        BiTree p = T;
        T = T->lchild;
        free(p);
        DeleteBSTGEx(T, x);
    }
    else DeleteBSTGEx(T->rchild, x);
    return OK;
}