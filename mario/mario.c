// 1.Prompt the user for input until a valid integer (n) between 0 and 8 is entered.
//  2.for each row i from 0 to n-1:
// a. Print (n-1-i) spaces.
//  b. Print (i+1) "#" charaters.
// c. Move to the next line.

// converting  this pseudocode into c code
#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int n;
    do
    {
        n = get_int("Height:");
    }
    while (n < 0 || n > 8);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - 1 - i; j++)
        {
            printf(" ");
        }

        for (int k = 0; k < i + 1; k++)
        {
            printf("#");
        }
        printf("\n");
    }
    return 0;
}






