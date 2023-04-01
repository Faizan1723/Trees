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
 
struct node* search(int key)
{
    struct node* t=root;
    while(t!=NULL)
    {
        if(key==t->data)
        {
            return t;
        }
        else if(key<t->data)
        {
            t=t->lchild;
        }
        else
            t=t->rchild;
    }
    return NULL;
}

int main()
{
    struct node* temp=NULL;

    insert(10);
    insert(18);
    insert(1);
    insert(20);
    insert(80);

    printf("THE INORDER TRAVERSAL OF THE BST IS : ");
    Inorder(root);
    printf("\n");

    int key;
    printf("ENTER THE ELEMENT TO BE SEARCHED : ");
    scanf("%d",&key);
    temp=search(key);
    if(temp!=NULL)
        printf("ELEMENT %d IS FOUND.",temp->data);
    else    
        printf("ELEMENT NOT FOUND!\n");
    return 0;
}