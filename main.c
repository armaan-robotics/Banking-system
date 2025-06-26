/*

Program author: Armaan Gupta


Working:

When the code is run, the user can either create or login to an account.
One can either deposit, withdraw or check balance from the bank account and then close.
Account details will be maintained in a .txt file.

In this new model multiple accounts can be held

*/


#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#include"login.h"
#include"create_acc.h"
#include"deposit_withdraw.h"
#include"balance.h"



//Introduction
char welstr[12][101] = {
    "\n\n\n--------------------------\n\n",
    "WELCOME TO ARMAAN'S BANK\n\n",
    "--------------------------\n\n\n",
    "--------------------------\n",
    "Type the number associated\nwith the task\n",
    "--------------------------\n",
    "[1] Create Account\n",
    "[2] Login\n",
    "[1] Deposit Money\n",
    "[2] Withdraw Money\n",
    "[3] Check Balance\n",
    "--------------------------\n"

    
};




//Complete
void main(){


    while (1<2)//Keep this in loop
    {
        
        
        int accopt; //account action chosen


        

        //Print the introduction
        for (int i = 0; i < 12; i++)
        {
            if (i==8 || i==9 || i==10 || i==11){
                continue; //omit wtihdraw, deposit and balance option for now
            }
            else{
                printf("%s", welstr[i]);
            }
        }
        
        scanf("%d", &accopt);




        //Calling account functions for action
        switch (accopt)
        {
        case 1:
            create_acc();
            break;
        case 2:{
            int x = login();
            if (x!=0){

                printf("Logged In !\n");
                //printf("%d", x);
                cont(x);

            }
            break;
        }

        default:
            printf("Invalid option\n");
            break;
        }


    }

    
    
    
}






// function to call withdrawal, deposit and balance
void cont(int username){

    //Print the introduction
    for (int i = 0; i < 12; i++)
    {
        if (i==6 || i==7 ){
            continue; //omit login and create account option
        }
        else{
            printf("%s", welstr[i]);
        }
    }

    int actopt; //action chosen
    scanf("%d", &actopt);


    switch (actopt)
    {
    case 1:
        depwith_func(1, username);
        break;

    case 2:
        depwith_func(2, username);
        break;

    case 3:
        balance_func(username);
        break;

    
    default:
        printf("Invalid option\n");
        break;
    }
        


    main();

}

