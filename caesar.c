#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h> // added for strlen ability
#include <stdlib.h> //for atoi


int main(int argc, string argv[])
{
    // check that only 2 arguments are provided (name, key) AND that it only takes digits
    if (argc != 2) // || argc != '\0')
    {
        printf("Usage: ./caesar <key>\n");
        return 1;
    }
// make sure argc (the key) isn't negative, or a letter
    for (int i = 0; argv[1][i] != '\0'; i++)
    {
        if (isalpha(argv[1][i]) != 0)
        {
            printf("Usage: ./caesar <key>\n");
            return 1;
        }
    }

    //convert argv into integer (key)
    int key = atoi(argv[1]);

    //make sure the key is not negative, if so, provide usage detail again
    if (key < 0)
    {
        printf("Usage: ./caesar <key>\n");
        return 1;
    }
    else
    {
        //get the plaintext string from the user
        string plaintext = get_string("plaintext: ");
        int n = strlen(plaintext);
        // needed to print out "ciphertext" otherwise wasn't passing auto tests
        printf("ciphertext: ");
        for (int i = 0; plaintext[i] != '\0'; i++)
            //for (int i = 0; i < n; i++)
            //check if each letter is upper or lower case to preserve cases
            if islower(plaintext[i]) //convert each lowercase letter
            {
                printf("%c", (((plaintext[i] + key) - 'a') % 26) + 'a');
            }
            else if isupper(plaintext[i]) // convert each upper case letter
            {
                printf("%c", (((plaintext[i] + key) - 'A') % 26) + 'A');
            }
            else // to account for numbers & special characters that aren't changing
            {
                printf("%c", plaintext[i]);
            }
    }
    printf("\n");
    return 0;


}




    //prompt for plaintext
    //for each character in plaintext, rotate character if letter
    // if nothing, give error message of 1
    // wrap around letters only, no special characters (i.e., 27 positions means A becomes B, wrap Z --> A)
    //output plaintext:
    //and ciphertext:
    //preserve cases
    //after outpout ciphertext, program should exit and return 0 from main
