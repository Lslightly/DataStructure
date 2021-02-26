#include "../Array_GList/GList2.h"

int GListDepth(GList L)
{
    int tp_depth = 0, hp_depth = 0;
    if (!L)
        return 0;
    else if (L->tag == LIST)
        hp_depth = GListDepth(L->hp) + 1;
    else
        hp_depth = 0;
    tp_depth = GListDepth(L->tp);
    return (hp_depth > tp_depth) ? hp_depth : tp_depth;
}