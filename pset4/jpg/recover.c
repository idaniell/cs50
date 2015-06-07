/**
 * recover.c
 *
 * Computer Science 50
 * Problem Set 4
 *
 * Recovers JPEGs from a forensic image.
 */

#include <stdio.h>
#include <stdint.h>

typedef uint8_t BYTE;

int main(void)
{   
    // open the file programmatically with fopen
    FILE* file = fopen("card.raw", "r");

    // check file permission
    if (file == NULL)
    {
        fclose(file); 
        printf("unable to recover file\n");
        return 1;
    }

    // output
    FILE* temp = NULL; 

    // image counter
    int imgCounter = 0; 

    // buffer 
    BYTE buffer[512];

    // file name 
    char fileName[10]; 

    // search through file for jpg headers
    while (!feof(file))
    {
        // check first couple 
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] == 0xe0 || buffer[3] == 0xe1))
        {
            // close previous jpg if not the first jpg found
            if (temp != NULL)
            {
                fclose(temp);
            }

            // create file name from imgCounter
            sprintf(fileName, "%03d.jpg", imgCounter);

            // next file in line
            temp = fopen(fileName, "w");

            // bump the counter up
            imgCounter++;

            // new file with buffer
            fwrite(buffer, sizeof(buffer), 1, temp);
        }
        else if (imgCounter > 0)
        {
            // put jpg into temp
            fwrite(buffer, sizeof(buffer), 1, temp);            
        }
        fread(buffer, sizeof(buffer), 1, file);
    }

    // close the file
    if (fclose != NULL)
    {
        fclose(file);
    }
    // that's all folks
    return 0;
}
