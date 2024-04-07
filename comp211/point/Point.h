#ifndef POINT_H
#define POINT_H

struct Point
{
    double x;
    double y;
};

typedef struct Point Point;


/*
 * Instantiates a Point type 
 * Accepts members _x_ and _y_ of double type
 * Returns a pointer to structure on heap or null if 
 * allocation fails.
 */
Point* point_create(double x, double y);

/*
 * Deallocate memory of point _self_
 * Accepts pointer to Point struct type
 */
void point_destroy(Point *self);

/*
 * Write point structure representation to standard out 
 * Accepts pointer to Point struct type 
 */
void point_print(Point *self);

/*
 * Applies an offset to _self_ and returns a pointer
 * to mutated point.
 */
Point* point_offset(Point *self, double x, double y);




#endif