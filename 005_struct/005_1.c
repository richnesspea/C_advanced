#include <stdio.h>
//Static array of structs

typedef struct {
    int x;
    int y;
} Point;


int main(){
    //Creating a "static array of points"
    Point pointsArray[5];

    for (int i = 0; i < 5; i++){
        printf("Enter the #%d 'x' coordinate: \n", i);
        scanf("%d", &pointsArray[i].x);
        printf("Enter the #%d 'y' coordinate: \n", i);
        scanf("%d", &pointsArray[i].y);
    }

    for (int i = 0; i < 5; i++){
        printf("The #%d 'x' coordinate: ", i);
        printf("%d \n", pointsArray[i].x);
        printf("The #%d 'y' coordinate: ", i);
        printf("%d \n", pointsArray[i].y);
    }
    
}