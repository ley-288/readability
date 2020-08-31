#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

int main(void)
{
    string s = get_string("Text: ");                                                        //Input from user. Text (s = our string here).
    int num_words, num_sentences, num_letters;                                              //Integers we need for the function list. Words, Secnteces, Letter count.
    num_words = num_sentences = num_letters = 0;                                            //Set these values to 0 by default.
    for (int i = 0, len = strlen(s); i < len; i++)                                          //Calc/Assign integer 'i' =0, length of word (use strlen to calc. word length)
    {                                                                                       //Take integer as less than length value, interger + 1.
        if (isalpha(s[i]))                                                                  //Use isalpha to determine letter case.
           num_letters++;                                                                   //Number of letter + 1.
        if ((i == 0 && s[i] != ' ') || (i != len - 1 && s[i] == ' ' && s[i + 1] != ' '))    //Int starts 0 and if next string[*] not equal to space, or next int not equal
           num_words++;                                                                     //to the length -1 AND int same as SPACE AND SPACE is int+1 NOT equal to space.
        if (s[i] == '.' || s[i] == '?' || s[i] == '!')                                      //if string/int equal to punctuation. sentence value + 1.
           num_sentences++;
    }
    float L = (num_letters / (float) num_words) * 100;                                      //Percentages. Use float to apply decimal number. below 100. Divide by 100.
    float S = (num_sentences / (float) num_words) * 100;                                    //Same. Sentence = sentence / words.
    int index = round(0.0588 * L - 0.296 * S - 15.8);                                       //Coleman-Liau index formula. need Integer and ROUND to recieve rounded no.
    if (index < 1)                                                                          //Application.
       printf("Before Grade 1\n");                                                          //If index below 1. Grade is before 1.
    else if (index >= 16)                                                                   //If index is equal to or greater than 16. Grade 16+.
       printf("Grade 16+\n");
    else
       printf("Grade %i\n", index);                                                         //Anything else, print Integer. ie Index number.

}