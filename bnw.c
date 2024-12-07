#include <stdio.h>
#include <stdlib.h>

#define black 0
#define white 255
#define dark 128 

int main(void)
{
    FILE *in = fopen("hypatia.bmp", "r");
    FILE *out = fopen("bnw.bmp", "w");
    if(!in || !out)
    {
        printf("This file doesn't exist.\n");
        return 101;
    }

    unsigned char header [54];
    fread(header, 1, 54, in);
    fwrite(header, 1, 54, out);

    int height = *(int *)&header[22];
    int width = *(int *)&header[18];
    int bitDepth = *(int *)&header[28];
    int size = height * width;
    unsigned char *buffer = (unsigned char *)malloc(size);
    fread(buffer, 1, size, in);

    for (int i = 0; i < size; i++)
    {
        buffer[i] = (buffer[i] > dark) ? white : black;
    }

    fwrite(buffer, 1, size, out);

    fclose(in);
    fclose(out);
    free(buffer);
    return 0;
}