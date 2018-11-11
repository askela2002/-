//Encripts, using vigenere cript
#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

bool check_input(int x, string s);

int main(int argc, string argv[])
{
    //Checks if argv[1] fulfills the conditions
    if (check_input(argc, argv[1]))
    {
        printf("Usage: ./vigenere k\n");
        exit(1);
    }
    // Main part
    else
    {
        string text = get_string("plaintext: ");
        int l = strlen(argv[1]);
        printf("ciphertext: ");
        for (int i = 0, j = 0, n = strlen(text); i < n; i++, j++)
        {
            if (isalpha(text[i]))
            {
                // Transforms sum of symbols to number from 65 to 90
                int new_symb = (toupper(text[i]) + toupper(argv[1][j % l])) % 26 + 65;
                // If letter was capital just print it
                if (isupper(text[i]))
                {
                    printf("%c", new_symb);
                }
                // If letter was small, return small
                else
                {
                    printf("%c", tolower(new_symb));
                }
            }
            else
            {
                printf("%c", text[i]);
                j--;
            }
        }
        printf("\n");
    }
}

// Checks an input from user
bool check_input(int x, string s)
{
    if (x != 2)
    {
        return true;
    }
    else
    {
        for (int j = 0, n = strlen(s); j < n; j++)
        {
            if (!(isalpha(s[j])))
            {
                return true;
            }
        }
    }
    return false;
}