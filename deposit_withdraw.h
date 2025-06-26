/*

Program author: Armaan Gupta

*/


#include<string.h>
#include<stdio.h>
#include<stdlib.h>

#define MAX_LINE_LENGTH 1024




void depwith_func(int choice, int username){


    //Ask for amount
    int input_amount;
    printf("Enter amount to deposit/withdraw: ");
    scanf("%d", &input_amount);

    char userstr[MAX_LINE_LENGTH];
    itoa(username, userstr, 10);//username integer to string

    char filename[MAX_LINE_LENGTH];
    snprintf(filename, sizeof(filename), "accounts_directory/%d.txt", username);


    //Existing amount
    FILE *fptr = fopen(filename, "r");
    char existing_amountstr[MAX_LINE_LENGTH];
    fgets(existing_amountstr, sizeof(existing_amountstr), fptr);
    fclose(fptr);
    
    int amount;
    amount = atoi(existing_amountstr);//First updataion of amount in account
    
    //check whether withdrawal or deposit
    if (choice==1){
        amount = amount+input_amount;//deposit
        printf("Deposited!");
    }
    else if(choice==2){
        amount = amount - input_amount;//withdraw
        printf("Withdrawan!");
    }

    //Upload final amount onto account file
    FILE *fptr2 = fopen(filename, "w");
    fprintf(fptr2, "%d", amount);
    fclose(fptr2);


    

}