#include<bits/stdc++.h>
using namespace std;

struct Stack{
    int capacity;
    int top;
    int *arr;
};

void create(struct Stack *store){
    printf("Please enter the size: ");
    scanf("%d",&store->capacity);
    store->top = -1;
    store->arr = new int[store->capacity];
}

void push(struct Stack *store, int data){
    if(store->top == store->capacity-1)
        printf("stack overflow\n");
    else{
        store->top++;
        store->arr[store->top] = data;
        ///printf("%d ", store->arr[store->top]);
    }
}

void display(struct Stack *store){
    if(store->top != -1)
    {
        for(int i = store->top ; i>=0 ; i--){
        printf("%d ",store->arr[i]);
    }}
    printf("\n");
}

int pop(struct Stack *store){
    if(store->top == -1)
        printf("stack underflow\n");
    else{
        return store->arr[store->top--];
    }
}

void peek(struct Stack *store, int position){
    int x = store->top-position+1;
    if(x < 0){
        printf("invalid position\n");
        return;}
    else
    printf("in position =%d, data is :%d\n",position,store->arr[x]);
}

bool is_emptyS(struct Stack store){
    if(store.top == -1){
        printf("Stack is empty\n");
        return true;
    }
    else{
        printf("Stack is not empty\n");
        return false;
    }
}

void is_full(struct Stack store){
    if(store.top > store.capacity)
        printf("Stack is full\n");
    else
        printf("Stack is not full\n");
}

void stackTop(struct Stack store){
    if(!is_emptyS(store)){
        printf("Top of the stack is : %d\n", store.arr[store.top]);
    }
}

int main()
{
    struct Stack store;
    create(&store);

    push(&store,1);\
    push(&store,2);
    push(&store,3);
    push(&store,4);

    stackTop(store);

    display(&store);

    peek(&store,3);

    int data = pop(&store);
    printf("poped data = %d\n", data);

    data = pop(&store);
    printf("poped data = %d\n", data);

    is_emptyS(store);
    is_full(store);

    display(&store);
}
