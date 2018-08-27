#include <stdio.h>
#include <string.h>

void closureParse(char state, int size, char arr[size][8])
{
    int i = 0, j = 0;
    for(int i = 0; i < size; i++)
    {
        if(arr[i][0] == state && arr[i][1] == '_')
        {
            for(j = 2; j < strlen(arr[i]); j++)
            {
                printf("%c", arr[i][j]);
                closureParse(arr[i][j], size, arr);
            }
        }
    }
}

int main(int argc, char const *argv[])
{
    int numOfStates, numOfTrans;
    int i = 0, j = 0;
    printf("Enter the number of States: ");
    scanf("%d", &numOfStates);
    char states[numOfStates];
    printf("\nEnter the states: \n");
    for (i = 0; i < numOfStates; i++)
    {
        scanf(" %c", &states[i]);
    }
    printf("\nEnter the number of Transitions: ");
    scanf("%d", &numOfTrans);
    char trans[numOfTrans][8];
    for (i = 0; i < numOfTrans; i++)
    {
        char temp[10];
        printf("\nEnter the State %d: ", i + 1);
        scanf(" %c", &trans[i][0]);
        printf("\n%d. %c on input symbol('_' for Epsilon): ", i + 1, trans[i][0]);
        scanf(" %c", &trans[i][1]);
        printf("\n%d. %c on input symbol %c gives: ", i + 1, trans[i][0], trans[i][1]);
        scanf("%s", temp);
        for (j = 0; j < strlen(temp) && j < 6; j++)
            trans[i][j + 2] = temp[j];
    }
   
    printf("\n\n**CLOSURE**");
    printf("\n--------------------------\n");
    for (i = 0; i < numOfStates; i++)
    {
        printf("%c -> %c", states[i], states[i]);
        closureParse(states[i], numOfTrans, trans);
        printf("\n--------------------------\n");
    }

    return 0;
}