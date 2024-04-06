#include <stdio.h>
#include <stdlib.h>
#include "Guards.h"

Point* point_create(double x, double y) {

    Point* new_point = OOM_GUARD(malloc(sizeof(Point)));    

    new_point -> x = x;
    new_point -> y = y;

    return new_point;
}

void point_destroy(Point *self) {
    if (self != NULL) {
        free(self);
    } else {
        fprintf(stderr, "Cannot dellocate memory at address %p\n", self);
    }
}

void point_print(Point *self) {
    if (self != NULL) {
        printf("Point = {%f, %f}", (*self).x, (*self).y);
    } else {
        fprintf(stderr, "Cannot print point at address: %p\n", self);
    }
}

Point* point_offset(Point *self, double x, double y) {
    if (self == NULL) {
        fprintf(stderr, "point_offset received pointer to null\n");
        return;
    }  

    //(*self).x += x;
    self -> x += x;

    //(*self).y += y;
    self -> y += y;    
}
