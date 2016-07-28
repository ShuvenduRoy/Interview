#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *file;
    file=freopen("output.txt","w",stdout);
    printf("Hello world!\n");
    return 0;
}
