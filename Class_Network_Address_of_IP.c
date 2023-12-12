/*
Date : 22/06/2021
Obj : Find class and network address of given IP address...
Author : Yuvraj Raghuvanshi (https://github.com/yuvrajraghuvanshis)
*/

#include <stdio.h>
#include <iostream>

int main()
{

    int firstOctet, secondOctet, thirdOctet, fourthOctet;
    printf("\nEnter IP address in dotted decimal format (x.x.x.x) : ");
    scanf("%d.%d.%d.%d", &firstOctet, &secondOctet, &thirdOctet, &fourthOctet);

    // Finding class...
    if (firstOctet >= 0 && firstOctet <= 127)
    {
        printf("Class : A");
        printf("\nNetwork Address : %d.%d.%d.%d", firstOctet & 255, secondOctet & 0, thirdOctet & 0, fourthOctet & 0);
    }
    else if (firstOctet >= 128 && firstOctet <= 191)
    {
        printf("Class : B");
        printf("\nNetwork Address : %d.%d.%d.%d", firstOctet & 255, secondOctet & 255, thirdOctet & 0, fourthOctet & 0);
    }
    else if (firstOctet >= 192 && firstOctet <= 223)
    {
        printf("Class : C");
        printf("\nNetwork Address : %d.%d.%d.%d", firstOctet & 255, secondOctet & 255, thirdOctet & 255, fourthOctet & 0);
    }
    else if (firstOctet >= 224 && firstOctet <= 239)
    {
        printf("Class : D");
        printf("\nNetwork Address : Not divided into netId and hostId");
    }
    else if (firstOctet >= 240 && firstOctet <= 255)
    {
        printf("Class : E");
        printf("\nNetwork Address : Not divided into netId and hostId.");
    }
    else
        printf("Incorrect IP.");

    printf("\n\n");
    system("pause"); // To freeze screen.
    return 0;
}
