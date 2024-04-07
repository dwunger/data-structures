#include <stdio.h>
#include "Guards.h"

Point* point_create(double x, double y) {

    Point* new_point = OOM_GUARD(malloc(sizeof(Point)));    

    new_point -> x = x;
    new_point -> y = y;

    return new_point;
}

void point_destroy(Point *self) {
    if (self == NULL) {
        fprintf(stderr, "point_destroy received a null pointer, cannot free memory\n");
    } else {
        free(self);
    }
}

void point_print(Point *self) {
    if (self == NULL) {
        fprintf(stderr, "point_print received a pointer to null\n");
    } else {
        printf("Point = { %f, %f }\n", self -> x, self -> y);
    }
}

Point* point_offset(Point *self, double x, double y) {
  if (self == NULL) {
        fprintf(stderr, "point_offset received a pointer to null\n");
        exit(1);
    } else {
        (*self).x += x;
        (*self).y += y;
    }
    return self;
}
