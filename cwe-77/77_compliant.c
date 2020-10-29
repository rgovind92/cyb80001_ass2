#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define CMD "/bin/cat"

void sanitize(char *text);

int main(int argc, char** argv)
{   
    if (argc > 1) {
        sanitize(argv[1]);
    
        execl(CMD, CMD, argv[1], NULL);
    }
}

void sanitize(char *text)
{
  static char ok_chars[] = "abcdefghijklmnopqrstuvwxyz"
                           "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
                           "1234567890_-.@";
  char *cp = text;
  const char *end = text + strlen(text);
  
  for (cp += strspn(cp, ok_chars); cp != end; cp += strspn(cp, ok_chars))
      *cp = '_';
}
