#include <stdio.h>
#include <stdlib.h>

typedef struct _List{
    int size;
    int capacity;
    int *data;
}List;

List* init_list(List *l, int N){
    l = (List*)malloc(sizeof(List));
    l->size = 0;
    l->capacity = N;
    l->data = (int*)malloc(l->capacity);
    return l;
}

int is_empty(List *l){
    return l->size == 0;
}

int is_full(List *l){
    return l->size == 100;
}

void Add_element(List *l, int value){
    l->data[l->size] = value;
    l->size ++;
}

void Insert_element(List *l, int value, int index){
    for (int i = l->size; i > index; i --){
        l->data[i] = l->data[i - 1];
    }
    l->data[index] = value;
    l->size ++;
}
void Remove_a_value(List *l, int value){
    if (is_empty(l)){
        printf("List empty\n");
        return;
    }
    for (int i = 0; i < l->size; i ++){
        if (l->data[i] == value){
            for (int j = i; j < l->size; j ++){
                l->data[j] = l->data[j + 1];
            }
            l->size --;
            return;
        }
    }
}

void remove_index(List *l, int index){
    if (is_empty(l)){
        printf("List empty\n");
        return;
    }
    for (int i = index; i < l->size; i ++){
        l->data[i] = l->data[i + 1];
    }
    l->size --;
    return;
}

void display_list(List *l){
    for (int i = 0; i < l->size; i ++){
        printf("%d ",l->data[i]);
    }
    printf("\n");
}

int main(){
    List *mylist;
    mylist = init_list(mylist,100);
    Add_element(mylist, 2);
    Add_element(mylist, 3);
    Add_element(mylist, 7);
    Add_element(mylist, 6);
    display_list(mylist);
    Insert_element(mylist, 3, 2);
    display_list(mylist);
    Remove_a_value(mylist, 7);
    display_list(mylist);
    remove_index(mylist, 0);
    display_list(mylist);
}