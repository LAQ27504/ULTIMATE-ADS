#include <stdio.h>

typedef struct _queue{
    int front;
    int end;
    int data[1000];
}queue;

void init_queue(queue * q){
    q->front = 0; 
    q->end = 0;
}

int is_empty(queue *q){
    return q->end - q->front == 0;
}

int is_full(queue *q){
    return q->end - q->front == 100;
}

void enqueue(queue *q, int value){
    q->data[q->end] = value;
    q->end ++;
}

void dequeue(queue *q){
    q->front ++;
}

void display_queue(queue *q){
    for ( int i = q->front; i < q->end; i ++ ){
        printf("%d ", q->data[i]);
    }
    printf("\n");
}
int main(){
    queue myqueue;
    init_queue(&myqueue);
    enqueue(&myqueue, 7);
    enqueue(&myqueue, 3);
    enqueue(&myqueue, 6);
    enqueue(&myqueue, 2);
    enqueue(&myqueue, 1);
    display_queue(&myqueue);
    dequeue(&myqueue);
    dequeue(&myqueue);
    display_queue(&myqueue);
}