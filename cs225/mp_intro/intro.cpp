#include "cs225/PNG.h"
#include "cs225/HSLAPixel.h"

#include <string>

void rotate(std::string inputFile, std::string outputFile) {
  // Read in reference image
  cs225::PNG input_png = cs225::PNG();
  input_png.readFromFile(inputFile);
  // Save the input image's dimensions
  unsigned width, height;
  width = input_png.width();
  height = input_png.height();
  // Create a blank canvas
  cs225::PNG rotated_png(width, height);

  for (unsigned x = 0; x < width; x++) {
    for (unsigned y = 0; y < height; y++) {
      cs225::HSLAPixel & ref_pixel = input_png.getPixel(x,y);
      cs225::HSLAPixel & rot_pixel = rotated_png.getPixel(width - x - 1, height - y - 1);
    
      rot_pixel.a = ref_pixel.a;
      rot_pixel.h = ref_pixel.h;
      rot_pixel.l = ref_pixel.l;
      rot_pixel.s = ref_pixel.s;
    }
  }

  // Write processed image to disk
  rotated_png.writeToFile(outputFile); 
}

cs225::PNG myArt(unsigned int width, unsigned int height) {
  cs225::PNG png(width, height);
  // TODO: Part 3

  return png;
}
