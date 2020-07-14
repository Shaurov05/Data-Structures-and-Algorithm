#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node *leftchild;
    Node *rightchild;
};
Node *root = NULL;

void bst_insert(int value){
    Node *curr_node,*prev_node;
    if(root == NULL){
        root = new Node;
        root->data = value;
        root->leftchild = root->rightchild = NULL;
    }
    else{
        curr_node = root;
        while(curr_node != NULL){
            prev_node = curr_node;
            if(value < curr_node->data)
                curr_node = curr_node->leftchild;
            else if(value > curr_node->data)
                curr_node = curr_node->rightchild;
            else
                return; ///value can't be equal.
        }
        Node *newnode = new Node;
        newnode->data = value;
        newnode->leftchild = newnode->rightchild = NULL;
        if(newnode->data > prev_node->data)
            prev_node->rightchild = newnode;
        else
            prev_node->leftchild = newnode;
    }
}

void Inorder(struct Node *node){
    if( node ){
        Inorder(node->leftchild);
        printf("%d ",node->data);
        Inorder(node->rightchild);
    }
}

struct Node *Search(int value){
    struct Node *curr_node = root;
    while(curr_node != NULL){
        if(value == curr_node->data)
            return curr_node;
        else if(value < curr_node->data)
            curr_node = curr_node->leftchild;
        else if(value > curr_node->data)
            curr_node = curr_node->rightchild;
    }
    return NULL;
};

int Height(struct Node *p)
{
    int x,y;
    if(p==NULL)
        return 0;
    x=Height(p->leftchild);
    y=Height(p->rightchild);
    return x>y?x+1:y+1;
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
        free(p);
        return NULL;
    }
    if(key < p->data)
        p->leftchild=Delete(p->leftchild,key);
    else if(key > p->data)
        p->rightchild=Delete(p->rightchild,key);
    else
    {
        if(Height(p->leftchild)>Height(p->rightchild))
        {
            q=InPre(p->leftchild);
            p->data=q->data;
            p->leftchild=Delete(p->leftchild,q->data);}
        else
        {
            q=InSucc(p->rightchild);
            p->data=q->data;
            p->rightchild=Delete(p->rightchild,q->data);}
        }
    return p;
}

int main()
{
    struct Node *temp;
    bst_insert(13);
    bst_insert(9);
    bst_insert(12);
    bst_insert(10);
    bst_insert(8);
    bst_insert(6);
    bst_insert(16);
    bst_insert(15);
    bst_insert(25);
    ///Delete(root,30);
    Inorder(root);
    printf("\n");
    if(temp = Search(10)){
        printf("value %d found\n", temp->data);
    }
    else
        printf("value not found\n");

    Delete(root,8);
    Inorder(root);
    printf("\n");
}
