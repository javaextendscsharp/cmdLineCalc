#include <stdio.h>

int main(int argc, char const *argv[])
{
    int n = 50;
    int *p = &n;
    printf("%d and %p\n", n, p);
    return 0;
}
