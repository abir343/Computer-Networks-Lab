/*
Date : 13/04/2021
Obj : Program to input codewords and output hamming distance..
Author : Yuvraj Raghuvanshi (https://github.com/yuvrajraghuvanshis)
*/

#include <stdio.h>
#include <iostream>
#include <string.h>

int min = 999;

int HammingDistance(char str1[], char str2[])
{
    int i = 0, count = 0;
    while (str1[i] != '\0')
    {
        if (str1[i] != str2[i])
            count++;
        i++;
    }
    return count;
}

void IsMin(int hd)
{
    if (hd < min)
    {
        min = hd;
    }
}

int main()
{
    int cwn, hd;
    char codeword[10][10] = {};
    printf("Enter number of codewords : ");
    scanf("%d", &cwn);
    printf("Enter codewords : ");
    for (int i = 0; i < cwn; i++)
    {
        scanf("%s", &codeword[i]);
    }

    for (int i = 0; i < cwn; i++)
    {
        for (int j = i + 1; j < cwn; j++)
        {
            hd = HammingDistance(codeword[i], codeword[j]);
            printf("\nHamming Distance (%s, %s) = %d", codeword[i], codeword[j], hd);
            IsMin(hd);
        }
    }

    printf("\n\nMinimum hamming distance : %d", min);
    printf("\n");
    system("pause");
    return 0;
}