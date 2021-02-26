#include "../Array_GList/GList1.h"
//  头尾链表表示法
int GListDepth_recur(GList L)
{
    int tp_depth = 0, hp_depth = 0;
    if (!L)
        return 1;
    if (L->tag == ATOM)
        return 0;
    else
    {
        tp_depth = GListDepth_recur(L->ptr.tp);
        hp_depth = GListDepth_recur(L->ptr.hp) + 1;
        return (tp_depth > hp_depth) ? tp_depth : hp_depth;
    }
}