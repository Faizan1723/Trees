#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node* lchild;
    struct node* rchild;
    int height;
};
struct node* root=NULL;

int node_height(struct node* p)
{
    int hl,hr;      //hl is height of left subtree and hr is height of right subtree.
    hl=p && p->lchild ? p->lchild->height:0;//if p is not null and p->lchild is there then return p's left child's height else return 0.
    hr=p && p->rchild ? p->rchild->height:0;//if p is not null and p->rchild is there then return p's right child's height else return 0.

    return hl>hr?hl+1:hr+1;
}

int balancefactor(struct node *p)
{
    int hl,hr;      //hl is height of left subtree and hr is height of right subtree.
    hl=p && p->lchild ? p->lchild->height:0;
    hr=p && p->rchild ? p->rchild->height:0;

    return hl-hr;
}

struct node* LLRoatation(struct node* p)
{
    struct node* pl=p->lchild;
    struct node* plr=pl->rchild;

    pl->rchild=p;
    p->lchild=plr;

    p->height=node_height(p);
    pl->height=node_height(pl);

    if(root==p)
        root=pl;

    return pl;
}

struct node* LRRoatation(struct node* p)
{
    struct node* pl=p->lchild;
    struct node* plr=pl->rchild;

    pl->rchild=plr->lchild;
    p->lchild=plr->rchild;

    plr->lchild=pl;
    plr->rchild=p;

    pl->height=node_height(pl);
    p->height=node_height(p);
    plr->height=node_height(plr);

    if(root=p)
        root=plr;
        
    return plr;
}

struct node* RRRoatation(struct node* p)
{
    struct node* pr=p->rchild;
    struct node* prl=pr->lchild;

    pr->lchild=p;
    p->rchild=prl;

    p->height=node_height(p);
    pr->height=node_height(pr);

    if(root==p)
        root=pr;
    
    return pr;
}

struct node* RLRoatation(struct node* p)
{
    struct node* pr=p->rchild;
    struct node* prl=pr->lchild;

    pr->lchild=prl->rchild;
    p->rchild=prl->lchild;

    prl->rchild=pr;
    prl->lchild=p;

    pr->height=node_height(pr);
    p->height=node_height(p);
    prl->height=node_height(prl);
    
    if(root==p)
        root=prl;
    
    return prl;
}

struct node* Rinsert(struct node* p, int key)
{
    struct node* t=NULL;
    if(p==NULL)
    {
        t=(struct node *)malloc(sizeof(struct node));
        t->data=key;
        t->height=1;
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

    p->height=node_height(p);

    if(balancefactor(p)==2 && balancefactor(p->lchild)==1)
    {
        return LLRoatation(p);
    }
    else if(balancefactor(p)==2 && balancefactor(p->lchild)==-1)
    {
        return LRRoatation(p);
    }
    else if(balancefactor(p)==-2 && balancefactor(p->rchild)==-1)
    {
        return RRRoatation(p);
    }
    else if(balancefactor(p)==-2 && balancefactor(p->rchild)==1)
    {
        return RLRoatation(p);
    }

    return p;
}

void Preorder(struct node *p)
{
    if (p)
    {
        printf("%d ", p->data);
        Preorder(p->lchild);
        Preorder(p->rchild);
    }
}

int main()
{
    int key,n;

    printf("ENTER THE TOTAL NO. OF KEYS IN THE AVL TREE: ");
    scanf("%d",&n);
    int key_array[n];

    // printf("ENTER THE FIRST KEY OF AVL TREE: \n");
    // scanf("%d",&key);
    // root=Rinsert(root,key);

    printf("ENTER THE KEYS OF THE AVL TREE:-\n");
    for(int i=0;i<n;i++)
    {   
        scanf("%d",&key_array[i]);
    }
    
    for(int i=0;i<n;i++)
    {
        key=key_array[i];
        if(i==0)
        {
            root=Rinsert(root,key);
        }
        else
            Rinsert(root,key);    
    }
    // root=Rinsert(root,10);
    // Rinsert(root,30);
    // Rinsert(root,20);

    Preorder(root);
    return 0;
}