#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <linux/fb.h>
#include <sys/mman.h>
#include "framebuffer_info.h"

int getDisplayInfo() {

    int fbfd = 0;
    struct fb_var_screeninfo vinfo;
    struct fb_fix_screeninfo finfo;
    long int screensize = 0;
    char *fbp = 0;
    int x = 0, y = 0,i;
    long int location = 0;

    /* Open the file for reading and writing */
    fbfd = open("/dev/fb0", O_RDWR);
    if (fbfd < 0) {
        printf("Error: cannot open framebuffer device.\n");
        return -1;
    }
    printf("The framebuffer device was opened successfully.\n");

    /* Get fixed screen information */
    if (ioctl(fbfd, FBIOGET_FSCREENINFO, &finfo)) {
        printf("Error reading fixed information.\n");
        return -1;
    }

    /* Get variable screen information */
    if (ioctl(fbfd, FBIOGET_VSCREENINFO, &vinfo)) {
        printf("Error reading variable information.\n");
        return -1;
    }

    printf ("The mem is %d\n", finfo.smem_len);
    printf("The line_length is :%d\n",finfo.line_length);
    printf("The xres is :%d\n",vinfo.xres);
    printf("The yres is :%d\n",vinfo.yres);
    printf("bits_per_pixel is :%d\n",vinfo.bits_per_pixel);

    close(fbfd);
    return 0;
}
