#include "../Array_GList/GList2.h"
//  拓展线性链表
Status GListEqual(GList L1, GList L2)
{
    if (!L1 && !L2) return TRUE;
    if (!L1 || !L2) return FALSE;
    if (L1->tag == LIST && L2->tag == LIST)
    {
        return GListEqual(L1->hp, L2->hp) && GListEqual(L1->tp, L2->tp);
    }
    else if (L1->tag == ATOM && L2->tag == ATOM)
    {
        return L1->atom == L2->atom && GListEqual(L1->tp, L2->tp);
    }
    else return FALSE;
}