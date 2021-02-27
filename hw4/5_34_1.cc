#include "../Array_GList/GList1.h"
//  头尾线性链表逆转

//  将L指向的头尾线性链表逆转，L指向逆转之后的第一个节点,并返回尾指针
GList GListReverse(GList &L)
{
    if (!L)
        return nullptr;
    else if (L->tag == LIST)
    {
        GListReverse(L->ptr.hp);
        GList temp = L;
        if (L->ptr.tp)
        {
            GList tail = GListReverse(L->ptr.tp);
            L = L->ptr.tp;
            temp->ptr.tp = nullptr;
            tail->ptr.tp = temp;
        }
        return temp;
    }
    else
    {
        return L;
    }
}