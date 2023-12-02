#include <stdio.h>

typedef struct _stack{
    int top;
    int data[100];
}stack;

void init_stack(stack *s){
    s->top = -1;
}

int is_empty(stack *s){
    return s->top == -1;
}

void push(stack *s, int value){
    s->top++;
    s->data[s->top] = value;
}

void pop(stack *s){
    s->top --;
}

void display_stack(stack *s){
    for ( int i = 0; i <= s->top; i ++ ){
        printf("%d ", s->data[i]);
    }
    printf("\n");
}
int main(){
    stack mystack;
    init_stack(&mystack);
    push(&mystack, 2);
    push(&mystack, 3);
    push(&mystack, 6);
    push(&mystack, 4);
    display_stack(&mystack);
    pop(&mystack);
    pop(&mystack);
    display_stack(&mystack);`3
}