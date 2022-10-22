#include <stdlib.h>
#include <string.h>

void test_dummy(int argc, char *argv[])
{
    if (argc < 2)
        exit(EXIT_FAILURE);
    else if (strcmp(argv[1], "dummy") == 0)
        exit(EXIT_SUCCESS);
    else 
        exit(EXIT_FAILURE);
}

int main(int argc, char *argv[])
{
    test_dummy(argc, argv);
    return EXIT_SUCCESS;
}