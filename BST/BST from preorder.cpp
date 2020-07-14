#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node *leftchild;
    Node *rightchild;
};

Node *root = NULL;
stack <Node *> my_stack;

void generateTree(int preorder[], int size){
    root = new Node;
    root->data = preorder[0];
    root->leftchild = root->rightchild = NULL;
    my_stack.push(root);
    Node *curr_node = root;

    int i=1,topdata=0;
    int value=0;
    while( i< size){
        int number = preorder[i];
        if(number < curr_node->data){
            my_stack.push(curr_node);
            Node *newnode = new Node;
            newnode->data = preorder[i];
            newnode->leftchild=newnode->rightchild=NULL;
            curr_node->leftchild = newnode;
            curr_node=newnode;
            i++;
        }
        else if(number > curr_node->data){
            if(!my_stack.empty())
                topdata = my_stack.top()->data;
            else
                topdata = 9*1e6;
            if(number>topdata){
                curr_node = my_stack.top();
                my_stack.pop();
            }
            else if(number < topdata){
                Node *newnode = new Node;
                newnode->data = number;
                newnode->leftchild = newnode->rightchild= NULL;
                curr_node->rightchild = newnode;
                curr_node = newnode;
                i++;
            }
        }
    }
}

void Inorder(Node *curr_node){
    if(curr_node){
        Inorder(curr_node->leftchild);
        printf("%d ",curr_node->data);
        Inorder(curr_node->rightchild);
    }
}

int main()
{
    int n;
    printf("Enter total the number of nodes: ");
    cin>> n;
    printf("Enter the pre-order representation of the tree: ");
    int preorder1[n];

    for(int i=0 ; i<n ;i++)
        cin>>preorder1[i];
    generateTree(preorder1, n);
    printf("Inorder form of the tree: ");
    Inorder(root);
    printf("\n");
}

/**
8
30 20 10 15 25 40 50 45
**/
