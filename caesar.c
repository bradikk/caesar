#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

bool digits(string text);
char cipher(char p, int k);

int main(int argc, string argv[1])
{
    // Establish string -> int variable
    int convert, length;
    string plaintext;
    // Check if there are '2' arguments & if a digit
    if (argc != 2 || !digits(argv[1]))
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    // Convert string to int
    convert = atoi(argv[1]);
    // Prompt user to enter plain text
    plaintext = get_string("plaintext: ");
    // Establish size of directory - same as plaintext!
    length = strlen(plaintext);
    // Create cipher text directory & +1 to include terminator
    char ciphertext[length + 1];
    // Loop through the entire plaintext and rotate them
    for (int i = 0; i < length; i++)
    {
        ciphertext[i] = cipher(plaintext[i], convert);
    }
    ciphertext[length] = '\0';
    // Print cipher text
    printf("ciphertext: %s\n", ciphertext);
    return 0;
}

// Check if the key is a digit
bool digits(string text)
{
    int length;

    length = strlen(text);

    for (int i = 0; i < length; i++)
    {
        if (!isdigit(text[i]))
        {
            return false;
        }
    }
    return true;
}
// Encipher aka rotate letters
char cipher(char p, int k)
{
    char pi, c, ci;
    if (isupper(p))
    {
        // Subtract 65 to get ASCII position of char
        pi = p - 65;
        ci = (pi + k) % 26;
        // Add 65 to get the new ASCII position of char
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