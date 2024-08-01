#include "monty.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void execute_instruction(char *line, unsigned int line_number, stack_t **stack)
{
    char *opcode, *arg;
    int n;
    instruction_t instructions[] = {
        {"pall", pall},
        {"pint", pint},
        {"pop", pop},
        {"swap", swap},
        {"add", add},
        {"nop", nop},
        {NULL, NULL}};

    opcode = strtok(line, " \t\n");
    if (!opcode || opcode[0] == '#')
        return;

    if (strcmp(opcode, "push") == 0)
    {
        arg = strtok(NULL, " \t\n");
        if (!arg || !is_number(arg))
        {
            fprintf(stderr, "L%d: usage: push integer\n", line_number);
            exit(EXIT_FAILURE);
        }
        n = atoi(arg);
        push(stack, line_number, n);
        return;
    }

    for (int i = 0; instructions[i].opcode; i++)
    {
        if (strcmp(opcode, instructions[i].opcode) == 0)
        {
            instructions[i].f(stack, line_number);
            return;
        }
    }

    fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
    exit(EXIT_FAILURE);
}

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
    if (!file)
    {
        fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    while ((read = getline(&line, &len, file)) != -1)
    {
        line_number++;
        execute_instruction(line, line_number, &stack);
    }

    free(line);
    fclose(file);
    free_stack(stack);
    return 0;
}
