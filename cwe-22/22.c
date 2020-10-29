#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv)
{
    FILE *fp;

    if (argc == 3) {
        if (!(fp = fopen(argv[1], "w"))) {
            printf("Error opening file!\n");
            exit(0);
        }

        if (!fwrite(argv[2], 1, strlen(argv[2]), fp)) {
            printf("Error writing to file!\n");
            exit(0);
        }

        fclose(fp);
    }
}
