#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    int height;
    Node *leftchild;
    Node *rightchild;
};
Node *root = NULL;

int NodeHeight(struct Node *p){
    int x,y;
    if(p==NULL)return 0;
        x=NodeHeight(p->leftchild);
        y=NodeHeight(p->rightchild);

    return x>y?x+1:y+1;
}

int BalanceFactor(struct Node *p){
    int hl, hr;
    hl = p and p->leftchild? p->leftchild->height:0;
    hr = p and p->rightchild? p->rightchild->height:0;

    return hl-hr;
}

struct Node *LLRotation(struct Node *p){
    printf("LL rotation performed\n");
    struct Node *pl = p->leftchild;
    struct Node *plr = pl->rightchild;
    printf("root %d, p %d, pl %d, pll %d\n\n",root->data,p->data,pl->data,pl->leftchild->data);

    pl->rightchild = p;
    p->leftchild = plr;

    pl->height=NodeHeight(pl);
    p->height = NodeHeight(p);

    if(p == root)
        root = pl;

    return pl;
};

struct Node *LRRotation(struct Node *p){
    printf("LR rotation performed\n");
    struct Node *pl = p->leftchild;
    struct Node *plr = pl->rightchild;
    printf("root %d, p %d, pl %d, plr %d\n\n",root->data,p->data,pl->data,plr->data);

    pl->rightchild = plr->leftchild;
    p->leftchild = plr->rightchild;

    plr->rightchild = p;
    plr->leftchild = pl;

    plr->height=NodeHeight(plr);
    p->height = NodeHeight(p);
    pl->height = NodeHeight(pl);

    if(p == root)
        root = plr;

    return plr;
};

struct Node *RLRotation(struct Node *p){
    printf("RL rotation performed\n");
    struct Node *pr= p->rightchild;
    struct Node *prl = pr->leftchild;
    printf("root %d, p %d, pr %d, prl %d\n\n",root->data,p->data,pr->data,prl->data);

    pr->leftchild = prl->rightchild;
    p->rightchild = prl->leftchild;
    prl->rightchild = pr;
    prl->leftchild = p;
    ///printf("p %d, p->left %d, p->right %d\n",prl->data,prl->leftchild->data,prl->rightchild->data);

    prl->height=NodeHeight(prl);
    p->height = NodeHeight(p);
    pr->height = NodeHeight(pr);

    if(p == root)
        root = prl;

    return prl;
};

struct Node *RRRotation(struct Node *p){
    printf("RR rotation performed\n");
    struct Node *pr = p->rightchild;
    struct Node *prl = pr->leftchild;
    printf("root %d, p %d, pr %d, prr %d\n\n",root->data,p->data,pr->data,pr->rightchild->data);

    pr->leftchild = p;
    p->rightchild = prl;

    pr->height=NodeHeight(pr);
    p->height = NodeHeight(p);

    if(p == root)
        root = pr;

    return pr;
};

struct Node *Rinsert(struct Node *p,int key){

    if(p == NULL){
        Node *t = new Node;
        t->data = key;
        t->leftchild = t->rightchild = NULL;
        t->height = 1;
        return t;
    }
    if(key< p->data)
        p->leftchild = Rinsert(p->leftchild, key);
    else if(key > p->data)
        p->rightchild = Rinsert(p->rightchild, key);

    p->height = NodeHeight(p);

    if(BalanceFactor(p)==2 && BalanceFactor(p->leftchild)==1)
        return LLRotation(p);
    else if(BalanceFactor(p)==2 && BalanceFactor(p->leftchild)==-1)
        return LRRotation(p);
    else if(BalanceFactor(p)==-2 && BalanceFactor(p->rightchild)==-1)
        return RRRotation(p);
    else if(BalanceFactor(p)==-2 && BalanceFactor(p->rightchild)==1)
        return RLRotation(p);

    return p;
};

void Inorder(struct Node*p){
    if(p){
        Inorder(p->leftchild);
        printf("%d ", p->data);
        Inorder(p->rightchild);
    }
}

struct Node *InPre(struct Node *p)
{
    while(p && p->rightchild!=NULL)
        p=p->rightchild;
    return p;
}

struct Node *InSucc(struct Node *p)
{
    while(p && p->leftchild!=NULL)
        p=p->leftchild;
    return p;
}

struct Node *Delete(struct Node *p,int key)
{
    struct Node *q;
    if(p==NULL)
        return NULL;

    if(p->leftchild==NULL && p->rightchild==NULL)
    {
        if(p==root)
            root=NULL;
        ///printf("deleting %d\n",key);
        ///printf("Dhukse %d, balance %d\n",p->data,BalanceFactor(p));
        free(p);
        return NULL;
    }
    if(key < p->data)
        p->leftchild=Delete(p->leftchild,key);
    else if(key > p->data)
        p->rightchild=Delete(p->rightchild,key);
    else if(key == p->data)
    {
        if(NodeHeight(p->leftchild)>NodeHeight(p->rightchild))
        {
            q=InPre(p->leftchild);
            p->data=q->data;
            ///printf("Dhukse 1\n");
            p->leftchild=Delete(p->leftchild,q->data);}
        else
        {
            q=InSucc(p->rightchild);
            p->data=q->data;
            ///printf("Dhukse 2\n");
            p->rightchild=Delete(p->rightchild,q->data);}
    }
    else{
        printf("Value not found\n");
        return NULL;
    }
    printf("Checking balance\n");
    if(BalanceFactor(p)==2 && BalanceFactor(p->leftchild)==1)
        return LLRotation(p);
    else if(BalanceFactor(p)==2 && BalanceFactor(p->leftchild)==-1)
        return LRRotation(p);
    else if(BalanceFactor(p)==2 && BalanceFactor(p->leftchild)==0)
        return LLRotation(p);
    else if(BalanceFactor(p)==-2 && BalanceFactor(p->rightchild)==-1)
        return RRRotation(p);
    else if(BalanceFactor(p)==-2 && BalanceFactor(p->rightchild)==1)
        return RLRotation(p);
    else if(BalanceFactor(p)==-2 && BalanceFactor(p->leftchild)==0)
        return RRRotation(p);

    return p;
}

int main()
{
    root = Rinsert(root,10);
    Rinsert(root,20);
    Rinsert(root,5);
    Rinsert(root,30);
    Rinsert(root,15);
    //Rinsert(root,5);
    /**Rinsert(root,13);
    Rinsert(root,9);
    Rinsert(root,12);
    Rinsert(root,10);
    Rinsert(root,6);
    Rinsert(root,5);
    Rinsert(root,16);
    Rinsert(root,15);
    Rinsert(root,25);
    Rinsert(root,14);**/

    Inorder(root);
    printf("\nroot =%d\n",root->data);

    Delete(root,5);
    Inorder(root);
    printf("\nnew root =%d\n",root->data);

    return 0;
}
