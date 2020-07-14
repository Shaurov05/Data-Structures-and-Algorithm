#include<bits/stdc++.h>
#include<cstdio>
using namespace std;

struct node{
    int data;
    node *next;
};

node *root = NULL ;

void append(int a[], int n){
    node *new_node, *current_node;
    for(int i=0; i<n ;i++){
        if(root == NULL){
            root = new node;
            root -> data = a[0];
            root -> next = NULL;
            current_node = root;
        }
        else{
            new_node = new node;
            new_node -> data = a[i];
            new_node -> next = NULL;

            current_node -> next = new_node; ///linking with new node
            current_node = new_node;
        }
    }
}

void Insert(int data,int position){
    node *current_node = root;
    if(position<0){
        return;
    }
    else if(position == 0){
        node *newnode = new node;
        newnode ->data = data;
        newnode ->next = root;
        root = newnode;
    }
    else if(position>0){
        node *newnode, *p;
        p = root;
        for(int i=0 ; i< (position - 1) && p ; i++){
            p = p ->next;
        }
        if(p){
            newnode = new node;
            newnode ->data = data;
            newnode ->next = p -> next;
            p ->next = newnode;
            ///cout<< p;
        }
    }
}

void display(){
    node *current_node = root;
    while(current_node != NULL){
        printf("data is = %d\n", current_node -> data);
        current_node = current_node -> next;
    }
}

int main()
{
    int a[] = {1,2,3,4,5};

    append(a, 5);

    Insert(23, 3);
    ///Insert(24, 0);
    Insert(25,9);
    display();
}

