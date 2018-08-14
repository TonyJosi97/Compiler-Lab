#include <stdio.h>

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


    printf("*%s\n", states[2]);
    

    return 0;
}
