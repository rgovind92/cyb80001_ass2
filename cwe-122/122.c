#include <string.h>
#include <stdlib.h>

#define BUFSIZE 8

int main(int argc, char **argv) {
  char *buf;
  buf = (char *) malloc(sizeof(char)*BUFSIZE);
  strcpy(buf, argv[1]);
}
