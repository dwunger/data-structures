/**
 * @file HSLAPixel.h
 *
 * @author CS 225: Data Structures
 * @version 2018r1-lab1
 */

#pragma once

#include <iostream>
#include <sstream>

namespace cs225 {
class HSLAPixel {
    public:
    // Custom constructors
    HSLAPixel();
    HSLAPixel(double hue, double saturation, double luminance);
    HSLAPixel(double hue, double saturation, double luminance, double alpha);

    // Color channels
    double h; // Range: [0,360] Hue
    double s; // Range: [0,1]   Saturation
    double l; // Range: [0,1]   Luminance
    double a; // Range: [0,1]   Alpha
};


}
