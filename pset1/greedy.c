#include <stdio.h>
#include <cs50.h>
#include <math.h>

float readInput()
{
    float owed;

    // check user's input
    do
    {
        printf("O hai! How much change is owed?\n");	
        owed = GetFloat();
    }while(owed < 0);

    return owed;
}

void coinsCounter(int* availableCoins, float owed)
{
    // converting money into cents
    int cents = round(owed * 100);

    // counter
    int coinCounter = 0;

    // number of coins needed
    for (int i = 0, coinLength = 4; i < coinLength; i++)
    {
        // update coin counter
        coinCounter += (cents - (cents % availableCoins[i])) / availableCoins[i];
        cents = cents % availableCoins[i];
    }

    // output coin counter result
    printf("%i\n", coinCounter);
}

int main(void)
{
    // all available coins
    int availableCoins[] = {25, 10, 5, 1};

    float owed = readInput();

    coinsCounter(availableCoins, owed);
}
