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

node *root3 = NULL;
node *tail3 = NULL;

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
        if(newnode->next == NULL)
            tail = newnode;
    }
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
    printf("data of linked list: \n");
    while(current_node != NULL){
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
            else if(next_node->next == NULL){
                tail = next_node->prev;
            }
            printf("%d is deleted.\n", next_node->data);
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
    int smaller=0, larger=0;
    while( next_node->next != NULL ){
        if((current_node->data <= next_node->data)&&smaller==0){
            larger = 1;
            ///printf("current %d, next=%d.\n",current_node->data, next_node->data);
            current_node = next_node;
            next_node =  next_node->next;
            ///printf("less\n");
        }
        else if((current_node->data >= next_node->data)&&larger==0){
            smaller = 1;
            ///printf("current %d, next=%d.\n",current_node->data, next_node->data);
            current_node = next_node;
            next_node =  next_node->next;
        }
        else
            return false;
    }
    return true;
}

void remove_duplicate(struct node *root){
    node *current_node = root;
    node *next_node = current_node->next;
    bool removed = false;
    while( next_node->next ){
        if(current_node->data == next_node->data){
            removed = true;
            current_node->next = next_node->next;
            node *newnode = next_node->next;
            newnode ->prev = current_node;

        printf("duplicate =%d is deleted.\n",current_node->data);
        free(next_node);
        }
        current_node = next_node;
        next_node = next_node->next;
    }
    if(!removed)
        printf("No duplicate present in the list.\n");
}

struct node* reverse_ll(struct node*head, struct node *last){
    node *current_node = last;
    node *following_node = last->prev;
    ///printf("current = %d, following %d\n", current_node->data, following_node->data);
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
    tail = last;
    ///printf("tail reverse = %d\n",tail->data);
    ///printf("head reverse = %d\n",head->data);
    ///display(head);
    return head;
}

void is_loop(struct node *first, struct node *last){
    if(!first->next){
        printf("No cycle detected\n");
        return;
    }

    struct node *tortoise = first;
    struct node *hare = first;
    while(1){
        if(hare->next && hare->next->next){
            hare = hare->next->next;
        }
        else{
            printf("No cycle detected\n");
            return;  }

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
}

void concatenate(struct node*first, struct node*second){
    node *current1=first;
    node *current2=second;
    node *current3;
    while(current1!=NULL || current2!=NULL){
        if(current1 == NULL){
            while(current2){
                ///printf("insert 1, current1 = %d ",current1->data);
                node *newnode = new node;
                newnode->data = current2->data;
                newnode->next = current3->next;
                newnode->prev = current3;
                current3->next = newnode;

                current2 = current2->next;
                current3 = current3->next;
            ///printf("root3=%d, tail=%d, current3 =%d\n",root3->data,tail3->data,current3->data);
            }
            return;
        }
        else if(current2 == NULL){
            while(current1){
                ///printf("insert 2, current1 = %d ",current1->data);
                node *newnode = new node;
                newnode->data = current1->data;
                newnode->next = current3->next;
                newnode->prev = current3;
                current3->next = newnode;

                current1 = current1->next;
                current3 = current3->next;
            ///printf("root3=%d, tail=%d, current3 =%d\n",root3->data,tail3->data,current3->data);
            }
            return;
        }
        else if(current1->data < current2->data){
            ///printf("list1 =%d < list2 %d ",current1->data, current2->data);
            if(root3 == NULL){
                node *newnode = new node;
                newnode->data = current1->data;
                newnode->next = NULL;
                newnode->prev = NULL;

                root3 = newnode;
                tail3 = newnode;
                current3 = newnode;
                current1 = current1->next;
            }
            else{
                node *newnode = new node;
                newnode->data = current1->data;
                newnode->next = NULL;
                newnode->prev = current3;
                current3->next = newnode;

                current3 = newnode;
                tail3 = newnode;
                current1 = current1->next;
            }
            ///printf("root3=%d, tail3=%d, current3 =%d\n",root3->data,tail3->data,current3->data);
        }
        else if(current1->data > current2->data){
            ///printf("list1 =%d > list2 %d. ",current1->data, current2->data);
            if(root3 == NULL){
                node *newnode = new node;
                newnode->data = current2->data;
                newnode->next = NULL;
                newnode->prev = NULL;
                current2 = current2->next;

                root3 = newnode;
                current3 = root3;
                tail3 = newnode;
            }
            else{
                node *newnode = new node;
                newnode->data = current2->data;
                newnode->next = current3->next;
                newnode->prev = current3;
                current3->next = newnode;

                current3 = current3->next;
                current2 = current2->next;
                tail3 = current3;
            }
            ///printf("root3=%d, tail=%d, current3 =%d\n",root3->data,tail3->data,current3->data);
        }
        else if(current1->data == current2->data){
            node *newnode = new node;
            ///printf("list1 =%d = list2 %d ",current1->data, current2->data);
            newnode->data = current1->data;
            newnode->next = current3->next;
            newnode->prev = current3;
            current3->next = newnode;
            current1 = current1->next;
            current3 = current3->next;

            ///printf("root3=%d, tail=%d, current3 =%d\n",root3->data,tail3->data,current3->data);

        }
    }
}

int main()
{
    appendnew(0,1,root);
    appendnew(1,3,root);
    appendnew(2,5,root);
    appendnew(3,7,root);
    appendnew(4,8,root);
    appendnew(5,9,root);
    appendnew(6,11,root);
    printf("first linked list:\n");
    display(root);

    printf("\nsecond linked list:\n");
    appendnew2(0,2,root2);
    appendnew2(1,4,root2);
    appendnew2(2,8,root2);
    appendnew2(2,6,root2);
    appendnew2(4,10,root2);
    display(root2);
    printf("\n");

    concatenate(root, root2);
    printf("merged ");
    display(root3);
    printf("\n");

    appendsort(0);
    appendsort(11);
    appendsort(14);

    printf("after using appendsort, first linked list:\n");
    display(root);

    printf("\nperforming deletion on first ll:-\n");
    delete_node(16);
    delete_node(8);

    printf("\nRemoving duplicate:\n");
    remove_duplicate(root);
    printf("\n");
    display(root);

    printf("\nbefore, root %d, tail %d\n",root->data,tail->data);
    root = reverse_ll(root, tail);
    printf("after, root %d,tail %d\n",root->data,tail->data);

    printf("\nreversed ");
    display(root);

    ///tail->next=root;
    ///printf("root %d, tail %d\n",root->data,tail->data);
    printf("\nany cycle?\n");
    is_loop(root, tail);

    printf("\nsorted?\n");
    if(is_sorted(root)){
        printf("Yes! linked list is sorted.\n");
    }
    else
        printf("No! linked list is not sorted.\n");
}
