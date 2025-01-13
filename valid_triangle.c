#include <cs50.h>
#include <stdio.h>

bool valid_triangle (float x, float y, float z);

int main (void)
{

float x = get_float ("Give me a first lengh: ");
float y = get_float ("Give me a second lenght: ");
float z = get_float ("Give me a third lenght: ");

if (x <= 0 || y <= 0 || z <= 0)
{
    printf("False\n");
}

if ((x + y <= z) || (y + z <= x) || (z + x <= y))
{
    printf("False\n") ;
}

else

printf("True\n");

}
