/*

Program author: Armaan Gupta

Takes in the username and password
Finds both in their respective documents.
If both exist, the logged in and next step can be accessed.

*/
#include<stdio.h>
#include<string.h>
#define MAX_LINE_LENGTH 1024 



int login(){

    char account_details_input[2][MAX_LINE_LENGTH];
    

    //Ask for username and password
    printf("\nPlease login\nUsername: ");
    scanf("%s", account_details_input[0]);
    printf("Password: ");
    scanf("%s", account_details_input[1]);

    int userline = checkusername(account_details_input[0]);
    //check for correct username
    if (userline!=-1){
        if (checkpassword(account_details_input[1], userline)==1){

            //printf("%d", atoi(account_details_input[0]));
            return atoi(account_details_input[0]);
        }
        else{
            printf("Invalid password");
            return 0;
            
        }
    }
    else {
        printf("Invalid username");
        return 0;
        
    }

}



int checkusername(char userinput[]){





    FILE *file;
    char userstring[MAX_LINE_LENGTH];


    // Open the file in read mode
    file = fopen("accounts_directory/username.txt", "r"); 


    //check for file opening error
    if (file == NULL) {
        perror("Error opening file");

    }

    int line_number=1;
    // Read each line until end-of-file
    while (fgets(userstring, sizeof(userstring), file) != NULL) {

        // Remove newline character if present
        userstring[strcspn(userstring, "\n")] = '\0';

        //check is username matches
        if (strcmp(userstring, userinput)==0){
            return line_number;
        }

        line_number++;
    }

    // Close the file
    fclose(file);
    return -1;


}







int checkpassword( char userinput[], int userline){





    FILE *file;
    char userstring[MAX_LINE_LENGTH];


    // Open the file in read mode
    file = fopen("accounts_directory/password.txt", "r"); 


    //check for file opening error
    if (file == NULL) {
        perror("Error opening file");

    }


    int line=1;

    // Read each line until end-of-file
    while (fgets(userstring, sizeof(userstring), file) != NULL) {

        // Remove newline character if present
        userstring[strcspn(userstring, "\n")] = '\0';

        //check is username matches
        if (line==userline && strcmp(userstring, userinput)==0){
            return 1;
        }
        line++;
    }

    // Close the file
    fclose(file);
    return 0;


}