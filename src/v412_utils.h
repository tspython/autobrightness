#ifndef V4L2_UTILS_H
#define V4L2_UTILS_H

int v4l2_init(const char *dev_path, int width, int height);
unsigned char *v4l2_capture_frame(int fd);
void v4l2_close(int fd);

#endif 

