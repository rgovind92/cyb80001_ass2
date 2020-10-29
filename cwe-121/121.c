#include <string.h>
#define BUFSIZE 8

int main(int argc, char **argv) {
  char buf[BUFSIZE];
  strcpy(buf, argv[1]);
}
