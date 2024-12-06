#include <stdio.h>

#define black 0
#define white 255
#define dark 128 

int main(void)
{
    FILE *input = fopen("hyptia", "r");
    FILE *output = fopen("bw.bmp", "bw");

    int i;
    unsigned char byte[54];
    unsigned char colortable[1024];

    if(input==NULL)
    {
        printf("This file doesn't exist.\n")
    }

    for(i=0; i<54; i++)
    {
        byte[i]=getc(input);
    }

    fwrite(byte,sizeof(unsigned char), 54, output);

    
}