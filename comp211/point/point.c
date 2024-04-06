#include "Guards.h"

Point* point_create(double x, double y) {

    Point* new_point = OOM_GUARD(malloc(sizeof(Point)));    

    new_point -> x = x;
    new_point -> y = y;

    return new_point;
}

void point_destroy(Point *self);

void point_print(Point *self);

Point* point_offset(Point self, double x, double y);

