#include <stdio.h>

#define black 0
#define white 255
#define dark 128 

int main(void)
{
    FILE *in = fopen("hypatia.bmp", "r");
    FILE *out = fopen("bw.bmp", "w+");

    int i;
    unsigned char byte[54];
    unsigned char colortable[1024];

    if(in==NULL)
    {
        printf("This file doesn't exist.\n");
    }

    for(i = 0; i < 54; i++)
    {
        byte[i]=getc(in);
    }

    fwrite(byte,sizeof(unsigned char), 54, out);

    int height = *(int*)&byte[18];
    int width = *(int*)&byte[22];
    int bitDepth = *(int*)&byte[28];

    printf("width %d\n", width);
    printf("height %d\n", height);
    int size=height*width;

    if(bitDepth <= 8)
    {
        fread(colortable, sizeof(unsigned char), 1024, in);
        fwrite(colortable, sizeof(unsigned char), 1024, out);
    }

    unsigned char buffer[size];

    fread(buffer, sizeof(unsigned char), size, in);

    for(i = 0; i < size; i++)
    {
        buffer[i] = (buffer[i] > dark) ? white : black;
    }

    fwrite(buffer, sizeof(unsigned char), size, out);

    fclose(in);
    fclose(out);

    return 0;
}