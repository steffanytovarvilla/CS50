#include <cs50.h>
#include <stdio.h>

int factorial(int number);

int main (void)
{
    //prompt the user for a number
    int n = get_int ("type a number: ");
    printf("%i\n", factorial(n));
}

int factorial(int number)
{
   if (number == 1)
   {
        return 1;
   }

   return number * factorial(number - 1);
}
