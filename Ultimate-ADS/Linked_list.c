#include <stdio.h>
#include <stdlib.h>

typedef struct _node {
    int value;
    struct _node* next;
} Node;

typedef struct linked_list {
    int size;
    Node* head;
} LL;

Node* initNode(int value){
    Node *a = (Node*)malloc(sizeof(*a));
    a->value = value;
    a->next = NULL;
    return a;
}

LL* initLL(LL *l){
    l = (LL*)malloc(sizeof(LL));
    l->size = 0;
    l->head = NULL;
    return l;
}

int isEmpty(LL *l){
    return l->size == 0;
}

void Add_element(LL *l, int value){
    if (isEmpty(l)){
        l->head = initNode(value);
        l->size ++;
        return;
    }
    Node* now = l->head;
    Node* temp = now->next;
    while (temp != NULL){
        now = temp; 
        temp = now->next;
    }
    now->next = initNode(value);
    l->size ++;
}

void Insert_element(LL *l, int value, int index){
    Node *now = l->head;
    if (index == 0){
        Node *new_node = initNode(value);
        new_node->next = now;
        l->head = new_node;
        return;
    }
    for (int i = 1; i < index; i ++){
        now = now->next;
    }
    Node *new_node = initNode(value);
    new_node->next = now->next;
    now->next = new_node;
    l->size ++;
}

void Remove_a_value(LL *l, int value){
    if (isEmpty(l)){
        printf("List empty\n");
        return;
    }
    Node *now = l->head;
    Node *temp = now->next;
    while (temp->next != NULL){
        if (temp->value == value){
            break;
        }
        now = temp;
        temp = now->next;
    }
    now->next = temp->next;
    free(temp);
    l->size --;
}

void remove_index(LL *l, int index){
    if (isEmpty(l)){
        printf("List empty\n");
        return;
    }
    if (index == 0){
        Node *now = l->head;
        l->head = now->next;
        free(now);
        l->size --;
        return;
    }
    Node *now = l->head;
    Node *temp = now->next;
    for (int i = 0; i < index - 1; i ++ ){
        now = temp; 
        temp = now->next;
    }
    now->next = temp->next;
    free(temp);
    l->size --;
}

void displaylinked_list(LL *l){
    Node* now = l->head;
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
    LL *mylist;
    mylist = initLL(mylist);
    Add_element(mylist, 2);
    Add_element(mylist, 4);
    Add_element(mylist, 3);
    Add_element(mylist, 6);
    displaylinked_list(mylist);

    remove_index(mylist, 0);
    displaylinked_list(mylist);
}