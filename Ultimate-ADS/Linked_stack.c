#include <stdio.h>
#include <stdlib.h>

typedef struct _node{
    int value;
    struct _node *next;
}Node;

typedef struct _stack{
    int size;
    Node *top;
}stack;

Node* init_node(int value){
    Node *new_node = (Node*)malloc(sizeof(Node));
    new_node->value = value;
    new_node->next = NULL;
    return new_node;
}

stack* init_stack(){
    stack *s = (stack*)malloc(sizeof(stack));
    s->top = NULL;
    s->size = 0;
    return s;
}

int is_empty(stack *s){
    return s->size == 0;
}

void push(stack *s, int value){
    if(is_empty(s)){
        s->top = init_node(value);
        s->size ++;
        return;
    }
    Node *new_node = init_node(value);
    Node *temp = s->top;
    new_node->next = temp;
    s->top = new_node;
    s->size++
    return;
}

void pop(stack *s){
    if(is_empty(s)){
        return;
    }
    Node *temp = s->top;
    s->top = temp->next;
    free(temp);
    s->size --;
    return;
}

void display_stack(stack *s){
    Node* now = s->top;
    Node* temp = now->next;
    while (temp != NULL){
        printf("%d ", now->value);
        now = temp;
        temp = now->next;
    }   
    printf("%d \n", now->value);
    return;
}

int main(){
    stack *mystack;
    mystack = init_stack();
    push(mystack, 3);
    push(mystack, 2);
    push(mystack, 4);
    push(mystack, 8);
    display_stack(mystack);
    pop(mystack);
    display_stack(mystack);
}