#include<stdio.h>
#include<stdlib.h>

struct node
{
    struct node* lchild;
    int data;
    struct node* rchild;
};
struct node* root=NULL;


/*************************************************************/
                    //RECURSIVE INSERT//
struct node* Rinsert(struct node* p, int key)
{
    struct node* t=NULL;
    if(p==NULL)
    {
        t=(struct node *)malloc(sizeof(struct node));
        t->data=key;
        t->lchild=t->rchild=NULL;
        return t;
    }
    if(key<p->data)
    {
        p->lchild=Rinsert(p->lchild,key);
    }
    else if(key>p->data)
    {
        p->rchild=Rinsert(p->rchild,key);   
    }
    return p;
}

                    //COUNT HEIGHT//
int Height(struct node* p)
{
    int x,y;
    if(p!=NULL)
    {
        x=Height(p->lchild);
        y=Height(p->rchild);
        if(x>y)
            return x+1;
        else
            return y+1;
    }
    return 0;
}


                    //INORDER PREDECESSOR//
struct node* InPre(struct node* p)
{
    while (p!=NULL && p->rchild!=NULL)
    {
       p=p->rchild;
    }
    return p;
}

                    //INORDER SUCCESOR//
struct node* InSuc(struct node* p)
{
    while (p!=NULL && p->lchild!=NULL)
    {
       p=p->lchild;
    }
    return p;
}

                    //RECURSIVE DELETE//
struct node* delete(struct node* p,int key)
{
    struct node* q;
    if(p==NULL)
        return NULL;
    if(p->lchild==NULL && p->rchild==NULL)
    {
        if(p==root);
            root=NULL;
        free(p);
        return NULL;
    }
    if(key<p->data)
    {
        p->lchild=delete(p->lchild,key);
    }
    else if(key>p->data)
    {
        p->rchild=delete(p->rchild,key);
    }
    else
    {
        if(Height(p->lchild)>Height(p->rchild))
        {
            q=InPre(p->lchild);
            p->data=q->data;
            p->lchild=delete(p->lchild,q->data);
        }
        else
        {
            q=InSuc(p->rchild);
            p->data=q->data;
            p->rchild=delete(p->rchild,q->data);
        }
    }
    return p;
}
/************************************************************/

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
    struct node* temp=NULL;

    root=Rinsert(root,10);
    Rinsert(root,5);
    Rinsert(root,20);
    Rinsert(root,8);
    Rinsert(root,30);

    printf("BEFORE DELETETION THE INORDER TRAVERSAL OF THE BINARY SEARCH TREE IS:-\n");
    Inorder(root);
    
    printf("\nAFTER DELETETION THE INORDER TRAVERSAL OF THE BINARY SEARCH TREE IS:-\n");
    root=delete(root,20);
    Inorder(root);

    printf("\n");
    return 0;
}