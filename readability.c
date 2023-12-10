#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

// Determining which text is suitable for which Grade Students according to Coleman-Liau's formula

int count_letters(string text, char letters[]);
int count_words(string text);
int count_sentences(string text);
// Letter's of Alphabet in order
char LETTERS[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm',
                  'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

int main(void)
{
    string text = get_string("Text: ");
    // printf("Text: %s\n", text);

    int lcount = count_letters(text, LETTERS);
    // printf("%d letters\n", lcount);

    int wcount = count_words(text);
    // printf("%d words\n", wcount);

    int scount = count_sentences(text);
    // printf("%d sentences\n", scount);

    float L = (float) lcount / wcount * 100;
    float S = (float) scount / wcount * 100;

    float grade = 0.0588 * L - 0.296 * S - 15.8;

    // Rounding the grades and priting the result
    int rounded_grade = (int) round(grade);
    if (rounded_grade < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (rounded_grade >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %d\n", rounded_grade);
    }
}

int count_letters(string text, char letters[])
{
    int text_length = strlen(text);
    int alpha_length = strlen(letters);
    int count = 0;
    for (int i = 0; i < text_length; i++)
    {
        // checking for Capital Letters and changing in small letters
        if (isupper(text[i]))
        {
            text[i] = tolower(text[i]);
        }
        for (int a = 0; a < alpha_length; a++)
        {
            if (text[i] == letters[a])
            {
                count++;
            }
        }
    }
    return count;
}

int count_words(string text)
{
    // starting with one because space+1 = n(words)
    int word_count = 1;
    char space = ' ';
    int text_length = strlen(text);
    for (int i = 0; i < text_length; i++)
    {
        if (space == text[i])
        {
            word_count++;
        }
    }
    return word_count;
}

int count_sentences(string text)
{
    // Checking different criteria's for text being a sentence
    char pd = '.';
    char el = '!';
    char qm = '?';

    int sentence_count = 0;
    int text_length = strlen(text);
    for (int i = 0; i < text_length; i++)
    {
        if (pd == text[i])
        {
            sentence_count++;
        }
        else if (el == text[i])
        {
            sentence_count++;
        }
        else if (qm == text[i])
        {
            sentence_count++;
        }
    }
    return sentence_count;
}
