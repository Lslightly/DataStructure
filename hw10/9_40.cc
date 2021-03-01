#include "../SearchTable/AVL.h"

BSTree kth(BSTree T, int k)
{
    if (T)
    {
        if (T->lsize == k)
            return T;
        else if (T->lsize < k)
            return kth(T->rchild, k-T->lsize);
        else
            return kth(T->lchild, k);
    }
    return nullptr;
}