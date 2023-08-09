#ifndef IMAGE_UTILS_H
#define IMAGE_UTILS_H

int calculate_brightness(const unsigned char *image_data, int width, int height);
int apply_weighting(int brightness);
void adjust_screen_brightness(int weighted_brightness);

#endif

