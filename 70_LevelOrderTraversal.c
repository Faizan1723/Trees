#include <stdio.h>
#include <stdlib.h>
#include "68_Queue.h"
struct Node *root = NULL;
void Treecreate()
{
    struct Node *p, *t;
    int x;
    struct Queue q;
    create(&q, 100);

    printf("Eneter root value ");
    scanf("%d", &x);
    root = (struct Node *)malloc(sizeof(struct Node));
    root->data = x;
    root->lchild = root->rchild = NULL;
    enqueue(&q, root);

    while (!isEmpty(q))
    {
        p = dequeue(&q);
        printf("eneter left child of %d ", p->data);
        scanf("%d", &x);
        if (x != -1)
        {
            t = (struct Node *)malloc(sizeof(struct
                                             Node));
            t->data = x;
            t->lchild = t->rchild = NULL;
            p->lchild = t;
            enqueue(&q, t);
        }
        printf("eneter right child of %d ", p->data);
        scanf("%d", &x);
        if (x != -1)
        {
            t = (struct Node *)malloc(sizeof(struct
                                             Node));
            t->data = x;
            t->lchild = t->rchild = NULL;
            p->rchild = t;
            enqueue(&q, t);
        }
    }
}
// void Preorder(struct Node *p)
// {
//     if (p)
//     {
//         printf("%d ", p->data);
//         Preorder(p->lchild);
//         Preorder(p->rchild);
//     }
// }
// void Inorder(struct Node *p)
// {
//     if (p)
//     {
//         Inorder(p->lchild);
//         printf("%d ", p->data);
//         Inorder(p->rchild);
//     }
// }
// void Postorder(struct Node *p)
// {
//     if (p)
//     {
//         Postorder(p->lchild);
//         Postorder(p->rchild);
//         printf("%d ", p->data);
//     }
// }

struct Node* queue[100];
int front=-1;
int rear=-1;

void insert_element(struct Node** p)
{
    if(front==-1 && rear==-1)
        front=rear=0;
    else
        rear++;
    queue[rear]=*p;   
}

struct Node* delete_element()
{
    struct Node* t;
    t=queue[front];
        front++;
    return t;
}

void LevelOrder(struct Node* p)
{
    printf("\n%d ",p->data);
    insert_element(&p);
    while (front<=rear)
    {
        p=delete_element();
        if(p->lchild!=NULL)
        {
            printf("%d ",p->lchild->data);
            insert_element(&p->lchild);
        }
        if(p->rchild!=NULL)
        {
            printf("%d ",p->rchild->data);
            insert_element(&p->rchild);   
        }
    }
}

int main()
{
    Treecreate();
    printf("LEVEL ORDER TRAVELSAL:-\n");
    LevelOrder(root);
    // Preorder(root);
    // printf("\nPost Order ");
    // Postorder(root);

    return 0;
}
