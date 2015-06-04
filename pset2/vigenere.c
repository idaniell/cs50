#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int ALPHABET_SIZE = 26;

int LOWER_OFFSET = 'a';
int UPPER_OFFSET = 'A';

// checks the keyword 
int checkKeyword(string message)
{
    for (int i = 0, length = strlen(message); i < length; i++)
    {
        if (!isalpha(message[i]))
        {
            return 0;
        }
    }
    return 1;
}

// gets the value 
int getKey(string key, int position, int length)
{
    int i = position % length;

    if (islower(key[i]))
        return key[i] - LOWER_OFFSET;
    else
        return key[i] - UPPER_OFFSET;
}

// Encodes the text with the Viginere cipher
// prints the coded char 
void encodeViginere(string message, string key)
{
    int key_length = strlen(key);

    // Encode and print each symbol of the message
    for (int i = 0, position = 0, n = strlen(message); i < n; i++)
    {
        if (isalpha(message[i]))
        {
            if (islower(message[i]))
                printf("%c", (LOWER_OFFSET + (message[i] - LOWER_OFFSET + getKey(key, position, key_length)) % ALPHABET_SIZE));
            else if (isupper(message[i]))
                printf("%c", (UPPER_OFFSET + (message[i] - UPPER_OFFSET + getKey(key, position, key_length)) % ALPHABET_SIZE));
            position++;
        }
        else
        {
            printf("%c", message[i]);
        }
    }
    printf("\n");
}

int main(int argc, char *argv[])
{
    // Check the number of input
    if (argc != 2)
    {
        printf("Incorrect input\n");
        return 1;
    }

    // checks the correctness of the keyword
    if (!checkKeyword(argv[1]))
    {
        printf("Arguments incorrect.\n");
        return 1;        
    }

    string message = GetString();

    // Encode the text with the Viginere cipher
    encodeViginere(message, argv[1]);

    return 0;
}
