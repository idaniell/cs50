/**
 * helpers.c
 *
 * Computer Science 50
 * Problem Set 3
 *
 * Helper functions for Problem Set 3.
 */
       
#include <cs50.h>

#include "helpers.h"

/**
 * Returns true if value is in array of n values, else false.
 */
bool search(int value, int values[], int n)
{
    // array limits
    int beginPosition = 0;
    int endPosition = n - 1;

    while (beginPosition <= endPosition)
    {
        int middlePosition = (beginPosition + endPosition) / 2;

        if(values[middlePosition] == value)
        {
            return true;
        }
        else if (values[middlePosition] < value)
        {
           beginPosition = middlePosition + 1; 
        }
        else
        {
            endPosition = middlePosition - 1;
        }

    }
    return false;
}

/**
 * Sorts array of n values.
 */
void sort(int values[], int n)
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n - 1; j++)
        {
            if (values[j] > values[j + 1])
            {
                int temp = values[j];
                values[j] = values[j + 1];
                values[j + 1] = temp;
            }
        }
    }
}
