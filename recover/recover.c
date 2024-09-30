#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage : ./recover infile\n");
        return 1;
    }
    FILE *rawFile = fopen(argv[1], "r");
    if (rawFile == NULL)
    {
        printf("Couldn't open input file\n");
        return 1;
    }

    BYTE buffer[512];
    FILE *outFile = NULL;
    unsigned int jpegCounter = 0;
    char filename[8];
    while (fread(buffer, sizeof(BYTE) * 512, 1, rawFile))
    {
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            if (outFile != NULL)
                fclose(outFile);
            sprintf(filename, "%03d.jpg", jpegCounter++);
            outFile = fopen(filename, "w");
        }
        if (outFile != NULL)
            fwrite(buffer, sizeof(BYTE) * 512, 1, outFile);
    }
    if (outFile != NULL)
        fclose(outFile);
    fclose(rawFile);
    return 0;
}
