#include <stdio.h>

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void selection_sort_iteration(int array[], int size){
    for (int i = 0 ; i < size; i ++ ){
        int min = i;
        for (int j = i; j < size; j ++){
            if (array[j] < array[min]){
                min = j;
            }
        }
        swap(&array[i], &array[min]);
    }
}

void selection_sort_recursion(int array[], int index1, int index2, int size, int min){
    if (index1 == size){
        return;
    }
    if (index2 == size){
        swap(&array[index1], &array[min]);
        selection_sort_recursion(array, index1 + 1, index1 + 1 , size, index1 + 1);
        return;
    }
    if (array[index2] < array[min]){
        selection_sort_recursion(array, index1, index2 + 1, size, index2);
        return;
    }
    selection_sort_recursion(array, index1, index2 + 1, size, min);
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
    selection_sort_iteration(array, array_size);
    display_array(array, array_size);
    int array2[] = {1,6,2,87,1,74,2,8};
    selection_sort_recursion(array2, 0, 0, array_size, 0);
    display_array(array2, array_size);
}