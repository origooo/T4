#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#define HEX_OFFSET    1
#define ASCII_OFFSET 51
#define NUM_CHARS    16


void hexdump (char* prog_name, char *filename);
void clear_line (char *line, int size);
char *hex (char *position, int c);
char *ascii (char *position, int c);


int main(int argc, char *argv[]) {
    char *prog_name="hexdump";

    if (argc != 2) {
        printf("\n\t%s syntax:\n\n", argv[0]);
        printf("\t\t%s filename\n\n", argv[0]);
        exit(0);
    }
    hexdump( argv[0], argv[1]);

    return 0;
}


void hexdump(char *prog_name, char *filename) {
    int c=' ';
    char *hex_offset;
    char *ascii_offset;
    FILE *ptr;
    char line[81];

    ptr = fopen(filename,"r");
    if (ferror(ptr)) {
        printf("\n\t%s: Unable to open %s\n\n", prog_name, filename);
        exit(0);
    }

    printf("\n\tHex dump of %s\n\n", filename);

    while (c != EOF) {
        clear_line(line, sizeof line);
        hex_offset   = line+HEX_OFFSET;
        ascii_offset = line+ASCII_OFFSET;

        while (ascii_offset < line+ASCII_OFFSET+NUM_CHARS && (c = fgetc(ptr)) != EOF) {
            /* Build the hex part of
             * the line.      */
            hex_offset = hex(hex_offset, c);

            /* Build the Ascii part of
             * the line.      */
            ascii_offset = ascii(ascii_offset, c);
        }
        printf("%s\n", line);
    }

    fclose(ptr);
}

void clear_line(char *line, int size) {
    int count;
    for  (count=0; count < size; line[count]=' ', count++);
}

char *ascii(char *position, int c) {
    /* If the character is NOT printable
     * replace it with a '.'  */
    if (!isprint(c))
        c='.';

    sprintf(position, "%c", c);    /* Put the character to the line so it can be displayed later */

    /* Return the position of the next ASCII character.   */
    return(++position);
}

char *hex(char *position, int c) {
    int offset=3;
    sprintf(position, "%02X ", (unsigned char) c);

    *(position+offset)=' ';   /* Remove the '/0' created by 'sprint'  */

    return (position+offset);
}