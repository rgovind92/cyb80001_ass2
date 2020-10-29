#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define CMD "/bin/cat "

int main(int argc, char** argv)
{   
    char cmd[] = "/bin/cat ";
    
    if (argc > 1) {
        strcat(cmd, argv[1]);
        system(cmd);
    }
}
