#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>  // Se añade para poder utilizar la función free

char* replace(const char* input);

int main(int argc, char* argv[])
{
    if(argc != 2)
    {
        printf("wrong command-line argument\n");
        return 1;
    }

    const char* word = argv[1];
    char* result = replace(word);

    printf("%s\n", result);
    free(result);  // Libera la memoria asignada en la función replace
    return 0;
}

char* replace(const char* input)
{
    int length = strlen(input);
    char* output = malloc(length + 1);  // +1 para el carácter nulo al final

    for(int i = 0; i < length; i++)
    {
        char c = tolower(input[i]);

        switch (c)
        {
            case 'a':  // Se corrigen las comillas
                output[i] = '6';
                break;

            case 'e':
                output[i] = '3';
                break;

            case 'i':
                output[i] = '1';
                break;

            case 'o':
                output[i] = '0';
                break;

            default:
                output[i] = c;
                break;
        }
    }
    output[length] = '\0';  // Asegura que la cadena termina con el carácter nulo
    return output;
}
