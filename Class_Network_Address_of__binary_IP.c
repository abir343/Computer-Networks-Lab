/*
Date : 22/06/2021
Obj : Find class and network address of given IP address in binary format...
Author : Yuvraj Raghuvanshi (https://github.com/yuvrajraghuvanshis)
*/

#include <stdio.h>
#include <iostream>

int main()
{

    int IP[32] = {0}, i, temp, netIdLen = 0;
    printf("\nEnter IP address in binary format : ");
    for (i = 0; i < 32; i++)
    {
        scanf("%d", &temp);
        if (temp != 0 && temp != 1)
        {
            printf("Incorrect IP, exiting...");
            printf("\n\n");
            system("pause"); // To freeze screen.
            return -1;
        }
        IP[i] = temp;
    }

    // Finding class...
    if (IP[0] == 0)
    {
        printf("Class : A\n");
        netIdLen = 8;
    }
    else if (IP[0] == 1 && IP[1] == 0)
    {
        printf("Class : B\n");
        netIdLen = 16;
    }
    else if (IP[0] == 1 && IP[1] == 1 && IP[2] == 0)
    {
        printf("Class : C\n");
        netIdLen = 24;
    }
    else if (IP[0] == 1 && IP[1] == 1 && IP[2] == 1 && IP[3] == 0)
    {
        printf("Class : D\n");
        netIdLen = 0;
    }
    else if (IP[0] == 1 && IP[1] == 1 && IP[2] == 1 && IP[3] == 1)
    {
        printf("Class : E\n");
        netIdLen = 0;
    }
    else
    {
    }

    if (netIdLen == 0)
    {
        printf("Class D is not broken down into netId and hostId. Class E is reserved.\n");
    }
    else
    {
        for (i = 0; i < 32; i++)
            IP[i] = i < netIdLen ? IP[i] & 1 : IP[i] & 0;
    }
    printf("Network address : ");
    for (i = 0; i < 32; i++)
    {
        printf("%d", IP[i]);
    }

    printf("\n\n");
    system("pause"); // To freeze screen.
    return 0;
}
