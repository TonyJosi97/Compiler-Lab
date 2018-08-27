#include <stdio.h>

/*
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
*/

void parseEpsilon(int ch, int ipSize, int col, char states[ipSize][col])
{
    int start = 0, k = 0, flag;
    start = ch;
    printf("%c -> %c", states[ch][0], states[ch][0]);
    while (states[start][1] != '-')
    {
        printf("%c", states[start][1]);
        flag = 0;
        for (k = 0; k < ipSize; k++)
        {
            if (states[k][0] == states[start][1])
            {
                flag = 1;
                start = k;
                break;
            }
        }
        if (flag == 0)
            break;
    }
    printf("\n---------------------\n");
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
            printf("State %c on Input %c (- if empty): ", states[i][0], ipSymbols[j]);
            scanf("%s", &states[i][j + 1]);
        }
    }

    //getEpsilon(0, ipSize, noIpSymbols + 1, states);
    
    char ch;
    int start = 0, k = 0, newStart, flag;

    printf("\nCLOSURE: \n");
    for(k = 0; k < ipSize; k++)
    {
        parseEpsilon(k, ipSize, noIpSymbols + 1, states);
    }

    return 0;
}
