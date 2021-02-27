#include "../Tree/BiTree.h"
#include <map>
using namespace std;

BiTree ancestor(BiTree root, BiTree p, BiTree q)
{
    while (1)
    {
        if (InBiTree(root->lchild, p) && InBiTree(root->lchild, q))
            root = root->lchild;
        else if (InBiTree(root->rchild, p) && InBiTree(root->rchild, q))
            root = root->rchild;
        else
            break;
    }
    return root;
}

Status InBiTree(BiTree root, BiTree p)
{
    if (!root) return FALSE;
    else if (root == p) return TRUE;
    else return InBiTree(root->lchild, p) || InBiTree(root->rchild, p);
}

BiTree ancestor_faster(BiTree root, BiTree p, BiTree q)
{
    map<BiTree, bool> map_p;
    map<BiTree, bool> map_q;
    InBiTree_dynamic(root, p, map_p);
    InBiTree_dynamic(root, q, maq_q);
    while (1)
    {
        if (map_p.find(root->lchild) != map_p.end() && map_q.find(root->lchild) != map_q.end())
            root = root->lchild;
        else if (map_p.find(root->rchild) != map_p.end() && map_q.find(root->rchild) != map_q.end())
            root = root->rchild;
        else
            break;
    }
    return root;
}

Status InBiTree_dynamic(BiTree root, BiTree p, map<BiTree, bool> &map_p)
{
    if (!root) return FALSE;
    if (root == p)
    {
        map_p.insert({p, true});
        return TRUE;
    }
    else
        return InBiTree_dynamic(root->lchild, p, map_p) || InBiTree_dynamic(root->rchild, p, map_p);
}