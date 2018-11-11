//Calculate the amount of coins
#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    int money, cnt = 0;
    //User input for change
    do
    {
        money = round(100 * get_float("Change owed: "));
    }
    while (money < 0);

    //Amount of quarters and reduce money
    while (money / 25 > 0)
    {
        cnt++;
        money -= 25;
    }
    //Adds amount of dimes to amount of quarters and reduce money
    while (money / 10 > 0)
    {
        cnt++;
        money -= 10;
    }

    //Adds amount of nickels to amount of dimes and quarters, and reduce money
    while (money / 5 > 0)
    {
        cnt++;
        money -= 5;
    }
    //Prints number of coins
    printf("The amount of coins are: %i\n", cnt + money);
}