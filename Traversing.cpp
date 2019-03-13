#include <stdio.h>
#include <stdlib.h>
typedef struct BiTNode
{
    /* data */
    char data;
    struct BiTNode *lchild, *rchild;
}BiTNode, *BiTree;

int preOrderTraverse(BiTree T)
{
    if(T)
    {
        printf("%c",T->data);
        preOrderTraverse(T->lchild);
        preOrderTraverse(T->rchild);
        return 1;
    }
    else
    {
        return 0;
    }
}

int inOrderTraverse(BiTree T)
{
    if(T)
    {
        inOrderTraverse(T->lchild);
        printf("%c",T->data);
        inOrderTraverse(T->rchild);
        return 1;
    }
    else
    {
        return 0;
    }
}

int pastOrderTraverse(BiTree T)
{
    if(T)
    {
        pastOrderTraverse(T->lchild);
        pastOrderTraverse(T->rchild);
        printf("%c",T->data);
        return 1;
    }
    else
    {
        return 0;
    }
}

BiTree initialBiTreeInPreOrder()
{
    BiTree T;
    char temp;
    T = (BiTree)malloc(sizeof(BiTNode));
    printf("enter a char for the node(space to exit):\n");
    scanf("%c",&temp);
    while(getchar() != '\n')
        continue;
    if(temp != ' ')
    {
        T->data = temp;
        T->lchild = initialBiTreeInPreOrder();
        T->rchild = initialBiTreeInPreOrder();
        return T;
    }
    else
    {
        return NULL;
    }
}

int main(void)
{
    BiTree T = initialBiTreeInPreOrder();
    preOrderTraverse(T);
    getchar();
    return 0;
}