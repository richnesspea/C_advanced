#include <stdio.h>

typedef struct {
    int x;
    int y;
}Point;

typedef struct {
    Point center;
    int radius;
}Circle;

int main(){
    Point p1 = {1, 2};
    Circle c1;
    c1.center = p1;
    c1.radius = 3;
    
}