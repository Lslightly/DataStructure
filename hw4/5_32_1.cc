#include "../Array_GList/GList1.h"
//  头尾链表
Status GListEqual(GList L1, GList L2)
{
    if (!L1 && !L2) return TRUE;
    if (!L1 || !L2) return FALSE;
    if (L1->tag == LIST && L2->tag == LIST)
    {
        return GListEqual(L1->ptr.hp, L2->ptr.hp) && GListEqual(L1->ptr.tp, L2->ptr.tp);
    }
    else if (L1->tag == ATOM && L2->tag == ATOM)
    {
        return L1->atom == L2->atom;
    }
    else return FALSE;
}