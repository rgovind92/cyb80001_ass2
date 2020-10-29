#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pwd.h>
#include <unistd.h>

int verify_file(char *file);

int main(int argc, char **argv)
{
    FILE *fp;
    char *absolute_path;

    if (argc == 3) {
        absolute_path = realpath(argv[1], NULL);

        if (!absolute_path) {
            printf("Error accessing file\n");
            exit(0);
        }

        if (verify_file(absolute_path)) {
            if (!(fp = fopen(absolute_path, "w"))) {
                printf("Error opening file!\n");
                free(absolute_path);
                exit(0);
            }

            if (!fwrite(argv[2], 1, strlen(argv[2]), fp)) {
                printf("Error writing to file!\n");
                free(absolute_path);
                exit(0);
            }

            printf("Written successfully!\n");

            fclose(fp);
        }
        else
            printf("That file cannot be accessed!\n");

        free(absolute_path);
    }
}

int verify_file(char *const filename) {
    /* Get /etc/passwd entry for current user */
    struct passwd *pwd = getpwuid(getuid());
    if (pwd == NULL) {
        /* Handle error */
        return 0;
    }
 
    const size_t len = strlen(pwd->pw_dir);
    if (strncmp(filename, pwd->pw_dir, len) != 0) {
        return 0;
    }
    /* Make sure there is a '/' immediately after */
    if (filename[len] == '/') {
        return 1;
    }
    return 0;
}
