#include <stdio.h>
#include <stdlib.h>
#include "v4l2_utils.h"
#include "image_utils.h"

int main() {
    int fd = v4l2_init("/dev/video0", 640, 480);
    if (fd < 0) {
        perror("Failed to open webcam");
        return 1;
    }

    while (1) {
        unsigned char *frame = v4l2_capture_frame(fd);

        int brightness = calculate_brightness(frame, 640, 480);

        int weightedBrightness = apply_weighting(brightness);
        adjust_screen_brightness(weightedBrightness);

        free(frame);
    }

    v4l2_close(fd);

    return 0;
}

