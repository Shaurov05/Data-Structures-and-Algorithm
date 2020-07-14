#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node *leftchild;
    Node *rightchild;
    int height;
};
Node *root = NULL;

int NodeHeight(struct Node *p){
    int hl, hr;
    hl = p && p->leftchild?p->leftchild->height:0;
    hr = p && p->rightchild?p->rightchild->height:0;

    return hl>hr?hl+1:hr+1;
}

int BalanceFactor(struct Node *p){
    int hl, hr;
    hl = p && p->leftchild?p->leftchild->height:0;
    hr = p && p->rightchild?p->rightchild->height:0;

    return hl-hr;
}

struct Node *RLRotation(struct Node *p){
    printf("RL rotation performed\n");
    struct Node *pr= p->rightchild;
    struct Node *prl = pr->leftchild;

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

struct Node* LLRotation(struct Node *p){
    printf("LL rotation performed\n");
    Node *pl = p->leftchild;
    Node *plr = pl->rightchild;

    pl->rightchild = p;
    p->leftchild = plr;

    p->height = NodeHeight(p);
    pl->height = NodeHeight(pl);

    if(root==p)
        root=pl;
    return pl;
}

struct Node* RRRotation(struct Node *p){
    printf("RR performed\n");
    Node *pr = p->rightchild;
    Node *prl = pr->leftchild;

    pr->leftchild = p;
    p->rightchild = prl;

    pr->height = NodeHeight(pr);
    p->height = NodeHeight(p);

    if(root==p)
        root=pr;

    return pr;
}

struct Node* LRRotation(struct Node *p){
    printf("LR-rotation performed\n");
    struct Node *pl = p->leftchild;
    struct Node *plr = pl->rightchild;

    pl->rightchild = plr->leftchild;
    p->leftchild = plr->rightchild;

    plr->leftchild = pl;
    plr->rightchild = p;

    pl->height = NodeHeight(pl);
    p->height = NodeHeight(p);
    plr->height = NodeHeight(plr);

    if(root == p)
        root = plr;

    return plr;
}


struct Node *Rinsert(struct Node *p, int key){
    struct Node*t = NULL;
    if(p == NULL)
    {
        t =new Node;
        t->data = key;
        t->height = 1;
        t->leftchild = t->rightchild = NULL;
        return t;
    }
    if(key < p->data)
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

void Display(struct Node *p){
    if(p){
        Display(p->leftchild);
        printf("%d ",p->data);
        Display(p->rightchild);
    }
}

int main()
{
    root = Rinsert(root,13);
    Rinsert(root,9);
    Rinsert(root,12);
    Rinsert(root,10);
    Rinsert(root,8);
    Rinsert(root,6);
    Rinsert(root,16);
    Rinsert(root,15);
    Rinsert(root,25);
    Display(root);
    printf("\n");

    return 0;
}
