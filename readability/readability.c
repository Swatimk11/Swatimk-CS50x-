#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    // Get text from user
    string text = get_string("Text: ");

    // Initialize counters
    int letterCount = 0;
    int wordCount = 0;
    int sentenceCount = 0;

    // Calculate the length of the text
    int textLength = strlen(text);

    // Count letters, words, and sentences
    for (int index = 0; index < textLength; index++)
    {
        if (isalpha(text[index]))
        {
            letterCount++;
        }
        else if (isspace(text[index]))
        {
            wordCount++;
        }
        else if (text[index] == '.' || text[index] == '!' || text[index] == '?')
        {
            sentenceCount++;
        }
    }

    // Account for last word and sentence
    wordCount++;
    sentenceCount++;

    // Calculate L and S
    float L = ((float) letterCount / (float) wordCount) * 100.0;
    float S = ((float) sentenceCount / (float) wordCount) * 100.0;

    // Coleman-Liau index formula
    float index = 0.0588 * L - 0.296 * S - 15.8;

    // Round to nearest integer
    int grade = (int) round(index + 0.5);

    // Output grade level
    if (grade < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (grade >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %d\n", grade);
    }
}
