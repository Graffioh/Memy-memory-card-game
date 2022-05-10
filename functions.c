#include "functions.h"
#define MAX_SIZE_ROW 3
#define MAX_SIZE_COLUMN 4

void swap(char* a, char* b)
{
    char temp = *a;
    *a = *b;
    *b = temp;
}

void cardShuffle(int arr[MAX_SIZE_ROW][MAX_SIZE_COLUMN]) // reference: https://www.geeksforgeeks.org/shuffle-a-given-array-using-fisher-yates-shuffle-algorithm/
{
    // Use a different seed value so that
    // we don't get same result each time
    // we run this program
    srand(time(NULL));

    // Start from the last element and swap
    // one by one. We don't need to run for
    // the first element that's why i > 0
    for (int i = MAX_SIZE_ROW - 1; i > 0; i--)
    {
        for (int k = MAX_SIZE_COLUMN - 1; k > 0; k--)
        {
            {
                // Pick a random index from 0 to i
                int j = rand() % (i + 1);
                int z = rand() % (k + 1);

                // Swap arr[i] with the element
                // at random index
                swap(&arr[i][k], &arr[j][z]);
            }
        }
    }
}

void playerInput(char* x, char* y)
{
    printf(" \nMake your choice: ");
    scanf_s(" %c", x);
    scanf_s(" %c", y);
}

void changeToX(int matrix[MAX_SIZE_ROW][MAX_SIZE_COLUMN], char arrPrint1[], char arrPrint2[], char arrPrint3[])
{
    int x = 0, y = 0, z = 0;
    
    for (int i = 0; i < MAX_SIZE_ROW; i++)
    {
        for (int j = 0; j < MAX_SIZE_COLUMN; j++)
        {
            if (matrix[i][j] == -1 || matrix[i][j] == -2)
            {
                x = i;
                y = j;
                if (x == 0 && (y >= 0 && y <= 3))
                {
                    if (y == 0)
                        z = 5;
                    if (y == 1)
                        z = 14;
                    if (y == 2)
                        z = 23;
                    if (y == 3)
                        z = 32;
                    arrPrint1[z] = 'X';
                    arrPrint1[z + 1] = 'X';
                }

                if (x == 1 && (y >= 0 && y <= 3))
                {
                    if (y == 0)
                        z = 5;
                    if (y == 1)
                        z = 14;
                    if (y == 2)
                        z = 23;
                    if (y == 3)
                        z = 32;
                    arrPrint2[z] = 'X';
                    arrPrint2[z + 1] = 'X';
                }
                if (x == 2 && (y >= 0 && y <= 3))
                {
                    if (y == 0)
                        z = 5;
                    if (y == 1)
                        z = 14;
                    if (y == 2)
                        z = 23;
                    if (y == 3)
                        z = 32;
                    arrPrint3[z] = 'X';
                    arrPrint3[z + 1] = 'X';
                }
            }
        }
    }
}