#ifndef BPLUSTREE_H
#define BPLUSTREE_H 1
//  B+树
#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2
typedef int Status;

typedef int KeyType;

typedef enum
{
    LEAF,
    BRANCH
} kind;

typedef struct BPTNode
{
    int tag; //  tag == LEAF叶子，tag == BRANCH非叶子节点
    int num_keys;
    KeyType *keys;        //  关键字
    struct BPTNode **ptr; //  指向孩子节点的指针数组，若为叶子，则指向下一个节点
} BPTNode, *BPTree;

typedef struct BPTreeFull
{
    BPTree root;
    BPTree sqt;
} BPTreeFull;

Status LocateBPTree(BPTree T, KeyType key, BPTree &leaf, int &place)
{
    int i;
    if (T->tag == LEAF)
    {
        for (i = 0; i < T->num_keys; i++)
            if (T->keys[i] == key)
            {
                leaf = T;
                place = i;
                return TRUE;
            }
        leaf = nullptr;
        place = -1;
        return FALSE;
    }
    else
    {
        for (i = 0; i < T->num_keys && key > T->keys[i]; i++)
            ;
        if (i == T->num_keys)
        {
            leaf = nullptr;
            place = -1;
            return FALSE;
        }
        else
        {
            return LocateBPTree(T->ptr[i], key, leaf, place);
        }
    }
}

#endif