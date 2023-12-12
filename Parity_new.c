/*
Date : 13/04/2021
Obj : Program to input a dataword and output codeword with even parity bit.
Author : Yuvraj Raghuvanshi (https://github.com/yuvrajraghuvanshis)
*/

#include <stdio.h>
#include <iostream>

struct string
{
    char array[10];
};
struct dataword_codeword
{
    string dataword, codeword;
    char parity;
};

char CountNumberOf1S(struct string temp)
{
    int i = 0, count = 0;
    while (temp.array[i] != '\000' && i < 10)
    {
        if (temp.array[i] == '1')
            count++;
        i++;
    }

    return count % 2 == 0 ? '0' : '1';
}

string AppendParityToCodeword(struct string dataword, char parity)
{
    int i = 0;
    while (dataword.array[i] != '\000')
    {
        i++;
    }

    if (parity == '0')
    {
        dataword.array[i] = '0';
    }
    else
    {
        dataword.array[i] = '1';
    }
    return dataword;
}

int main()
{
    int dn, i;

    struct dataword_codeword dc[10] = {};
    printf("Enter the number of datawords : ");
    scanf("%d", &dn);
    printf("Enter datawords : ");
    // Enter dataword and it's parity...
    for (i = 0; i < dn; i++)
    {
        struct string temp = {};
        scanf("%s", &temp.array);
        dc[i].dataword = temp;
        dc[i].parity = CountNumberOf1S(temp);
    }

    // Enter codeword and it's parity...
    for (i = 0; i < dn; i++)
    {
        dc[i].codeword = AppendParityToCodeword(dc[i].dataword, dc[i].parity);
    }

    printf("DW\tCW\tP(DW)");
    for (i = 0; i < dn; i++)
    {
        printf("\n%s\t%s\t%c", dc[i].dataword.array, dc[i].codeword.array, dc[i].parity);
    }

    printf("\n");
    system("pause"); // To freeze screen.
    return 0;
}