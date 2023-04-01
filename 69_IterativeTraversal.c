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
/*void Preorder(struct Node *p)
{
    if (p)
    {
        printf("%d ", p->data);
        Preorder(p->lchild);
        Preorder(p->rchild);
    }
}
void Inorder(struct Node *p)
{
    if (p)
    {
        Inorder(p->lchild);
        printf("%d ", p->data);
        Inorder(p->rchild);
    }
}
void Postorder(struct Node *p)
{
    if (p)
    {
        Postorder(p->lchild);
        Postorder(p->rchild);
        printf("%d ", p->data);
    }
}*/
int top=-1;
struct Node* stack[100];

void push(struct Node** t)
{
    top=top+1;
    stack[top]=*t;
}

struct Node* pop()
{
    struct Node* p=stack[top];
    top=top-1;
    return p;
}

void Ipreorder(struct Node *t)
{
    while (t!=NULL || top!=-1)
    {
        if(t!=NULL)
        {
            printf("%d ",t->data);
            push(&t);
            t=t->lchild;
        }
        else
        {
            t=pop();
            t=t->rchild;
        }
    }
    
}

void Iinorder(struct Node *t)
{
    while (t!=NULL || top!=-1)
    {
        if(t!=NULL)
        {
            push(&t);
            t=t->lchild;
        }
        else
        {
            t=pop();
            printf("%d ",t->data);
            t=t->rchild;
        }
    }
    
}

void Ipostorder(struct Node* t)
{
    long int temp;
    while (t!=NULL || top!=-1)
    {
        if(t!=NULL)
        {
            push(&t);
            t=t->lchild;
        }
        else
        {
            temp=(long int)pop();
            if(temp>0)
            {
               
                push(&t);
                t=((struct Node*)temp)->rchild;
            }
            else
            {
                printf("%d ",((struct Node*)temp)->data);
                t=NULL;
            }
        }
    }
}

int main()
{
    Treecreate();
    printf("PreOrder Traversal\n");
    Ipreorder(root);
    printf("\nInOrder Traversal\n");
    Iinorder(root);
    /*Preorder(root); 
    printf("\nPost Order ");
    Postorder(root);*/

    return 0;
}
