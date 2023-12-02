#include <stdio.h>

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void merge(int array[], int low, int mid, int high){
    int subarray1 = mid - low + 1;
    int subarray2 = high - mid;
    int S1[subarray1], S2[subarray2];
    for (int i = 0; i < subarray1; i ++){
        S1[i] = array[low + i];
    }
    for (int i = 0; i < subarray2; i ++){
        S2[i] = array[mid + 1 + i];
    }
    int i = 0;
    int j = 0;
    int k = low;
    while (i < subarray1 && j < subarray2){
        if (S1[i] <= S2[j]){
            array[k] = S1[i];
            i ++;
        }
        else{
            array[k] = S2[j];
            j ++;
        }
        k++;
    }
    while (i < subarray1){
        array[k] = S1[i];
        i++;
        k++;
    }

    while (j < subarray2){
        array[k] = S2[j];
        j++;
        k++;
    }
}

void Merge_sort(int array[], int low, int high){
    if (low < high){
        int mid = (low + high) / 2;

        Merge_sort(array, low, mid);
        Merge_sort(array, mid + 1, high);
        merge(array, low, mid, high);
    }
    
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
    Merge_sort(array, 0, array_size - 1);
    display_array(array, array_size);
}