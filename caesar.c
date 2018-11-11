//Encripts, using caesar cript
#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    //wrong amount of arguments
    if (argc != 2)
    {
        printf("Usage: ./caesar k\n");
        exit(1);
    }

    else
    {
        string plaintext = get_string("plaintext: ");
        printf("ciphertext: ");
        for (int i = 0; i < strlen(plaintext); i++)
        {
            //Checks if character is a letter
            if (isalpha(plaintext[i]))
            {
                int new_key = plaintext[i] + atoi(argv[1]) % 26;
                //Checks if a new character is a letter
                if (isalpha(new_key))
                {
                    printf("%c", new_key);
                }
                //Returns a letter
                else
                {
                    printf("%c", new_key - 26);
                }
            }
            //Returns a character, which is not a letter
            else
            {
                printf("%c", plaintext[i]);
            }
        }
        printf("\n");
    }
}