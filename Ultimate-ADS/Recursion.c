#include <stdio.h>

//Đề sẽ cho công thức theo dạng 
// f(x) = công thức nào đó với f(x - 1) công thức nào đó thêm với f(x - 2) ...
//Viết function theo dạng iteration + pseduo code 
//Chuyển sang dạng recursive function
//Example
//cho 1 array để check từng số trong array có phải số pentagonal không
//số pentagonal là:
// f(n) = (3*n^2 - n)/2          ( f(2) = (3*2^2 - 2)/2 = 5 => 5 là số pentagonal )

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

//nếu mà đề bài hỏi công thức khác thì chỉ cần thay công thức vô :v

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



int main(){
    int a[] = {1,2,4,7,5,9,12};
    int size = sizeof(a)/sizeof(a[0]);
    iteration_pentagonal(a,size);

    recursive_pentagonal(a,0,1,size);
}