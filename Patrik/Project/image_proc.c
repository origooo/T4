#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>

#define PIC_NAME "test2.jpg"

uint8_t *load_image(char *filename, unsigned int *width, unsigned int *height) {

	uint8_t *image;
    char buf[512];
    char *bufptr;
    int ret;

    FILE *fp = fopen(filename, "r");
    bufptr = fgets(buf, 512, fp);
    ret = fscanf(fp, "%d %d\n", width, height);
    bufptr = fgets(buf, 512, fp);

    printf("W: %i, H: %i, Ret: %i\n", *width, *height, ret);

    //image = malloc(*width * *height * 4);

    //uint8_t *ptr = image;
    //for (int i = 0; i < *width * *height; ++i) {
    //    ret = fread(ptr, 1, 3, fp);
    //    ptr += 4;
    //}
	//460 × 650

    fclose(fp);
    return image;
}

int main() {

	unsigned int width, height;
	uint8_t *in_image;

	in_image = load_image(PIC_NAME, &width, &height);
	printf("%zu\n", sizeof(in_image));

	return 0;
}