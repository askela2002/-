// Cracks the password
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <crypt.h>
#include <cs50.h>

// First and last symbol to use in password

#define FIRST_LETTER 65
#define LAST_LETTER 122


int print_chek_hash(string s, string hash_code);

int main(int argc, string argv[])
{
    char pas[6];
    // Each step increases the lenght of pas (from 1 to 5)
    for (int t = 0; t < 5; t++)
    {
        pas[t] = FIRST_LETTER;
        //Checks if arguments fulfill the conditions and start an algorithm
        if (argc == 2)
        {
            int len = strlen(pas);
            // Simulates the first symbol of password
            for (int i = FIRST_LETTER; i <= LAST_LETTER ; i++)
            {
                // Checks if i is a letter
                if (isalpha(i))
                {
                    // Records i for the first char of password
                    pas[0] = i;
                    print_chek_hash(pas, argv[1]);
                    // Simulates the second symbol of password
                    for (int j = FIRST_LETTER; j <= LAST_LETTER && len >= 2; j++)
                    {
                        if (isalpha(j))
                        {
                            pas[1] = j;
                            print_chek_hash(pas, argv[1]);
                            // Simulates the third symbol of password
                            for (int k = FIRST_LETTER; k <= LAST_LETTER && len >= 3; k++)
                            {
                                if (isalpha(k))
                                {
                                    pas[2] = k;
                                    print_chek_hash(pas, argv[1]);
                                    // Simulates the fourth symbol of password
                                    for (int l = FIRST_LETTER; l <= LAST_LETTER && len >= 4; l++)
                                    {
                                        if (isalpha(l))
                                        {
                                            pas[3] = l;
                                            print_chek_hash(pas, argv[1]);
                                            // Simulates the fifth symbol of password
                                            for (int m = FIRST_LETTER; m <= LAST_LETTER && len == 5; m++)
                                            {
                                                if (isalpha(m))
                                                {
                                                    pas[4] = m;
                                                    print_chek_hash(pas, argv[1]);
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        else
        {
            printf("Usage: ./crack k\n");
            exit(1);
        }
    }
}

// Compares argv[1] and simulated hash
int print_chek_hash(string s, string hash_code)
{
    // Checks if second letter of hash is "0"
    if (hash_code[1] == 48)
    {
        // Checks if the given hash coincides with simulated one
        if (strcmp(crypt(s, "50"), hash_code) == 0)
        {
            printf("\n");
            printf("%s\n", s);
            exit(0);
        }
    }
    else
    {
        if (strcmp(crypt(s, "51"), hash_code) == 0)
        {
            printf("\n");
            printf("%s\n", s);
            exit(0);
        }
    }
    return 0;
}