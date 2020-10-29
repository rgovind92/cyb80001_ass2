#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

void sum(signed int a, signed int b)
{
    if (((b > 0) && (a > INT_MAX - b)) ||
        ((b < 0) && (a < INT_MIN - b))) {
        printf("Overflow!\n");
        exit(0);
    }

    printf("Sum: %d", a + b);
}

int main()
{
    sum(INT_MAX, 1);
}
