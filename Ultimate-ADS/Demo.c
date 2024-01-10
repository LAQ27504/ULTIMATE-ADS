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


// f(n) = 4-n/2
void iteration_pentagonal(int a[], int size){
    for (int i = 0; i < size; i ++){
        int j = 1;
        while ( ( 3*j*j - j )/2 < a[i] ){
            j ++;
        }
        if ( ( 3*j*j - j )/2 == a[i] ){
            printf("Number %d is pentagonal\n", a[i]);
        }
        else{
            printf("Number %d is not pentagonal\n", a[i]);
        }
    }
}


void recursive_pentagonal(int a[], int index, int n, int size){
    int number = ( 3*n*n - n )/2;
    if (index == size){
        return;
    }
    if (number > a[index]){
        printf("number %d is not pentagonal\n",a[index]);
        recursive_pentagonal(a,index + 1, 1, size);
    }
    else if (number == a[index]){
        printf("Number %d is pentagonal\n", a[index]);
        recursive_pentagonal(a,index + 1, 1, size);
    }
    else{
        recursive_pentagonal(a,index , n + 1, size);
    }
}

//nếu mà đề bài hỏi công thức khác thì chỉ cần thay công thức vô :v

void LL_recursive_pentagonal(LL *mylist, int index, int n, int size){
    int number = ( 3*n*n - n )/2;
    if (index == size){
        return;
    }
    if (number > mylist->head->value){
        printf("number %d is not pentagonal\n",mylist->head->value);
        remove_index(mylist,0);
        LL_recursive_pentagonal(mylist,index + 1, 1, size);
    }
    else if (number == mylist->head->value){
        printf("Number %d is pentagonal\n", mylist->head->value);
        remove_index(mylist,0);
        LL_recursive_pentagonal(mylist,index + 1, 1, size);
    }
    else{
        LL_recursive_pentagonal(mylist,index , n + 1, size);
    }
}

void LL_iteration_pentagonal(LL *mylist, int size){
    for (int i = 0; i < size; i ++){
        int j = 1;
        while ( ( 3*j*j - j )/2 < mylist->head->value ){
            j ++;
        }
        if ( ( 3*j*j - j )/2 == mylist->head->value){
            printf("Number %d is pentagonal\n", mylist->head->value );
            remove_index(mylist, 0);
        }
        else{
            printf("Number %d is not pentagonal\n",mylist->head->value );
            remove_index(mylist, 0);
        }
    }
}

int main(){

    int a[] = {1,2,4,7,5,9,12};
    int size = sizeof(a)/sizeof(a[0]);
    iteration_pentagonal(a,size);

    recursive_pentagonal(a,0,1,size);


    LL *linked_list;
    
    linked_list = initLL(linked_list);
    Add_element(linked_list, 1);
    Add_element(linked_list, 2);
    Add_element(linked_list, 4);
    Add_element(linked_list, 7);
    Add_element(linked_list, 5);
    Add_element(linked_list, 9);
    Add_element(linked_list, 12);
    LL_recursive_pentagonal(linked_list,0 ,1 ,linked_list->size);

    Add_element(linked_list, 1);
    Add_element(linked_list, 2);
    Add_element(linked_list, 4);
    Add_element(linked_list, 7);
    Add_element(linked_list, 5);
    Add_element(linked_list, 9);
    Add_element(linked_list, 12);
    LL_iteration_pentagonal(linked_list, linked_list->size);

}