#include<bits/stdc++.h>
using namespace std;

struct node{
    int data;
    node *left=NULL;
    node *right= NULL;
};
node *root;

void insert(int roll)
{
    if(root == NULL){
        node *newnode = new node;
        newnode->data = roll;
        root = newnode;
    }
    else{
        node *current_node = root;
        node *parent_node = current_node;

        while(current_node != NULL)
        {
            if(current_node->data > roll){
                parent_node = current_node;
                current_node = current_node->left; }
            else{
                parent_node = current_node;
                current_node = current_node->right; }
        }
        node *newnode = new node;
        newnode->data = roll;

        if(parent_node->data > newnode->data)
            parent_node->left = newnode;
        else
            parent_node->right = newnode;
    }
}

void print_preorder(node *current){
    if(current == NULL) return;
    cout<<current->data<<endl;
    print_preorder(current->left);
    print_preorder(current->right);
}

int main()
{
    insert(100);
    insert(50);
    insert(80);
    insert(150);
    insert(120);
    insert(30);
    insert(50);
    insert(170);
    insert(90);

    print_preorder(root);
}
