#include "../Array_GList/GList2.h"
//  拓展线性链表

//  逆转L指向的链表，结果为L指向逆转之后的头结点，返回逆转之后的尾结点
GList GListReverse(GList &L)
{
    if (!L)
        return L;
    else if (L->tag == LIST)
        GListReverse(L->hp);
    GList temp = L;
    if (L->tp)
    {
        GList tail = GListReverse(L->tp);
        L = L->tp;
        temp->tp = nullptr;
        tail->tp = temp;
    }
    return temp;
}