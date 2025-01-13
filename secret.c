#include <cs50.h>
#include <stdio.h>
#include <string.h>

bool check_phrase(string);

int main(void)

{
    string phrase = get_string("What`s the secret phrase?");

    bool correct = check_phrase(phrase);

         if (strcmp(phrase, password) == 0)
        {
             printf("Come on in!\n");
        }
}

