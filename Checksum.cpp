/*
Date : 27/04/2021
Obj : A program which takes some binary input and calculates it's checksum. Further ask to change any input to simulate noise transmission and calculates new checksum...
Author : Yuvraj Raghuvanshi (https://github.com/yuvrajraghuvanshis)
*/

#include <stdio.h>
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

string addBinaryAsStrings(string checksum, string dataword)
{
    int checksumLen = checksum.size(), datawordLen = dataword.size(), len = 0;

    // Compare both lengths and add padding (0's on left side) so that they can add properly.
    if (checksumLen < datawordLen)
    {
        for (int i = 0; i < datawordLen - checksumLen; i++) //See how much is the difference in length.
            checksum = '0' + checksum;                      //Prepend that many 0's in checksum.
        len = datawordLen;
    }
    else if (datawordLen < checksumLen)
    {
        for (int i = 0; i < checksumLen - datawordLen; i++) //See how much is the difference in length.
            dataword = '0' + dataword;                      //Prepend that many 0's in dataword.
        len = checksumLen;
    }
    else // Both are equal length.
    {
        len = datawordLen;
    }

    string result;
    char carry = '0';
    for (int i = len - 1; i >= 0; i--)
    {
        char checksumBit = checksum[i];
        char datawordBit = dataword[i];
        char sum = (checksumBit ^ datawordBit ^ carry);                                      // XOR for sum i.e. : 1 + 1 = 0(sum) and 1(carry).
        result = sum + result;                                                               // Prepend sum in result.
        carry = (checksumBit & datawordBit) | (datawordBit & carry) | (checksumBit & carry); // Bitwise AND for carry i.e. : 1 & 1 = 1(carry).
    }
    if (carry == '1')          // After all calculations if carry remains (at 9th index if dataword is 8 bits).
        result = '1' + result; // Prepend that to result.
    return result;
}

string addWrappedSum(string checksum)
{
    int *pointToExtraBits;
    pointToExtraBits = checksum.size() - 8;
    int requiredLength = 8, checksumLength = checksum.size(), i;
    int extraBitsLen = checksumLength - requiredLength;
    char extraBits[extraBitsLen] = {};
    for (i = 0; i < extraBitsLen; i++)
    {
        extraBits[extraBitsLen--] = checksum[i];
    }
    printf("%s", extraBits);
    return "meow";
}

string onesComplement(string checksum)
{

    int i = 0, len = checksum.size();
    for (i = 0; i < len; i++)
    {
        if (checksum[i] == '0')
        {
            checksum[i] = '1';
            continue; // Go to next iteration immediately.
        }
        if (checksum[i] == '1')
        {
            checksum[i] = '0';
            continue; // Otherwise this would run and cause logical error.
        }
    }
    return checksum;
}

int main()
{
    int dwn, i;
    string datawords[10] = {}, checksum = "00000000";

    printf("Enter the number of datawords (1 byte each) : ");
    scanf("%d", &dwn);
    printf("Enter %d datawords : ", dwn);
    for (i = 0; i < dwn; i++)
    {
        cin >> datawords[i];
        checksum = addBinaryAsStrings(checksum, datawords[i]);
    }

    // checksum = addWrappedSum("10110110111011");
    checksum = onesComplement(checksum);

    // Heading
    cout << "\n\n|";
    for (i = 0; i < dwn; i++)
    {
        printf("   DW %d   |", i);
    }
    printf(" Checksum | ");

    // Data
    cout << "\n\n| ";
    for (i = 0; i < dwn; i++)
    {
        cout << datawords[i] + " | ";
    }
    cout << checksum + " | ";

    printf("\n\n");
    system("pause"); // To freeze screen.
    return 0;
}