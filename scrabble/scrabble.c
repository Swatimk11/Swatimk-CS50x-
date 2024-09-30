#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int calculateScore(char *word)
{
    int score = 0;
    for (int i = 0; i < strlen(word); i++)
    {
        switch (toupper(word[i]))
        {
            case 'A':
            case 'E':
            case 'I':
            case 'L':
            case 'N':
            case 'O':
            case 'R':
            case 'S':
            case 'T':
            case 'U':
                score += 1;
                break;
            case 'D':
            case 'G':
                score += 2;
                break;
            case 'B':
            case 'C':
            case 'M':
            case 'P':
                score += 3;
                break;
            case 'F':
            case 'H':
            case 'V':
            case 'W':
            case 'Y':
                score += 4;
                break;
            case 'K':
                score += 5;
                break;
            case 'J':
            case 'X':
                score += 8;
                break;
            case 'Q':
            case 'Z':
                score += 10;
                break;
        }
    }
    return score;
}
int main()
{
    char word1[100], word2[100];
    printf("Player 1, enter your word:");
    scanf("%s", word1);
    printf("Player 2, enter your word:");
    scanf("%s", word2);
    int score1 = calculateScore(word1);
    int score2 = calculateScore(word2);
    if (score1 > score2)
    {
        printf("Player 1 wins!\n");
    }
    else if (score2 > score1)
    {
        printf("Player 2 wins !\n");
    }
    else
    {
        printf("Tie!\n");
    }
    return 0;
}
