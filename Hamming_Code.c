/*
Date : 30/04/2021
Obj : Take an input from user which came from noisy channel and has atmost 1 bit error and try to find error out using Hamming Code.
Author : Yuvraj Raghuvanshi (https://github.com/yuvrajraghuvanshis)
*/
// HammingCode(15,11)
#include <stdio.h>
#include <iostream>

int main()
{
    int i, codeLen = 15 + 1; // !5 for CW + redundant bits, and 1 for 0th index that is unused in (15,11) code.
    int hammingCode[codeLen], errPos = 0;
    printf("Enter 15 digits codeword : ");

    for (i = 1; i < codeLen; i++)
    {
        scanf("%d", &hammingCode[i]);
    }

    // XOR all positions which are 1
    for (i = 1; i < codeLen; i++)
    {
        if (hammingCode[i] == 1)
            errPos ^= i;
    }

    errPos == 0 ? printf("No one bit in code") : printf("Error at position %d.", errPos);
    printf("\nOriginal codeword : ");
    for (i = 1; i < codeLen; i++)
    {
        printf(" %d ", hammingCode[i]);
    }
    printf("\nModified codeword : ");
    for (i = 1; i < codeLen; i++)
    {
        if (i == errPos)
            printf("<%d>", hammingCode[i] == 0 ? 1 : 0);
        else
            printf(" %d ", hammingCode[i]);
    }
    printf("\n");
    system("pause");
    return 0;
}