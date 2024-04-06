#ifndef POINT_H
#define POINT_H
/*
Instructions:
1. Starting with the `Point` structure and related functions from the lecture, modify 
    `point.h` and `point.c` to include:
   - A `point_create` function that allocates a new `Point` on the heap and initializes it with given 
        `x` and `y` values.
   - A `point_destroy` function that frees the memory allocated for a `Point`.

2. Update the `point_offset` function to use a "self" parameter for the `Point` being modified.
*/

struct Point
{
    double x;
    double y;
};

typedef struct Point Point;

Point* point_create(double x, double y);

void point_destroy(Point *self);

void point_print(Point *self);
/*
Returns address to mutated point structure for inline manipluation
*/
Point* point_offset(Point self, double x, double y);




#endif