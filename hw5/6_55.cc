#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2
typedef int Status;
typedef int TElemType;
typedef struct BiNode
{
    TElemType data;
    struct BiNode *lchild, *rchild;
    int DescNum;
} BiNode, *BiTree;

int Desc_BiTree(BiTree T)
{
    if (!T)
        return 0;
    T->DescNum = Desc_BiTree(T->lchild) + Desc_BiTree(T->rchild);
    if (T->lchild)
        T->DescNum += 1;
    if (T->rchild)
        T->DescNum += 1;
    return T->DescNum + 1;
}