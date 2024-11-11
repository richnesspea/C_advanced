#include<stdio.h>

//https://www.youtube.com/watch?v=xli_FI7CuzA Tutorial for bubble sort
//https://www.youtube.com/watch?v=4VqmGXwpLqc&list=PL9xmBV_5YoZOZSbGAXAPIq1BeUf4j20pl Tutorial for some sorting algorithms

void bubbleSort(int *arr, int size){
    for(int i = 0; i < size - 1; i++){         //sau mỗi vòng lặp thì tại vị trí cao nhất sẽ được sắp xếp 
        for(int j = 0; j < size - i - 1; j++){ //Nên là j sẽ không cần lặp đến vị trí size - 1 - i nữa
            if(arr[j] > arr[j + 1]){
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp; 
            }
        }
    }
}