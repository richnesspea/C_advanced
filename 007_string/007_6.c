//Counting voweles and consonants
//Counting words
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define SIZE 100

void createString(char **arr, int size){
    char *arrPtr;
    arrPtr = (char *)malloc(size * sizeof(char));
    if (arrPtr == NULL) { // Kiểm tra malloc có thành công không
        printf("Memory allocation failed\n");
        exit(1); 
    }
    printf("Enter the string (max %d characters): \n", size - 1);
    fgets(arrPtr, size, stdin);  // Sử dụng fgets để nhập chuỗi với kích thước lớn hơn
    *arr = arrPtr;
}

void displayString(char *arr){
    printf("The entered string is: %s\n", arr);
}

void vowelConsonents(char *arr, int *vow, int *cons){
    int i; 
    int vcount = 0, ccount = 0;
    for(i = 0; arr[i] != '\0'; i++){
        if(arr[i] == 'u'||arr[i] == 'e' || arr[i] == 'o' || arr[i] == 'a' || arr[i] == 'i' || 
           arr[i] == 'U' || arr[i] == 'E' || arr[i] == 'O' || arr[i] == 'A' || arr[i] == 'I'){
            vcount++;
        }
        else if ((arr[i] >= 'A' && arr[i] <= 'Z') || (arr[i] >= 'a' && arr[i] <= 'z')){
            ccount++;
        }
    }
    *vow = vcount;
    *cons = ccount;
}

void countWords(char *arr, int *numWord){
    int i;
    int word = 0;
    for(i = 0; arr[i] != '\0'; i++){
        if ((arr[i] == ' ' || arr[i] == '\n' || arr[i] == '\t') && 
            (i > 0 && arr[i-1] != ' ' && arr[i-1] != '\n' && arr[i-1] != '\t')){
            word++;
        }
    }
    // Nếu chuỗi không rỗng và không chỉ có dấu cách, thì từ đầu tiên chưa được đếm
    //if (strlen(arr) > 0 && arr[0] != ' ') word++;
    
    *numWord = word;
}

int main(){
    char* str;
    int vow = 0, cons = 0, word = 0;

    createString(&str, SIZE);
    displayString(str);

    vowelConsonents(str, &vow, &cons);
    printf("The number of vowels in the string is: %d\n", vow);
    printf("The number of consonants in the string is: %d\n", cons);

    countWords(str, &word);
    printf("The number of words in the string is: %d\n", word);

    free(str); // Giải phóng bộ nhớ sau khi sử dụng xong
    return 0;
}
