#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>


int calc_index(char *text, int length);

int main(void)
{
    char *text = get_string("Text: ");
    int text_length = strlen(text);
    int index = calc_index(text, text_length);
    if (index < 0)
    {
        printf("Before Grade 1\n");
    }
    else if (index < 16)
    {
        printf("Grade %d\n", index);
    }
    else
    {
        printf("Grade 16+\n");
    }
}

int calc_index(char *text, int length)
{
    float index, letters = 0.0, words = 1.0, sentences = 0.0;
    for (int i = 0; i < length; i++)
    {
        if (text[i] == ' ')
        {
            words++;
        }
        else if (text[i] == '.' || text[i] == '?' || text[i] == '!')
        {
            sentences++;
        }
        else if (isalpha(text[i]))
        {
            letters++;
        }
    }

    // calculating the Coleman-Liau index of a text
    index = 5.88 * letters / words - 29.6 * sentences / words - 15.8;
    return round(index);
}
