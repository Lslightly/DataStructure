#include "../Array_GList/MPList.h"

Status mul(MPList &M, AtomType coef)
{
    MPList p = M->hp->tp;
    while (p)
    {
        if (p->tag == ATOM)
            p->coef *= coef;
        else
            mul(p, coef);
        p = p->tp;
    }
    return OK;
}

Status Free(MPList &M)
{
    MPList p = M->hp;
    MPList temp = nullptr;
    while (p)
    {
        temp = p->tp;
        if (p->tag == ATOM)
        {
            free(p);
        }
        else
        {
            Free(p);
            free(p);
        }
        p = temp;
    }
    return OK;
}

Status partial_d(MPList &M)
{
    MPList pre_p = M->hp;
    MPList p = M->hp->tp;
    while (p)
    {
        if (p->exp != 0)
        {
            if (p->tag == ATOM)
            {
                p->coef *= p->exp;
                p->exp -= 1;
            }
            else
            {
                mul(p, p->exp);
                p->exp -= 1;
            }
        }
        else
        {
            if (p->tag == LIST)
                Free(p);
            pre_p->tp = nullptr;
            free(p);
            p = pre_p;
        }
        p = p->tp;
        pre_p = pre_p->tp;
    }
    return OK;
}