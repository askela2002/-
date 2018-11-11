//Checks a card and gives a type of a card
#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    long long int cc;
    int sum = 0;

    //User inputs number of card
    do
    {
        cc = get_long_long("Type a number of your card: ");
        //cc = 378282246310005; //Amex
        //cc = 4149649193093166; //Visa-16
        //cc = 4147629395083; //Visa-13
        //cc = 5169110000922313; //Mastercard
    }
    while (cc <= 0);

    for (int i = 1; i <= 8; i++)
    {
        int x = (cc % (long int)pow(10, 2 * i) - cc % (long int)pow(10, 2 * i - 1)) / pow(10, 2 * i - 1);
        if (2 * x > 9)
        {
            sum += (2 * x) % 10 + 1;
        }
        else
        {
            sum += 2 * x;
        }
    }

    for (int i = 1; i <= 8; i++)
    {
        int y = (cc % (long int)pow(10, 2 * i - 1) - cc % (long int)pow(10, 2 * i - 2)) / pow(10, 2 * i - 2);
        sum += y;
    }

    //for Amex
    int type1 = cc / (long int)pow(10, 13);
    //for Mastercard
    int type2 = cc / (long int)pow(10, 14);
    //for Visa
    int type3 = cc / (long int)pow(10, 15);
    int type4 = cc / (long int)pow(10, 12);

    if ((type1 == 37 || type1 == 34) && sum % 10 == 0)
    {
        printf("AMEX\n");
    }
    else if (type2 >= 51 && type2 <= 55 && sum % 10 == 0)
    {
        printf("MASTERCARD\n");
    }

    else if ((type3 == 4 || type4 == 4) && sum % 10 == 0)
    {
        printf("VISA\n");
    }
    else
    {
        printf("INVALID\n");
    }
}