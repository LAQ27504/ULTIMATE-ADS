#include <stdio.h>
#include <stdlib.h>

typedef struct _node{
    int value;
    struct _node *next;
    struct _node *previous;
}Node;

typedef struct _queue{
    int size; 
    Node *front;
    Node *end;
}queue;

Node* init_node(int value){
    Node *new_node = (Node*)malloc(sizeof(Node));
    new_node->next = NULL;
    new_node->previous = NULL;
    new_node->value = value;
    return new_node;
}

queue* init_queue(queue *q){
    q = (queue*)malloc(sizeof(queue));
    q->front = NULL;
    q->end = NULL;
    q->size = 0;
    return q;
} 

int is_empty(queue *q){
    return q->size == 0;
}

void enqueue(queue *q, int value){
    if (is_empty(q)){
        q->end = init_node(value);
        q->front = q->end;
        q->size ++;
        return;
    }   
    Node *new_node = init_node(value);
    new_node->previous = q->end;
    q->end->next = new_node;
    q->end = new_node;
    q->size ++;
}

void dequeue(queue *q){
    Node *new_node = q->front;
    q->front = new_node->next;
    free(new_node);
    q->size --;
}

void display_queue(queue *q){
    Node* now = q->front;
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
    queue *myqueue;
    myqueue = init_queue(myqueue);
    enqueue(myqueue,2);
    enqueue(myqueue,3);
    enqueue(myqueue,4);
    enqueue(myqueue,6);
    enqueue(myqueue,7);
    enqueue(myqueue,1);
    display_queue(myqueue);
    dequeue(myqueue);
    dequeue(myqueue);
    dequeue(myqueue);
    display_queue(myqueue);

}