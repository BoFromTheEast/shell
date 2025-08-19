#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv)
{

    shellLoop();
}

void shellLoop(void)
{
    char *line;
    char **args;
    int loopStatus;

    do
    {
        printf("> ");
        line = shell_readline();
        args = shell_splitline(line);
        loopStatus = shell_execute(args);

        free(line);
        free(args);
    } while (loopStatus);
}

char *shell_readline(void)
{
    int bufferSize = 1024;
    int position = 0;
    char *buffer = malloc(sizeof(char) * bufferSize);
    int c;

    if (!buffer)
    {
        fprintf(stderr, "Buffer allocation failed");
        exit(EXIT_FAILURE);
    }

    while (1)
    {

        c = getchar();

        if (c == EOF || c == "\n")
        {
            buffer[position] = '\0';
        }
        else
        {
            buffer[position] = c;
        }
        position++;

        if (position >= bufferSize)
        {
            bufferSize += bufferSize;
            realloc(buffer, bufferSize);
            if (!buffer)
            {
                fprintf(stderr, "Buffer allocation failed");
                exit(EXIT_FAILURE);
            }
        }
    }
}

char **shell_splitline(char **line)
{
    int bufferSize = 64, position = 0;
    char **tokens = malloc(sizeof(char *) * bufferSize);
    char *token;

    if (!tokens)
    {
        fprintf(stderr, "Allocation error");
        exit(EXIT_FAILURE);
    }

    token = strtok(line, " \t\r\n\a");

    while (token != NULL)
    {
        tokens[position] = token;
        position++;

        if (position >= bufferSize)
        {
            bufferSize += bufferSize;
            realloc(tokens, bufferSize * sizeof(char *));

            if (!tokens)
            {
                fprintf(stderr, "Allocation error");
                exit(EXIT_FAILURE);
            }
        }
        token = strtok(NULL, " \t\r\n\a");
    }
    tokens[position] = NULL;
    return tokens;
}

int shell_execute(char ***args)
{
}
