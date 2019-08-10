#define _XOPEN_SOURCE
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <cs50.h>

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: crack \"hash\" \n");
        return 1;
    }

    int letters_count = 53;

    string letters = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ\0"; //Les Caracteres utiliser dans les mots de passe
    string hash = argv[1];

    char salt[3];
    memcpy(salt, hash, 2); //Copie les deux premiere valeur du hash dans salt
    salt[2] = '\0';

    char key[6] = "\0\0\0\0\0\0"; //va contenir le mot de passe rechercher

    //Recherche du mot de passe par force brute
    for (int fifth = 0; fifth < letters_count; fifth++)
    {
        for (int fourth = 0; fourth < letters_count; fourth++)
        {
            for (int third = 0; third < letters_count; third++)
            {
                for (int second = 0; second < letters_count; second++)
                {
                    for (int first = 1; first < letters_count; first++)
                    {
                        key[0] = letters[first];
                        key[1] = letters[second];
                        key[2] = letters[third];
                        key[3] = letters[fourth];
                        key[4] = letters[fifth];

                        if (strcmp(crypt(key, salt), hash) == 0) // Comparaison des deux clés haché
                        {
                            printf("%s\n", key);
                            return 0;
                        }
                    }
                }
            }
        }
    }

    printf("Password couldn't be cracked!");

    return 2;
}