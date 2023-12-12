/*
Date : 13/04/2021
Obj : Program to input a 1-D array as dataword and output a 2-D array having codeword with even parity bit.
Author : Yuvraj Raghuvanshi (https://github.com/yuvrajraghuvanshis)
*/

#include <stdio.h>
#include <iostream>
#include <math.h>
#include <map>

int ReturnParity(int num)
{
    int count = 0;
    while (num != 0)
    {
        num = num & (num - 1);
        count++;
    }
    return count % 2 == 0 ? 1 : 2;
    // Return 1 for even parity and 2 for odd parity.
}

int main()
{
    int dn;
    std::map<int, std::map<int, int>> dataword_codeword = {};
    std::map<int, int> codeword = {};

    // dataword_codeword.emplace("window", 3.14);

    // map_data.emplace(0, data);

    printf("\nEnter number of dataword(s) : ");
    scanf("%d", &dn);
    printf("Enter datawords in decimal : ");
    for (int i = 0; i < dn; i++)
    {
        int temp;
        scanf("%d", &temp);
        codeword.emplace(0, 0);
        dataword_codeword.emplace(temp, codeword);
    }

    // Check no of 1's in inputs...
    for (int i = 0; i < dn; i++)
        // {
        //     dataword_codeword.insert(std::pair<int, int>(dataword[i], ReturnParity(dataword[i])));
        //     //  = ReturnParity(dataword[i]);
        // }

        // Test printing
        for (auto &x : codeword)
        {
            std::cout << x.first << ": " << x.second << '\n';
        }
    return 0;
}