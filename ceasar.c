#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

bool only_digits(string s);
char rotate(char c, int n);

int main(int argc, string argv[])
{
    //Ensure program was run with just one command-line argument and contains only digit characters
    if (argc != 2 || !only_digits(argv[1]))
    {
        // Prompt user to type in key or a digit
        printf("Usage: ./caesar key\n");
        return 1;
    }

    // Convert argument into an integer
    int k = atoi(argv[1]);

    //get plaintext from the user
    string plaintext = get_string("Plaintext:  ");

    int length = strlen(plaintext);
    char ciphertext[length + 1];
    for (int i = 0; i < length; i++)
    {
        ciphertext[i] = rotate(plaintext[i], k);
    }
    ciphertext[length] = '\0';

    //Print Ciphertext
    printf("Ciphertext: %s\n", ciphertext);
    return 0;
}

//Function checks if command line arguments is a digit or a number
bool only_digits(string s)
{
    int length;
    length = strlen(s);
    for (int i = 0; i < length; i++)
    {
        if (isdigit(s[i]))
        {
            return true;
        }
    }
    return 0;
}

//Function to encipher plaintext characters
char rotate(char p, int k)
{
    char pi, c, ci;
    if (isupper(p))
    {
        pi = p - 65;
        ci = (pi + k) % 26;
        c = ci + 65;
    }
    else if (islower(p))
    {
        pi = p - 97;
        ci = (pi + k) % 26;
        c = ci + 97;
    }
    else
    {
        return p;
    }
    return c;
}

