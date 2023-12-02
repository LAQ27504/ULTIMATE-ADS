#include <stdio.h>

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}


void Insertion_sort_iteration(int array[], int size){
    for (int i = 1; i < size; i ++){
        if (array[i - 1] > array[i]){
            int j = i;
            int temp = array[i];
            while (j > 0 && array[j - 1] > array[j]){
                swap(&array[j - 1], &array[j]);
                j --;
            }
            array[j] = temp;
        }
        
    }
}

void Insertion_sort_recursion(int array[], int size, int index1){
    if (index1 == size){
        return;
    }
    int index2 = index1;
    int temp = array[index1];
    while (index2 > 0 && array[index2 - 1] > array[index2]){
        swap(&array[index2 - 1], &array[index2]);
        index2 --;
    }
    array[index2] = temp;

    Insertion_sort_recursion(array, size, index1 + 1);
}

void display_array(int array[], int size){
    for (int i = 0; i < size; i ++){
        printf("%d ", array[i]);
    }
    printf("\n");
}


int main(){
    int array[] = {1,6,2,87,1,74,2,8};
    int array_size = sizeof(array)/sizeof(array[0]);
    Insertion_sort_iteration(array, array_size);
    display_array(array, array_size);
    int array2[] = {1,6,2,87,1,74,2,8};
    Insertion_sort_recursion(array2, array_size, 0);
    display_array(array2, array_size);
}