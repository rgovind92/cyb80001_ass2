#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

void sum(signed int si_a, signed int si_b)
{
    signed int sum = si_a + si_b;

    printf("Sum: %d", sum);
}

int main()
{
    sum(INT_MAX, 1);
}
