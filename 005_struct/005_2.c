#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int x;
    int y;
}Point;

int main(){
    Point *pointsArr;
    int totalPoints;
    printf("Enter the number of points: \n");
    scanf("%d", &totalPoints);

    pointsArr = (Point *)malloc(sizeof(Point)*totalPoints);
    for(int i = 0; i < totalPoints; i++){
        printf("Enter the #%d 'x' coordinate: \n", i);
        scanf("%d", &pointsArr[i].x);
        printf("Enter the #%d 'y' coordinate: \n", i);
        scanf("%d", &pointsArr[i].y);
    }

    for (int i = 0; i < totalPoints; i++){
        printf("The #%d 'x' coordinate: ", i);
        printf("%d \n", pointsArr[i].x);
        printf("The #%d 'y' coordinate: ", i);
        printf("%d \n", pointsArr[i].y);
    }
}