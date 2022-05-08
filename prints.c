#include "prints.h"

void printGame()
{
    printf(" +++++++++++++++++++++++++++++++++++++++++++++++++++\n");
    printf(" | WELCOME TO MEMY, Where the Memory is important! |\n");
    printf(" +++++++++++++++++++++++++++++++++++++++++++++++++++\n\n");
    printf(" RULES:\n");
    printf(" Just put the inputs accordingly to the image, and then see if they are the same, go over and find all the same cards.\n\n");

    printf(" In order to win you must score 6 points.\n\n");

    printf(" Max number of choices available: row = 2 column = 3 And you can't go under 0\n\n");

    printf(" Insert only digits, not alphabet letters/special symbols.\n\n");

    printf(" If you score a point, XX characters will be displayed where you already flipped the card\n\n");

    printf(" ENJOY! :)\n\n");

}

void printCards()
{
    printf(" [row][column]\n");
    printf("     ^\n");
    printf("     |\n");
    printf("  ==================================\n");
    printf(" |        |        |        |        |\n");
    printf(" |   00   |   01   |   02   |   03   |\n");
    printf(" |        |        |        |        |\n");
    printf("  ==================================\n");
    printf(" |        |        |        |        |\n");
    printf(" |   10   |   11   |   12   |   13   |\n");
    printf(" |        |        |        |        |\n");
    printf("  ==================================\n");
    printf(" |        |        |        |        |\n");
    printf(" |   20   |   21   |   22   |   23   |\n");
    printf(" |        |        |        |        |\n");
    printf("  ==================================\n");
}

void printCardsFinal(char arrPrint1[], char arrPrint2[], char arrPrint3[])
{

    printf("  ==================================\n");
    printf(" |        |        |        |        |\n");
    printf("%s", arrPrint1);
    printf(" |        |        |        |        |\n");
    printf("  ==================================\n");
    printf(" |        |        |        |        |\n");
    printf("%s", arrPrint2);
    printf(" |        |        |        |        |\n");
    printf("  ==================================\n");
    printf(" |        |        |        |        |\n");
    printf("%s", arrPrint3);
    printf(" |        |        |        |        |\n");
    printf("  ==================================\n");
}