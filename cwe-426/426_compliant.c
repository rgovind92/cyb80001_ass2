#define DIR "/etc"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char **argv)
{
    char *pathbuf;
    size_t n;
 
    if (clearenv() != 0) {
        return -1;
    }
 
    n = confstr(_CS_PATH, NULL, 0);
    if (n == 0) {
        return -1;
    }
 
    if ((pathbuf = malloc(n)) == NULL) {
        /* Handle error */
    }
 
    if (confstr(_CS_PATH, pathbuf, n) == 0) {
        /* Handle error */
    }
 
    if (setenv("PATH", pathbuf, 1) == -1) {
        /* Handle error */
    }
 
    if (setenv("IFS", " \t\n", 1) == -1) {
        /* Handle error */
    }    

    char cmd[500];
    sprintf(cmd, "ls -l %480s", DIR);
    
    //setuid(0);
    system(cmd);
}
