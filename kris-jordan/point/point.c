#include <stdio.h>
#include <stdlib.h>
    
struct Point {
    double x;
    double y;
};
typedef struct Point Point;

void Point_print(const Point *self, const char *name);

Point add(Point p1, Point p2);

int main(void) {

    Point a = { 1.0, 2.0 };
    Point b = { 3.0, 4.0 };
    
    Point c = add(a,b);
    
    Point_print(&a,"a"); 
    Point_print(&b,"b"); 
    Point_print(&c,"c"); 
    
    return 0;
}

void Point_print(const Point *self, const char *name) {
    printf("Point %s = { %f , %f };\n",
            name, (*self).x, (*self).y);
}

Point add(Point p1, Point p2) {
    p1.x += p2.x; //p3.x = p1.x + p2.x;
    p1.y += p2.y; //p3.y = p1.y + p2.y;
    return p1;
}
