#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LENGTH 256

bool control_argv(char *argv, size_t length);
char *encrypt(char *plain_text, char *key, size_t length);

int main(int argc, char *argv[])
{
    if (argc == 2)
    {
        int length = strlen(argv[1]);
        if (control_argv(argv[1], length))
        {
            printf("plaintext:  ");
            char *plaintext = malloc(MAX_LENGTH * sizeof(char));
            scanf("%255[^\n]", plaintext); // limit the number of chars to prevent buffer overflow
            char *ciphertext = encrypt(plaintext, argv[1], strlen(plaintext));
            printf("ciphertext: %s\n", ciphertext);

            free(plaintext);
            free(ciphertext);

            return 0;
        }

        else
        {
            return 1;
        }
    }
    else
    {
        printf("Usage: %s key\n", argv[0]);
        return 1;
    }
}

bool control_argv(char *argv, size_t length)
{
    if (length == 26)
    {
        bool char_present[26] = {false};
        for (int i = 0; i < length; i++)
        {
            if (!isalpha(argv[i]))
            {
                return false;
            }

            int index = tolower(argv[i]) - 'a';
            if(char_present[index])
            {
                fprintf(stderr, "Key must not contain duplicate characters.\n");
                return false;
            }

            char_present[index] = true;
        }
        return true;
    }
    else
    {
        fprintf(stderr, "Key must contain 26 characters.\n");
        return false;
    }
}

char *encrypt(char *plain_text, char *key, size_t length)
{
    char *cipher_text = malloc((length + 1) * sizeof(char));
    for (int i = 0; i < length; i++)
    {
        char current_char = plain_text[i];
        if (islower(current_char))
        {
            int index = current_char - 'a';
            cipher_text[i] = tolower(key[index]);
        }

        else if (isupper(current_char))
        {
            int index = current_char - 'A';
            cipher_text[i] = toupper(key[index]);
        }

        else
        {
            cipher_text[i] = current_char;
        }
    }

    cipher_text[length] = '\0';

    return cipher_text;
}
