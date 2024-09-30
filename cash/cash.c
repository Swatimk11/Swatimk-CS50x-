// 1.prompt the user for input until they enter a non -negative integer.
// 2.convert the user input to cents.
// 3.Intialize variables to count the number of  each coin type (quaters, dimes, nickels,pennies).
// 4.calculate the number of quarters by dividing  the remainig amount by 25.
// 5.Update the remainig amount by subtracting the value of qurters.
// 6.Repeat steps 4-5 for dimes, nickels, and pennies.
// 7.print the total number of each coin type.


#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    int  change;
    do
    {
        change = get_int ("Change owed: ");
    }
    while (change < 0);
    int coins = 0;
    int quarters = change / 25;
    coins += quarters;
    change %= 25;

    int dimes = change / 10;
    coins += dimes;
    change %= 10;

    int nickels = change / 5;
    coins += nickels;
    change %= 5;

    int pennies = change;
    coins += pennies;

    printf("%d\n" , coins);

    return 0;
}
