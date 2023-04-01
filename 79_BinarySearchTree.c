#include<stdio.h>
#include<stdlib.h>

struct node
{
    struct node* lchild;
    int data;
    struct node* rchild;
};
struct node* root=NULL;

void insert(int key)
{
    struct node* t=root;
    struct node* r;
    struct node* p;

    if(t==NULL)
    {
        p=(struct node*)malloc(sizeof(struct node));
        p->data=key;
        p->lchild=p->rchild=NULL;
        root=p;
        return;
    }
    while (t!=NULL)
    {
        r=t;
        if(key<t->data)
        {
            t=t->lchild;
        }
        else if(key>t->data)
        {
            t=t->rchild;
        }
        else
        return;
    }
    p=(struct node*)malloc(sizeof(struct node));
    p->data=key;
    p->lchild=p->rchild=NULL;

    if(key<r->data)
    {
        r->lchild=p;
    }
    else
    {
        r->rchild=p;
    }
}

void Inorder(struct node *p)
{
    if (p)
    {
        Inorder(p->lchild);
        printf("%d ", p->data);
        Inorder(p->rchild);
    }
}
 
int main()
{
    insert(10);
    insert(5);
    insert(20);
    insert(8);
    insert(30);

    printf("THE INORDER TRAVERSAL OF THE BST IS : ");
    Inorder(root);
    return 0;
}