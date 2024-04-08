#include <stdio.h>
#include <stdlib.h>

#include "Guards.h"
#include "Point.h"


int main(int argc, char *argv[])
{
    // Create a point struct instance
    Point* boston_coords = point_create(0,0);

    // Display point instance representing Boston as a point
    point_print(boston_coords);

    // Create a second point as an offset
    Point* point_offset = point_create(128.256, 512.1024);
    
    // Offset the first point using point offset instance
    point_offset(boston_coords, offset->x, offset->y);

    // Display the updated coordinates
    point_print(boston_coords);

    // Free memory
    point_destroy(boston_coords);
    point_destroy(point_offset);

    return 0;

}