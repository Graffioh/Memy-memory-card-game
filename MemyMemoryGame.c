#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include "functions.h"
#include "prints.h"

#define MAX_SIZE_ROW 3
#define MAX_SIZE_COLUMN 4

// Memory Game MADE BY BREGLIA UMBERTO (N86004111) & BARRETTA MATTIA (N86004124)

// TO DO
//  1) Randomize matrix (positions not numbers, so a shuffle) (DONE)
//     references: [https://www.geeksforgeeks.org/shuffle-a-given-array-using-fisher-yates-shuffle-algorithm/] 
//                 [https://stackoverflow.com/questions/6127503/shuffle-array-in-c] 
//
//  2) Implement functions (DONE)
//  
//  3) Better user-interface experience (DONE)

int main()
{
    int matrix[MAX_SIZE_ROW][MAX_SIZE_COLUMN] = {
        {1, 6, 2, 2},
        {3, 9, 6, 5},
        {1, 3, 9, 5} };

    int choice1row = 0 , choice1column = 0 , choice2row = 0, choice2column = 0; // input variables.
    int flag = 0, counter = 0, i = 0, fails = 0;                              // check variables.
    char choice1rowChar, choice1columnChar, choice2rowChar, choice2columnChar;

    char arrPrint1[] = { " |   00   |   01   |   02   |   03   |\n" };         // arrays for graphic integration.
    char arrPrint2[] = { " |   10   |   11   |   12   |   13   |\n" };        //
    char arrPrint3[] = { " |   20   |   21   |   22   |   23   |\n" };        //

    printGame();

    system("pause");
    system("cls");

    printCards();

    cardShuffle(matrix);

    // print test
    /*
    printf("\n\n");
    for (int i = 0; i < MAX_SIZE_ROW; i++)
    {
        for (int j = 0; j < MAX_SIZE_COLUMN; j++)
        {
            printf("riga %d , colonna %d : %d \n", i, j, matrix[i][j]);
        }
    }
    printf("\n\n");
    */

    do
    {
        // player inputs
        int error = 0;
        do
        {
            if (error == 1) // error reset
            {
                printf("try again\n");
                error = 0;
            }

            playerInput(&choice1rowChar, &choice1columnChar);

            choice1row = (int)choice1rowChar - 48;
            choice1column = (int)choice1columnChar - 48;


            if ((choice1row < MAX_SIZE_ROW && choice1row >= 0) && (choice1column < MAX_SIZE_COLUMN && choice1column >= 0)) // check if the choice is available.
            {
                if (matrix[choice1row][choice1column] != -1 && matrix[choice1row][choice1column] != -2) // check if the card is already flipped or not.
                {
                    printf(" \nNumber under first card: %d\n\n", matrix[choice1row][choice1column]);
                }
                else
                {
                    printf("Card already flipped\n");
                    error = 1;
                }
            }
            else
            {
                printf("Choice not available\n");
                error = 1;
            }
        } while (matrix[choice1row][choice1column] == -1 || error == 1); // check for invalid inputs.


        error = 1;
        do
        {
            if (error == 0)
            {
                printf("try again\n");
                error = 1;
            }

            playerInput(&choice2rowChar, &choice2columnChar);

            choice2row = (int)choice2rowChar - 48;
            choice2column = (int)choice2columnChar - 48;

            if (choice2row < MAX_SIZE_ROW && choice2row >= 0 && (choice2column < MAX_SIZE_COLUMN && choice2column >= 0))
            {
                if (matrix[choice2row][choice2column] != -2 && matrix[choice2row][choice2column] != -1)
                {
                    printf(" \nNumber under second card: %d\n\n", matrix[choice2row][choice2column]);
                }
                else
                {
                    printf("Card already flipped\n");
                    error = 0;
                }
            }
            else
            {
                printf("Choice not available\n");
                error = 0;
            }

            if ((choice2row == choice1row && choice2column == choice1column)) // another error checking
            {
                error = 0;
            }

        } while (matrix[choice2row][choice2column] == -2 || error == 0);


        // game logic
        if ((matrix[choice1row][choice1column] == matrix[choice2row][choice2column])) // if equal +1 point && print the updated table.
        {
            Sleep(1600);
            system("cls");
            printf("*** Nice! go on: +1 point ***\n");
            system("pause");
            system("cls");

            matrix[choice1row][choice1column] = -1; // change the value in the first correct position to -1
            matrix[choice2row][choice2column] = -2; // change the value in the second correct position to -2

            printf("\n Failed attempts: %d\n\n", fails);
            changeToX(matrix, arrPrint1, arrPrint2, arrPrint3); // function to change printf accordingly to the state of the game
            printCardsFinal(arrPrint1, arrPrint2, arrPrint3);   // function to print the changed table

            counter++;
        }
        else
        {
            Sleep(1600);
            system("cls");
            printf("--- Unlucky! retry ---\n");
            system("pause");
            system("cls");

            fails++;

            printf("\n Failed attempts: %d\n\n", fails);
            printCardsFinal(arrPrint1, arrPrint2, arrPrint3);
        }

        if (counter == 6)
        {
            printf("\n\n01011001 01001111 01010101 00100000 01010111 01001111 01001110\n\n"); // a message for the winner
            system("pause");
            flag = 1;
        }

    } while (flag == 0);

    return 0;
}