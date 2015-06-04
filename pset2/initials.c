#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

// get the initials letters in uppercase
int getInitialsLetters(string name, char* initialsLetter)
{
    // char's vector length 
    int vectorLength = 0; 

    // initial letter 
    initialsLetter[vectorLength++] = toupper(name[0]);

    // grab the first letter in uppercase
    for (int i = 1; i < strlen(name); i++)
    {
        if (name[i] == ' ' && name[i + 1] != '\0')
        {
            initialsLetter[vectorLength++] = toupper(name[i + 1]);
        }
    }

    return vectorLength;
}

// printing the first letters
void printName(char* initialsLetter, int lengthVector)
{
    for(int i = 0; i < lengthVector; i++)
    {
        printf("%c", initialsLetter[i]);
    }
    printf("\n");
}

int main(void)
{
    int lengthVector;
    char initialsLetters[100];
    // get string input from user
    string name = GetString();

    // get the initials letters in uppercase
    lengthVector = getInitialsLetters(name, initialsLetters);

    // printing the first letters
    printName(initialsLetters, lengthVector);
}
