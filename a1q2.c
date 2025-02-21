#include <stdlib.h>
#include <stdio.h>
    
#define BUFSIZE 256
    
// This program prints the size of a specified file in bytes
int main(int argc, char** argv) {
    // Ensure that the user supplied exactly one command line argument
    if (argc != 2) { 
        fprintf(stderr, "Please provide the address of a file as an input.\n");
        return -1;
    }

    // adapted from: https://cplusplus.com/reference/cstdio/ftell/
    // open file
    FILE *fileptr = fopen(argv[1], "rb");
    if (fileptr == NULL) {
        fprintf(stderr, "Failed to open file.\n");
        return -1;
    }

    // seek EOF
    if (fseek(fileptr, 0, SEEK_END) != 0) {
        fprintf(stderr, "Failed to seek EOF.\n");
        fclose(fileptr);
        return -1;
    }

    // read file size
    long filesize = ftell(fileptr);
    if (filesize < 0) {
        fprintf(stderr, "Failed to determine file size.\n");
        fclose(fileptr);
        return -1;
    }

    // keep output consistent with wc -c
    printf("%ld\n", filesize);

    return 0;
}
