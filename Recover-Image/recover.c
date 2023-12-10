#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

// defining block size
#define BLOCK_SIZE 512

typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
    // Check for correct number of command-line arguments
    if (argc != 2)
    {
        fprintf(stderr, "Usage: %s image\n", argv[0]);
        return 1;
    }

    // opening the file in binary mode read
    FILE *file = fopen(argv[1], "rb");
    if (file == NULL)
    {
        fprintf(stderr, "Could not open forensic image %s for reading.\n", argv[1]);
        return 1;
    }

    BYTE buffer[BLOCK_SIZE];
    int count = 0;
    FILE *output_file = NULL;

    // File Iteration
    while (fread(buffer, sizeof(BYTE), BLOCK_SIZE, file) == BLOCK_SIZE)
    {
        // Check for JPEG signature in the block
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            // If a JPEG signature is found, closing the previous file
            if (output_file != NULL)
            {
                fclose(output_file);
            }

            // Creating new JPEG file

            char filename[8];
            sprintf(filename, "%03d.jpg", count++);
            output_file = fopen(filename, "wb");
            if (output_file == NULL)
            {
                // Not able to create a file
                fclose(file);
                return 1;
            }
        }

        // Write the block to the output file (if it's open)
        if (output_file != NULL)
        {
            fwrite(buffer, sizeof(BYTE), BLOCK_SIZE, output_file);
        }
    }

    // Closing the last output file
    if (output_file != NULL)
    {
        fclose(output_file);
    }

    // Closing the forensic image file
    fclose(file);

    return 0;
}
