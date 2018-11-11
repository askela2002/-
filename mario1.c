//Draws two-side stairs for Mario
#include <stdio.h>
#include <cs50.h>


int main(void)
{
    int i, j, k, n;
    //Amount of stairs
    do
    {
        n = get_int("Height: ");
    }
    while (n < 0 || n > 23);

    for (i = 1; i <= n; i++)
    {
        for (k = n - i; k > 0; k--)
        {
            printf(" ");
        }
        //Draws hashes
        for (j = 0; j < i; j++)
        {
            printf("#");
        }
        //Two spaces between stairs
        printf("  ");

        for (j = 0; j < i; j++)
        {
            printf("#");
        }
        printf("\n");
    }
}
