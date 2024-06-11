/**
 * @file lab_intro.cpp
 * Implementations of image manipulation functions.
 */

#include <iostream>
#include <cmath>
#include <cstdlib>
#include <stdexcept>

#include "cs225/PNG.h"
#include "cs225/HSLAPixel.h"
#include "lab_intro.h"

using cs225::HSLAPixel;
using cs225::PNG;

/**
 * Returns an image that has been transformed to grayscale.
 *
 * The saturation of every pixel is set to 0, removing any color.
 *
 * @return The grayscale image.
 */
PNG grayscale(PNG image) {
  /// This function is already written for you so you can see how to
  /// interact with our PNG class.
  for (unsigned x = 0; x < image.width(); x++) {
    for (unsigned y = 0; y < image.height(); y++) {
      HSLAPixel & pixel = image.getPixel(x, y);

      // `pixel` is a pointer (Um, no it's not... I assume this was just a slip)
      // to the memory stored inside of the PNG `image`,
      // which means you're changing the image directly.  No need to `set`
      // the pixel since you're directly changing the memory of the image.
      pixel.s = 0;
    }
  }

  return image;
}



/**
 * Returns an image with a spotlight centered at (`centerX`, `centerY`).
 *
 * A spotlight adjusts the luminance of a pixel based on the distance the pixel
 * is away from the center by decreasing the luminance by 0.5% per 1 pixel euclidean
 * distance away from the center.
 *
 * For example, a pixel 3 pixels above and 4 pixels to the right of the center
 * is a total of `sqrt((3 * 3) + (4 * 4)) = sqrt(25) = 5` pixels away and
 * its luminance is decreased by 2.5% (0.975x its original value).  At a
 * distance over 160 pixels away, the luminance will always decreased by 80%.
 * 
 * The modified PNG is then returned.
 *
 * @param image A PNG object which holds the image data to be modified.
 * @param centerX The center x coordinate of the crosshair which is to be drawn.
 * @param centerY The center y coordinate of the crosshair which is to be drawn.
 *
 * @return The image with a spotlight.
 */
PNG createSpotlight(PNG image, int centerX, int centerY) {
  double dst;
  for (unsigned x = 0; x < image.width(); x++) {
    for (unsigned y = 0; y < image.height(); y++) {
      HSLAPixel & pixel = image.getPixel(x, y);
      // Compute the distance from spotlight
      dst = sqrt(abs(x - (double)centerX) * abs(x - (double)centerX) + abs(y - (double)centerY) * abs(y - (double)centerY));

      if (dst > 160) {
        pixel.l *= 0.2;
      } else {
        pixel.l = pixel.l * (1 - (dst * 0.005));
      }
    }
  }
  return image;
  
}

/**
 * Returns a image transformed to Illini colors.
 *
 * The hue of every pixel is set to the a hue value of either orange or
 * blue, based on if the pixel's hue value is closer to orange than blue.
 *
 * @param image A PNG object which holds the image data to be modified.
 *
 * @return The illinify'd image.
**/
PNG illinify(PNG image) {
  for (unsigned x = 0; x < image.width(); x++) {
    for (unsigned y = 0; y < image.height(); y++) {
      HSLAPixel & pixel = image.getPixel(x, y);

      double diff_orange = std::min(abs(pixel.h - 11.0), 360 - abs(pixel.h - 11.0));
      double diff_blue = std::min(abs(pixel.h - 216.0), 360 - abs(pixel.h - 216.0));

      if (diff_orange < diff_blue) {
        pixel.h = 11.0; // Set orange
      } else {
        pixel.h = 216.0; // Set blue
      }
    }
  }
  return image;
}

PNG euclidean_illinify(PNG image) {
  // Conversion factor degrees to radians
  const double rad_factor = M_PI / 180.0;
  // Orange (x,y) on unit circle
  const double orange_x = cos(11.0 * rad_factor);
  const double orange_y = sin(11.0 * rad_factor);
  // Blue (x,y) on unit circle
  const double blue_x = cos(216.0 * rad_factor);
  const double blue_y = sin(216.0 * rad_factor);

  for (unsigned x = 0; x < image.width(); x++) {
    for (unsigned y = 0; y < image.height(); y++) {
      HSLAPixel & pixel = image.getPixel(x, y);
      
      // Sort of an obtuse and wasteful approach, but is imperative! 
      // True distance would apply sqrt, but the function is continuous and postive trending
      // So, it's more efficient to take advantage of their proportionality
      double orange_dst = cos(pixel.h * rad_factor) * orange_x + sin(pixel.h * rad_factor) * orange_y;
      double blue_dst = cos(pixel.h * rad_factor) * blue_x + sin(pixel.h * rad_factor) * blue_y;

      // Compute distance as before, but avoid special conditions for negative distances
      if (orange_dst < blue_dst) {
        pixel.h = 11.0; // Set orange
      } else {
        pixel.h = 216.0; // Set blue
      }
    }
  }
  return image;
}
/**
* Returns an immge that has been watermarked by another image.
*
* The luminance of every pixel of the second image is checked, if that
* pixel's luminance is 1 (100%), then the pixel at the same location on
* the first image has its luminance increased by 0.2.
*
* @param firstImage  The first of the two PNGs to be averaged together.
* @param secondImage The second of the two PNGs to be averaged together.
*
* @return The watermarked image.
*/
PNG watermark(PNG firstImage, PNG secondImage) {
  // secondImage = watermark
  // In case of image size mismatch, we could error out, scale, or truncate using max dimensions
  // Will use the last approch

  unsigned max_width = firstImage.width();
  unsigned max_height = firstImage.height();

  if (secondImage.width() > max_width) { max_width = secondImage.width(); }
  if (secondImage.height() > max_height) { max_height = secondImage.height(); }

  for (unsigned x = 0; x < max_width; x++) {
    for (unsigned y = 0; y < max_height; y++) {
      HSLAPixel & ref_pixel = secondImage.getPixel(x, y);
      if (ref_pixel.l != 1.0) {
        continue;
      }
      HSLAPixel & bg_pixel = firstImage.getPixel(x,y);
      bg_pixel.l += 0.2;
      if (bg_pixel.l > 1.0) { bg_pixel.l = 1.0; }
    }
  }
  return firstImage;
}
