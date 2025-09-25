#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <cs50.h>
#include <string.h>
#include <strings.h>

int verifykey(int argc, char **argv);
string caesar(string key, string plaintext);

int main(int argc, char **argv)
{
    verifykey(argc, argv);
    string key = argv[1];
    string plaintext = get_string("plaintext:  ");
    string ciphertext = caesar(key, plaintext);

    printf("ciphertext: %s\n", ciphertext);

    return 0;
}

int verifykey(int argc, char **argv)
{
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        exit(1);
    }
    string key = argv[1];
    int len = strlen(key);
    for (int i = 0; i < len; i++)
    {
        if(isdigit(key[i]) == false)
        {
            printf("Usage: ./caesar key\n");
            exit(1);
        }
    }
    return 0;
}
string caesar(string key, string plaintext)
{
    int nkey = atoi(key);
    string ciphertext = malloc(strlen(plaintext) + 1);
    string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char *newalphabet[26];


    for (int i = 0; i < strlen(alphabet); i++)
    {
        newalphabet[i] = &alphabet[(nkey+i)%26];
    }

    for (int j = 0; j < strlen(plaintext); j++)
    {
        int alpha_index = 0;
        if(isupper(plaintext[j]))
        {
            alpha_index += (int)plaintext[j] - 'A';
            ciphertext[j] = *newalphabet[alpha_index];

        }
        else if (islower(plaintext[j]))
        {
            alpha_index += (int)plaintext[j] - 'a';
            ciphertext[j] = tolower(*newalphabet[alpha_index]);
        }
        else
        {
            ciphertext[j] = plaintext[j];
        }
    }
    ciphertext[strlen(plaintext)] = '\0';
    return ciphertext;
}
