#include<bits/stdc++.h>
using namespace std;

struct Stack{
    int length;
    int top;
    char *operatr;
};

void push(struct Stack *store, char data){
    store->top++;
    store->operatr[store->top] = data;
    ///printf("%d ", store->postfix[store->top]);
}

int pop(struct Stack *store){
    return store->operatr[store->top--];
}

bool is_operand(char ch){
    if(ch == '(' || ch == '*' || ch == '/' || ch == '+' || ch == '-' ||
       ch == '&' || ch == '|' || ch == '!' || ch == '$' || ch == ')' )
        return false;
    else
        return true;
}

bool is_emptyS(struct Stack store){
    if(store.top == -1)
        return true;
    else
        return false;
}

int precedence(char ch){
    if(ch == '$')
        return 5;
    else if(ch == '*' || ch == '/')
        return 4;
    else if(ch == '+' || ch == '-')
        return 3;
    else if(ch == '&' || ch == '|')
        return 2;
    else if(ch == '!')
        return 1;
    else
        return 0;
}

void display(struct Stack *store){
    if(store->top != -1)
    {
        for(int i = store->top ; i>=0 ; i--){
        printf("%c ",store->operatr[i]);
    }}
    printf("\n");
}

void create_postfix(string infix,int len){
    int j=0, i=0,k=0;
    struct Stack my_post;
    my_post.top = -1;
    my_post.length = len;
    my_post.operatr = new char[100];
    char *postfix = new char[my_post.length];

    while(i<my_post.length){
        if(infix[i] == ' '){
            i++; continue;
        }
        else if(is_operand(infix[i])){
            postfix[j++] = infix[i++];
        }
        else if(infix[i]=='(' || precedence(infix[i]) >
               precedence(my_post.operatr[my_post.top])){
            push(&my_post, infix[i++]);
        }
        else if(infix[i]==')'){
               while(my_post.operatr[my_post.top]!='(') {
                postfix[j++] = pop(&my_post);
                }
                pop(&my_post);  i++;
            }
        else{
            while(precedence(infix[i]) <=
                    precedence(my_post.operatr[my_post.top])){
                postfix[j++] = pop(&my_post);
            }
            push(&my_post,infix[i++]);
        }
    }
    printf("POSTFIX => %c", postfix[0]);

    for(i=1 ; i<j;i++){
        printf(" %c", postfix[i]);
    }
    while(!is_emptyS(my_post)){
        printf(" %c",pop(&my_post));
    }
    printf("\n");
}

string create_infix(string prefix){
    int j=0, i=0 ,k=0;
    stack <string> my_post2;

    int length2 = prefix.size();
    i = length2-1;
    string result;

    while(i >= 0){
        if(prefix[i] == ' '){
            i--;
            continue;
        }
        if(is_operand(prefix[i])){
            my_post2.push(string(1,prefix[i]));
        }
        else if(!is_operand(prefix[i])){
                string left = my_post2.top(); my_post2.pop();
                string right = my_post2.top(); my_post2.pop();
                result = "(" + left + prefix[i] + right + ")";
                my_post2.push(result);
        }
    i--;}
    return result;
}

int main()
{
    string prefix1,infix,infix1;
    getline(cin,infix);
    getline(cin,prefix1);

    printf("INFIX   => ");
    cout << infix<<endl;
    printf("PREFIX  => ");
    cout<< prefix1<<endl;

    infix1 = create_infix(prefix1);
    create_postfix(infix1, infix1.size());
}
