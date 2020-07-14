#include<bits/stdc++.h>

using namespace std;

struct node{
    int data;
    node *prev, *next;
};

node *root = NULL;
node *tail = NULL;
node *cycle_start = NULL;

void appendnew(int position,int data,struct node*first){
    root = first;
    if(root == NULL){
        node *newnode = new node;
        newnode -> data = data;
        newnode -> next = newnode;
        newnode ->prev = newnode;
        root = newnode;
        tail = root;
    }
    else{
        node *current_node, *newnode, *next_node;
        newnode = new node;
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
            newnode->data = data;
            newnode->next = current_node->next;

            if(next_node){
                ///printf("next = %d\n", next_node->data);
                next_node->prev = newnode;
            }
            current_node->next = newnode;
            newnode->prev = current_node;
        }
        if(newnode->next == root){
            newnode->next = root;
            root->prev = newnode;
            tail = newnode;
    }
    }
    ///printf("root %d, tail = %d \n",root->data,tail->data);
}

void display(struct node *first, struct node *c_start){
    node *current_node = first;
    printf("data of linked list: ");
    int count=0;
    do{
        if (current_node == c_start) count++;
        if(count==2) break;

        printf("%d ", current_node->data);
        current_node = current_node->next;

    }while(current_node != first && current_node!=NULL);
    printf("\n");
}

struct node *detect_cycle(struct node *first, struct node *last){
    if(!first->next){
        printf("No cycle detected\n");
        return first;
    }
    else if(tail->next == NULL){
        printf("No cycle detected\n");
        return NULL;
    }

    struct node *tortoise = first;
    struct node *hare = first;
    while(1){
        if(hare->next && hare->next->next){
            hare = hare->next->next;
        }
        else{
            printf("No cycle detected\n");
            return first;
        }

        tortoise = tortoise->next;
        if(tortoise == hare)
            break;
    }
    node *tortoise2 = first;
    ///printf("tail next %d, tortoise2 %d\n",tail->next->data,tortoise2->data);

    while(tortoise2 != tortoise){
        tortoise2 = tortoise2->next;
        tortoise = tortoise->next;
    }
    printf("cycle starts from node: %d\n",tortoise2->data);
    return tortoise2;
}

void delete_node(int data, node *c_start){
    node *current_node = root;
    node *next_node = current_node->next;

    if( current_node->data == data){
        next_node->prev = tail;
        tail->next = next_node;
        root = next_node;
        printf("%d is deleted.\n", current_node->data);
        free(current_node);
        return;
    }
    int count=0;
    while( next_node != NULL ){
        node *newnode = NULL;

        if(next_node == c_start) count++;
        if(count==2){
            printf("%d is not present in the linked list.\n",data);
            return;}

        if(next_node-> data == data){
            current_node->next = next_node->next;
            if((next_node->next)){
                newnode = next_node->next;
                newnode ->prev = current_node;
            }
            else if(next_node->next == NULL){
                tail = next_node->prev;
            }
            printf("%d is deleted.\n", next_node->data);
            if(next_node==c_start) tail->next = NULL;
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

int main()
{
    appendnew(0,2,root);
    appendnew(1,4,root);
    appendnew(2,6,root);
    appendnew(3,10,root);
    appendnew(3,8,root);
    appendnew(5,12,root);
    appendnew(6,14,root);

    printf("first linked list:\n");
    display(root, NULL);
    cycle_start = detect_cycle(root,tail);

    printf("\n");
    delete_node(8, cycle_start);
    printf("\nafter deletion, \n");
    display(root, cycle_start);

    tail->next = root->next->next;

    cycle_start = detect_cycle(root,tail);
    printf("\n");
    delete_node(6, cycle_start);

    printf("\nfirst linked list:\n");
    display(root, cycle_start);

    detect_cycle(root,tail);
}
