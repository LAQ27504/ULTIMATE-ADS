#include <stdio.h>

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void display_array(int array[], int size){
    for (int i = 0; i < size; i ++){
        printf("%d ", array[i]);
    }
    printf("\n");
}

int partition (int array[], int low, int high){
    
    int pivot = array[low];
    int i = high;
    for (int j = high; j > low; j --){
        if (array[j] > pivot){
            swap(&array[j], &array[i]);
            i--;  
        }
    }
    swap(&array[i], &array[low]);
    return i;
}

void Quick_sort(int array[], int low, int high){
    if (low < high){
        int p = partition(array, low, high);
        Quick_sort(array, low, p - 1);
        Quick_sort(array, p + 1, high);
    }
}



int main(){
    int array[] = {1,6,2,87,1,74,2,1};
    int array_size = sizeof(array)/sizeof(array[0]);
    Quick_sort(array, 0, array_size - 1);
    display_array(array, array_size);
}