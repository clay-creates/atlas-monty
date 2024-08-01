#include "monty.h"

int main(int argc, char *argv[])
{
    FILE *file;
    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    stack_t *stack = NULL;
    unsigned int line_number = 0;

    if (argc != 2)
    {
        fprintf(stderr, "USAGE: monty file\n");
        exit(EXIT_FAILURE);
    }

    file = fopen(argv[1], "r");
    if (!line)
    {
        fprintf(stderr, "Error: Can't open file %s\n, argv[1]");
        exit(EXIT_FAILURE);
    }

    free(line);
    fclose(file);
    free_stack(stack);
    return (0);
}