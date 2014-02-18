#include <stdio.h>


char  *in_name, *out_name;
short **the_image;
long  height, width;
create_image_file(in_name, out_name);
get_image_size(in_name, &height, &width);
the_image = allocate_image_array(height, width);
read_image_array(in_name, the_image);
   //call an image processing routine
write_image_array(out_name, the_image);
free_image_array(the_image, height);