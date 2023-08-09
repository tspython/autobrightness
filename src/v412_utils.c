#include "v4l2_utils.h"

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <linux/videodev2.h>

int v4l2_init(const char *dev_path, int width, int height) {
    // Open device
    int fd = open(dev_path, O_RDWR);
    if (fd == -1) {
        perror("Failed to open device");
        return -1;
    }

    // Set format
    struct v4l2_format fmt = {0};
    fmt.type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
    fmt.fmt.pix.width = width;
    fmt.fmt.pix.height = height;
    fmt.fmt.pix.pixelformat = V4L2_PIX_FMT_RGB24;
    ioctl(fd, VIDIOC_S_FMT, &fmt);

    return fd;
}

unsigned char *v4l2_capture_frame(int fd) {
    return NULL;
}

void v4l2_close(int fd) {
    close(fd);
}

