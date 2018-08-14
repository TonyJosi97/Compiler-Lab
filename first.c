#include <stdio.h>

void getEpsilon(int whichState, int size, int col, char arr[size][col])
{
    int k = 0, newWhichState;
    printf("%c", arr[whichState][1]);
    
    if (arr[whichState][1] != '-')
    {
        printf("%c", arr[whichState][1]);
        for (k = 0; k < size; k++)
        {
            if (arr[k][0] == arr[whichState][1])
            {
                newWhichState = k;
                break;
            }
        }
        getEpsilon(newWhichState, size, col, arr);
    }
    
}

int main(int argc, char const *argv[])
{
    int ipSize, noIpSymbols;
    printf("Enter the number of states: ");
    scanf("%d", &ipSize);
    printf("Enter the number of Input Symbols: ");
    scanf("%d", &noIpSymbols);
    int i, j;
    char ipSymbols[noIpSymbols];

    printf("Enter the input symbols( _ for Epsilon):\n");
    for (i = 0; i < noIpSymbols; i++)
        scanf("%s", &ipSymbols[i]);

    char states[ipSize][noIpSymbols + 1];

    for (i = 0; i < ipSize; i++)
    {
        printf("State %d: ", i + 1);
        scanf("%s", &states[i][0]);

        for (j = 0; j < noIpSymbols; j++)
        {
            printf("State %d on Input %c (- if empty): ", i + 1, ipSymbols[j]);
            scanf("%s", &states[i][j + 1]);
        }
    }

    getEpsilon(0, ipSize, noIpSymbols + 1, states);

    return 0;
}
