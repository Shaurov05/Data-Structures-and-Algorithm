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

struct Stack{
    int size;
    int top;
    Node **stack_array;
};

void Stackcreate(struct Stack *st,int a){
    st->size = a;
    st->top=-1;
    st->stack_array = (struct Node **)malloc(sizeof(struct Node*));
}

void push(struct Stack *st,struct Node *x){
    if(st->top==st->size-1)
        printf("Stack overflow\n");
    else{
        st->top++;
        st->stack_array[st->top]=x;
    }
}

struct Node *pop(struct Stack *st){
    Node *x = NULL;
    if(st->top==-1)
        printf("Stack Underflow\n");
    else{
        x=st->stack_array[st->top--];
    }
    return x;
}

int isEmptyStack(struct Stack st){
    if(st.top==-1)
        return 1;
    return 0;
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

void IPreOrder(struct Node *curr_node){
    struct Stack stk;
    Stackcreate(&stk,100);
    while(curr_node || !isEmptyStack(stk)){
        if(curr_node){
            ///printf("dhukse %d\n",curr_node->data);
            printf("%d ",curr_node->data);
            push(&stk,curr_node);
            curr_node=curr_node->lchild;
            }
        else{
            curr_node=pop(&stk);
            curr_node=curr_node->rchild;
        }
    }
}

void IInOrder(struct Node *curr_node){
    struct Stack stk;
    Stackcreate(&stk,100);
    while(curr_node || !isEmptyStack(stk)){
        if(curr_node){
            push(&stk,curr_node);
            curr_node=curr_node->lchild;
        }
        else{
            curr_node=pop(&stk);
            printf("%d ",curr_node->data);
            curr_node = curr_node->rchild;
        }
    }
}

void IPostOrder(struct Node *curr_node){
    struct Stack stk;
    long int temp;
    Stackcreate(&stk,100);
    while(curr_node || !isEmptyStack(stk)){

        if(curr_node){
            ///printf("dhukse %d\n",curr_node->data);
            push(&stk, curr_node);
            curr_node = curr_node->lchild;
        }
        else{
            temp = (long int)pop(&stk);
            if(temp > 0){
                push(&stk,(Node *)(-1*temp));
                curr_node = ((Node *)temp)->rchild;
            }
            else{
                printf("%d ", ((Node *)(-1*temp))->data);
                curr_node = NULL;
            }
        }
    }
}

int main()
{
    struct Queue q;
    create_tree();
    printf("\nPre order  : ");
    IPreOrder(root);

    printf("\nIn order   : ");
    IInOrder(root);

    printf("\nPost order : ");
    IPostOrder(root);
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
