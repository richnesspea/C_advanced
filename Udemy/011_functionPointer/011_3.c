//Project: Pizza making 
/*
1. Why we need function pointers, why we dont use separate functions.
    * Pizza is composed of dough, saucea and cheese
    * 3 types of dough, 4 of sauce and 5 of cheese => 60 different combinations 
2. 
    * have different functions for making dough, sauce and cheese. 
    * one funciton for making pizza, using function pointers. 
*/
#include <stdio.h>

// Step 1: Define functions for each Pizza element
// Dough making fucntions:

void thinCrust(){
    printf("Making thin crust \n");
}

void thickCrust(){
    printf("Making thick crust \n");
}

// Source making functions:

void tomatoSauce(){
    printf("Adding tomato sauce \n");
}

void pestoSauce(){
    printf("Adding pesto sauce \n");
}

// Cheese making functions:

void mozzarellaCheese(){
    printf("Adding mozzarella cheese \n");
}

void cheddarCheese(){
    printf("Adding cheddar cheese \n");
}

// Step 2: Create the pizza function

// Pizza creation process

void createPizza(void (*makeDough)(void), void (*makeSauce)(void), void (*addCheese)(void)){
    //makeDough là con trỏ để gọi đến hàm mình sẽ sử dụng
    //hàm con mình tạo, ví dụ như thinCrust không có parameter vào và cũng ko có trả về kết quả gì nên input parameter và return đều là void
    
    makeDough();
    makeSauce();
    addCheese();  
}

int main(){
    printf("Pizza 1: \n");
    createPizza(thinCrust, tomatoSauce, mozzarellaCheese);
}