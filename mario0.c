//Draws one-side stairs for Mario
#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int i, j, k, n;
    //Amount of levels
    do
    {
        n = get_int("Height: ");
    }
    while (n < 0 || n > 23);

    for (i = 1; i <= n; i++)
    {
        //Draws spaces
        for (k = n - i; k > 0; k--)
        {
            printf(" ");
        }
        //Draws hashes
        for (j = 0; j < i + 1; j++)
        {
            printf("#");
        }
        printf("\n");
    }
}
