#include<bits/stdc++.h>

using namespace std;

struct node{
    int data;
    node *prev, *next;
};

node *root = NULL;
node *tail = NULL;

node *root2 = NULL;
node *tail2 = NULL;

void appendnew(int position, int data,struct node*first){
    root = first;
    if(root == NULL){
        node *newnode = new node;
        newnode -> data = data;
        newnode -> next = NULL;
        newnode ->prev = NULL;
        root = newnode;
        tail = root;
    }
    else{
        node *current_node, *newnode, *next_node;
        current_node = root;
        next_node = root->next;
        int i=0;
        while(i<position-1){
            current_node = next_node;
            next_node = next_node->next;
            i++;
        }
        if(current_node){
            ///printf("current node = %d, data = %d, ", current_node->data, data);
            newnode = new node;
            newnode->data = data;
            newnode->next = current_node->next;

            if(next_node){
                ///printf("next = %d\n", next_node->data);
                next_node->prev = newnode;
            }
            current_node->next = newnode;
            newnode->prev = current_node;
        }
        if(newnode->next == NULL){
            tail = newnode;
    }}
    ///printf("tail = %d \n", tail->data);
}

void appendnew2(int position, int data,struct node*first){
    root2 = first;
    if(root2 == NULL){
        node *newnode = new node;
        newnode -> data = data;
        newnode -> next = NULL;
        newnode ->prev = NULL;
        root2 = newnode;
        tail2 = root;
    }
    else{
        node *current_node, *newnode, *next_node;
        current_node = root2;
        next_node = root2->next;
        int i=0;
        while(i<position-1){
            current_node = next_node;
            next_node = next_node->next;
            i++;
        }
        if(current_node){
            newnode = new node;
            newnode->data = data;
            newnode->next = current_node->next;

            if(next_node)
                next_node->prev = newnode;

            current_node->next = newnode;
            newnode->prev = current_node;
        }
        if(newnode->next == NULL){
            tail2 = newnode;
    }}
    ///printf("tail2 = %d \n", tail2->data);
}

void appendsort(int value){
    node *current_node = root;
    node *next_node = root->next;

    node *newnode = new node;
    newnode->data = value;
    while( current_node != NULL && (next_node)){
        if( current_node->data>=value ){
            newnode->next = current_node;
            newnode->prev = NULL;
            current_node->prev = newnode;
            root = newnode;
            return;
        }
        else if(current_node->data <=value
                && next_node->data >= value){
            newnode->prev = next_node->prev;
            newnode->next = next_node;
            current_node->next = newnode;
            next_node->prev = newnode;
            return;
        }
        else if(!(next_node->next) && next_node->data<value){
            newnode->next = next_node ->next;
            newnode->prev = next_node;
            next_node->next = newnode;
            tail = newnode;
            return;
        }
        else{
            current_node = current_node->next;
            next_node = next_node->next;
        }
        if(!next_node){
                tail = current_node;
            }
    }
}

void display(struct node *first){
    node *current_node = first;
    printf("data of linked list: ");
    while(current_node!= NULL){
        printf("%d ", current_node->data);
        current_node = current_node->next;
    }
    printf("\n");
}

void delete_node(int data){
    node *current_node = root;
    node *next_node = current_node->next;

    if( current_node->data == data){
        next_node->prev = NULL;
        root = next_node;
        printf("%d is deleted.\n", current_node->data);
        delete(current_node);
        return;
    }
    while( next_node != NULL ){
        node *newnode = NULL;
        if(next_node-> data == data){
            current_node->next = next_node->next;
            if((next_node->next)){
                newnode = next_node->next;
                newnode ->prev = current_node;
            }
            printf("%d is deleted.\n", next_node->data);
            if(next_node->next == NULL){
                tail = newnode;
            }
            free(next_node);
            return;
        }
        else{
            current_node = next_node;
            next_node = next_node->next;
        }
    }
    printf("%d is not present in the linked list.\n",data);
}

bool is_sorted(struct node *head){
    node *current_node = head;
    node *next_node = current_node->next;

    while( next_node->next != NULL ){
        static int smaller=0, larger=0;
        if((current_node->data <= next_node->data) && smaller==0){
            larger = 1;
            current_node = next_node;
            next_node =  next_node->next;
            ///printf("less\n");
        }
        else if((current_node->data >= next_node->data) && larger==0){
            smaller = 1;
            current_node = next_node;
            next_node =  next_node->next;
            ///printf("greater.\n");
        }
        else
            return false;
    }
    return true;
}

void remove_duplicate(struct node *root){
    node *current_node = root;
    node *next_node = current_node->next;
    while( next_node->next ){
        if(current_node->data == next_node->data){
            current_node->next = next_node->next;
            node *newnode = next_node->next;
            newnode ->prev = current_node;

        printf("duplicate =%d is deleted.\n",current_node->data);
        free(next_node);
        }
        current_node = next_node;
        next_node = next_node->next;
    }
}

struct node* reverse_ll(struct node*head, struct node *last){
    node *current_node = last;
    node *following_node = last->prev;

    while(1){
        ///printf("current = %d \n", current_node->data);
        current_node->prev = current_node->next;
        current_node->next = following_node;

        current_node = following_node;
        following_node = following_node->prev;
        if(!(following_node)){
            current_node->next = NULL;
            break;
        }
    }
    struct node*replica = head;
    head = last;
    last = replica;
    ///display(head);
    return head;
}

int main()
{
    appendnew(0,1,root);
    appendnew(1,8,root);
    appendnew(2,5,root);
    appendnew(3,7,root);
    appendnew(3,7,root);
    appendnew(5,9,root);
    appendnew(6,11,root);
    appendnew(7,11,root);
    printf("first linked list:\n");
    display(root);

    printf("\nsecond linked list:\n");
    appendnew2(0,2,root2);
    appendnew2(1,4,root2);
    appendnew2(2,6,root2);
    appendnew2(2,8,root2);
    appendnew2(4,10,root2);
    appendnew2(5,12,root2);
    display(root2);
    printf("\n");

    appendsort(0);
    appendsort(13);
    appendsort(14);
    appendsort(15);

    printf("after using appendsort, first linked list:\n");
    display(root);

    printf("\nperforming deletion:-\n");
    delete_node(7);
    delete_node(8);

    printf("\nRemoving duplicate.\n");
    remove_duplicate(root);
    printf("\n");
    display(root);

    root = reverse_ll(root, tail);

    printf("reversed \n");
    display(root);

    printf("\nsorted?\n");
    if(is_sorted(root)){
        printf("Yes! linked list is sorted.\n");
    }
    else
        printf("No! linked list is not sorted.\n");

}
