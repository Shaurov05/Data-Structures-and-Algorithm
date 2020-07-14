#include<bits/stdc++.h>
using namespace std;

struct Node{
    Node *lchild;
    Node *rchild;
    int data;
};
Node *root = NULL;

struct Queue{
    int size;
    int front;
    int rear;
    Node **node_array;
};

void create(struct Queue *q,int size){
    q->size=size;
    q->front=q->rear=-1;
    q->node_array= new Node*[size];
}

void enqueue(struct Queue *q,struct Node *x){
    if((q->rear+1)%q->size==q->front)
        printf("Queue is Full");
    else
    {
        q->rear=(q->rear+1)%q->size;
        q->node_array[q->rear]=x;
    }
}

struct Node *dequeue(struct Queue *q){
    struct Node *x= NULL;
    if(q->front==q->rear)
        printf("Queue is Empty\n");
    else
    {
        q->front=(q->front+1)%q->size;
        x=q->node_array[q->front];
    }
    return x;
}

void Display(struct Queue q){
    int i;
    for(i=q.front+1;i<=q.rear;i++)
        printf("%d ",q.node_array[i]);
    printf("\n");
}

bool is_Empty(struct Queue q){
    return q.front == q.rear;
}

void create_tree(){
    struct Node *prev_node, *curr_node;
    int value=0;
    struct Queue my_queue;
    create(&my_queue, 100);

    printf("Enter the value of root: ");
    scanf("%d", &value);
    root = new Node;
    root->data = value;
    root->lchild = root->rchild = NULL;
    enqueue(&my_queue, root);

    while(!is_Empty(my_queue)){
        prev_node = dequeue(&my_queue);
        printf("Enter left child of %d : ", prev_node->data);
        scanf("%d",&value);
        if( value!= -1){
            curr_node = new Node;
            curr_node->data = value;
            curr_node->lchild = curr_node->rchild=NULL;
            prev_node->lchild = curr_node;
            enqueue(&my_queue, curr_node);
        }
        printf("Enter right child of %d : ", prev_node->data);
        scanf("%d",&value);
        if( value!= -1){
            curr_node = new Node;
            curr_node->data = value;
            curr_node->lchild = curr_node->rchild=NULL;
            prev_node->rchild = curr_node;
            enqueue(&my_queue, curr_node);
    }}
}

int count(struct Node *root){
    int x=0,y=0;
    if(root){
        x = count(root->lchild);
        y = count(root->rchild);
        return x+y+1;
    }
    else{
        return 0;
    }
}

int height(struct Node *root)
{
    int x=0,y=0;
    if(root==0)
        return 0;
    x=height(root->lchild);
    y=height(root->rchild);

    if(x>y)
        return x+1;
    else
        return y+1;
}

int main()
{
    struct Queue q;
    create_tree();
    printf("Number of leaves  : %d\n",count(root));
    printf("Height of the tree : %d\n", height(root));

    return 0;
}

/**
5
8
6
-1
9
4
-1
3
2
-1
-1
-1
-1
-1
-1
**/
