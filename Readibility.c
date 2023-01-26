#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);


//with all my comments as I tried to work through it

int main(void)
{
    //prompt user for text input:
    string text = get_string("Text: ");
    //printf("the text is %s\n", text);
    int letters = count_letters(text);
    int words = count_words(text);
    int sentences = count_sentences(text);
    //printf("\n%i letters\n", letters);
    //printf("%i words \n", words);
    //printf("%i sentences\n", sentences);
    //return text

    //int grade = 0;

    // take average letters/sentences per 100 words
    float L = (100 / ((float) words) * (float) letters);
    //printf("\n%f\n", L); //to test what the calculation comes back with
    float S = (100 / ((float) words) * (float) sentences);
    //printf("%f\n", S);


/** this didn't work, and I'm still trying to figure out why..
    float L = 100 * (letters / words);
    printf("\n%f\n", L);
    float S = 100 * (sentences / words);
    printf("%f\n", S);
**/


    //User coleman-liau index - index = 0.0588 * L - 0.296 * S - 15.8

    int index = round(0.0588 * L - 0.296 * S - 15.8);

    //Print grade levels
    if (index > 16)
    {
        printf("\nGrade 16+\n");
    }
    else if (index < 1)
    {
        printf("\nBefore Grade 1\n");
    }
    else
    {
        printf("\nGrade %i\n", index);
    }

}

int count_letters(string text)
{
    //using isalpha() and changing the string to char allows you to just count alphabetical (ignoring spaces, #s, special characters)
    //int letters = 0;
    float letters = 0;
    for (int i = 0; text[i]; i++)
    {
        if (isalpha((unsigned char)text[i]))
        {
            putchar (text[i]);
            letters++;
        }
    }
    return letters;
}

int count_words(string text)
{
    //initialized to one to account for the first word, which doesn't have a space before it to start to trigger the count
    //int words = 1;
    float words = 1;
    //int i;
    for (int i = 0; i < strlen(text); i++)
    {
        if (text[i] == ' ' && text[i+1] != 0)
        {
            words++;
        }
    }
    return words;
}

int count_sentences(string text)
{
    //int sentences = 0;
    float sentences = 0;
    //int i;
    for (int i = 0; i <strlen(text); i++)
    {
        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            sentences++;
        }
    }
    return sentences;
}


/**

index = 0.0588 * L - 0.296 * S - 15.8
L = # of letters per 100 words -- 65/14 * 100 = 464.29
S = # of sentences per 100 words -- 4/14 * 100 = 28.57

# of letters / # of words

Need to count:
# of words
# of letters
# of sentences

Then calculate grade level and print the grade level

**/

