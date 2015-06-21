/****************************************************************************
 * dictionary.c
 *
 * Computer Science 50
 * Problem Set 5
 *
 * Implements a dictionary's functionality.
 ***************************************************************************/

#include <stdbool.h>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "dictionary.h"

// size of hashtable
#define SIZE 1000000

// linked list
typedef struct node
{
    char word[LENGTH+1];
    struct node* next;
}
node;

// create hashtable
node* hashtable[SIZE] = {NULL};

// hash function
int hash (const char* word)
{
    int n, hash = 0;

    for (int i = 0; word[i] != '\0'; i++)
    {
        // alphabet case
        if(isalpha(word[i]))
        {
            n = word [i] - 'a' + 1;
        }

        // comma case
        else
        {
            n = 27;
        }

        hash = ((hash << 3) + n) % SIZE;
    }
    return hash;    
}

// variable to count size
int dictionarySize = 0;

/**
 * Loads dictionary into memory.  Returns true if successful else false.
 */
bool load(const char* dictionary)
{
    // opens dictionary
    FILE* file = fopen(dictionary, "r");
    if (file == NULL)
    {
        return false;
    }

    // word to be stored in
    char word[LENGTH + 1];

    // scan through the file, loading each word into the hash table
    while (fscanf(file, "%s\n", word)!= EOF)
    {
        int index;
        // increment dictionary size
        dictionarySize++;

        // allocate memory 
        node* newWord = malloc(sizeof(node));

        // clone 
        strcpy(newWord->word, word);

        // find what index of the array 
        index = hash(word);

        // hashtable is empty at index
        if (hashtable[index] == NULL)
        {
            hashtable[index] = newWord;
            newWord->next = NULL;
        }
        // append
        else
        {
            newWord->next = hashtable[index];
            hashtable[index] = newWord;
        }      
    }

    fclose(file);
    return true;
}

/**
 * Returns true if word is in dictionary else false.
 */
bool check(const char* word)
{
    // temp variable to store a lower-cased version of the word
    char temp[LENGTH + 1];
    int index, len = strlen(word);

    for(int i = 0; i < len; i++)
    {
        temp[i] = tolower(word[i]);
    }
    temp[len] = '\0';

    // find out what index of the array the word should be in
    index = hash(temp);

    // word not found 
    if (hashtable[index] == NULL)
    {
        return false;
    }

    // create cursor to compare to word
    node* cursor = hashtable[index];

    // iterating through words and compare
    while (cursor != NULL)
    {
        if (strcmp(temp, cursor->word) == 0)
        {
            return true;
        }
        cursor = cursor->next;
    }

    // word not found 
    return false;
}

/**
 * Returns number of words in dictionary if loaded else 0 if not yet loaded.
 */
unsigned int size(void)
{
    // return number of words
    if (dictionarySize > 0)
    {
        return dictionarySize;
    }

    // if dictionary hasn't been loaded, return 0
    return 0;
}

/**
 * Unloads dictionary from memory.  Returns true if successful else false.
 */
bool unload(void)
{
    // go through index
    int index = 0;

    // iterate through entire hashtable array
    while (index < SIZE)
    {
        // go to next index
        if (hashtable[index] == NULL)
        {
            index++;
        }

        // iterate through nodes and start freeing
        else
        {
            while(hashtable[index] != NULL)
            {
                node* cursor = hashtable[index];
                hashtable[index] = cursor->next;
                free(cursor);
            }

            // once hashtable is empty at index, go to next index
            index++;
        }
    }

    // successful
    return true;
}
