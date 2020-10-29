#define DIR "/etc"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char **argv)
{
    char cmd[500];
    sprintf(cmd, "ls -l %480s", DIR);
    
    //setuid(0);
    system(cmd);
}
