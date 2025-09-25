#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <strings.h>
#include <stdlib.h>
#include <ctype.h>

int verifykey(int argc, char **argv);
string convert_plaintext(string plaintext, string key);

int main (int argc, char **argv)
{
    verifykey(argc, argv);
    string key = argv[1];
    string plaintext = get_string("Plaintext: \n");

    string ciphertext = convert_plaintext(plaintext, key);

    printf("ciphertext: %s\n", ciphertext);
    exit(0);
}

int verifykey(int argc, char **argv)
{
    string key = argv[1];
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        exit(1);
    }
    else if (strlen(argv[1]) != 26)
    {
        printf("Key must contain 26 characters.\n");
        exit(1);
    }
    else
    {
        for(int i = 0; i < strlen(key); i++)
        {
            if(isalpha(key[i]) == false)
            {
                printf("Key must contain only characters.\n");
                exit(1);
            }
            for(int j = 0; j < strlen(key); j++)
            {
                if (i != j)
                {
                    if(toupper(key[i]) == toupper(key[j]) && key[i] != ' ')
                    {
                        printf("Try again without repeting characters. \n");
                        exit(1);
                    }
                }
            }
        }
    }
    return 0;
}
string convert_plaintext(string plaintext, string key)
{
    int len = strlen(plaintext);
    string ciphertext = malloc(len + 1);
    for (int i = 0; i < len; i++)
    {
        if (isalpha(plaintext[i]))
        {
            int alpha_index = toupper(plaintext[i]) - 'A';
            char cipher_char = isupper(plaintext[i]) ? toupper(key[alpha_index]) : tolower(key[alpha_index]);
            ciphertext[i] = cipher_char;
        }
        else
        {
            ciphertext[i] = plaintext[i];
        }
    }

    ciphertext[len] = '\0';
    return ciphertext;
}
