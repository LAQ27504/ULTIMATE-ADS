#include <stdio.h>

typedef struct _List{
    int size;
    int data[100];
}List;

void init_list(List *l){
    l->size = 0;
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
    List mylist;
    init_list(&mylist);
    Add_element(&mylist, 2);
    Add_element(&mylist, 3);
    Add_element(&mylist, 7);
    Add_element(&mylist, 6);
    display_list(&mylist);
    Insert_element(&mylist, 3, 2);
    display_list(&mylist);
    Remove_a_value(&mylist, 7);
    display_list(&mylist);
    remove_index(&mylist, 0);
    display_list(&mylist);
}