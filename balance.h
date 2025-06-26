//Complete


/*

Program author: Armaan Gupta


When this function is called, the username is used to find and read the file.
If the file is not available then it is a wrong username/ it doesnt exist.
If exists, the file is read an the string is saved.
File is closed
string is converted to integer and returned to 'main.c'

*/


#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX_LINE_LENGTH 1024 



void balance_func(int username){


    //integer username converted to string
    char usernamestr[MAX_LINE_LENGTH];
    itoa(username, usernamestr, 10);

    //file directory
    char filename[MAX_LINE_LENGTH];
    snprintf(filename, sizeof(filename), "accounts_directory/%d.txt", username);


    //read file
    int balance;
    char balancestr[MAX_LINE_LENGTH];
    FILE*fptr = fopen(filename, "r");
    fgets(balancestr, sizeof(balancestr), fptr);
    balance = atoi(balancestr);

    fclose(fptr);

    printf("Balance left: %d", balance);

}