#ifndef POINT_H
#define POINT_H

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
Point* point_offset(Point *self, double x, double y);




#endif