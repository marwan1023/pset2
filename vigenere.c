#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <cs50.h>

// Vigenere`s cipher is an improvement of Caesar`s cipher by encrypting messages using a sequence of keys or by a keyword.
// When starting the program the user is entering the keyword that will be used for encryption and
// then he is prompted to provide the text that he wants to be encrypted
bool is_valid_k(string k)
{
    for (int i = 0; i < strlen(k); i++)
    {
        if (!isalpha(k[i]))
        {
            return false;
        }
    }

    return true;
}

int main(int argc, string args[])
{
    if (argc != 2 || !is_valid_k(args[1]))
    {
        printf("Usage: ./vigenere k\n");
        return 1;
    }
 // Check for correct input of 2 strings - the function and only one more string
    string k = args[1];
    string plaintext = get_string("plaintext: ");
    int k_len = strlen(k);

    printf("ciphertext: ");
// Check if the second string from the input is something other than alphabetical
    for (int i = 0, j = 0, n = strlen(plaintext); i < n; i++)
    {
        if (!isalpha(plaintext[i]))
        {
            printf("%c", plaintext[i]);
            continue;
        }
// Start encrypting the entered plaintext
        int ascii_offset = isupper(plaintext[i]) ? 65 : 97;

        int pi = plaintext[i] - ascii_offset;
        int kj = toupper(k[j % k_len]) - 65;
        int ci = (pi + kj) % 26;
        j++;

        printf("%c", ci + ascii_offset);
    }

    printf("\n");
    return 0;
}