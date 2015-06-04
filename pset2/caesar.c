#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

const int ALPHABET_SIZE = 26;

const int LOWER_OFFSET = 'a';
const int UPPER_OFFSET = 'A';

// encodes the text with the Caesar cipher
// prints the coded char 
void encodeCaesar(string message, int k)
{
    // Encode and print each symbol of the text with the key
    for (int i = 0, length = strlen(message); i < length; i++)
    {
        if (isalpha(message[i]))
        {
            if (islower(message[i]))
                printf("%c", (LOWER_OFFSET + (message[i] - LOWER_OFFSET + k) % ALPHABET_SIZE));
            else if (isupper(message[i]))
                printf("%c", (UPPER_OFFSET + (message[i] - UPPER_OFFSET + k) % ALPHABET_SIZE));
        }
        else
        {
            printf("%c", message[i]);
        }
    }
    printf("\n");
}

int main(int argc, string argv[])
{
    // Check the number of input parameters
    if (argc != 2 )
    {
        printf("Invalid input\n");
        return 1;
    }

    // Convert the input to a number
    int k = (atoi(argv[1])) % ALPHABET_SIZE;
    // message to encrypt
    string message = GetString(); 

    encodeCaesar(message, k);

    return 0;
}
