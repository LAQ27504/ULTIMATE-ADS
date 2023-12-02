#include <stdio.h>

int Binary_search_iteration(int array[], int size, int x){
    int low = 0;
    int high = size;
    while(low <= high){
        int mid = (low + high)/2;
        if (x > array[mid]){
            low = mid + 1;
        }
        else if (x < array[mid]){
            high = mid - 1;
        }
        else{
            return mid;
        }
    }
    return low;
}

int Binary_search_recursion(int array[], int low, int high, int x){
    int mid = (low + high)/2;
    if (low > high){
        return low;
    }
    if (x > array[mid]){
        return Binary_search_recursion(array, mid + 1, high, x);
    }
    else if (x < array[mid]){
        return Binary_search_recursion(array, low, mid - 1, x);
    }
    else{
        return mid;
    }
}

int main(){
    int array[] = {1,5,7,10,15,37,50};
    int array_size = sizeof(array)/sizeof(array[0]);
    printf("%d ", Binary_search_iteration(array, array_size - 1, 41));
    printf("%d ", Binary_search_recursion(array, 0, array_size - 1, 41));
}