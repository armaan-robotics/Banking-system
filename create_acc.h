/*
Program author: Armaan Gupta


Checks the username list for the last username code.
Increases it by 1 and assigns that as new username.
Then takes in the password from the user.
Adds the new username to the username list and password to password list.
Creates a new file by the name of the username and put 0 as the balance in it.



*/

#include <stdio.h>
#include <string.h>
#include<stdlib.h>
#define MAX_LINE_LENGTH 1024


void create_acc() {
    // Introduction
    char welstr[6][101] = {
        "\n\n\n--------------------------\n\n",
        "WELCOME TO ARMAAN'S BANK\n\n",
        "--------------------------\n\n\n",
        "--------------------------\n",
        "Create account\n",
        "--------------------------\n"
    };

    for (int i = 0; i < 6; i++) {
        printf("%s", welstr[i]);
    }

    // Input credentials
    char password[100];

    int username = generate_username();

    printf("Your assigned Username: %d\n", username);

    printf("Enter Password of choice: ");
    scanf("%s", password);

    // Open files in append mode
    FILE *fuptr = fopen("accounts_directory/username.txt", "a");
    FILE *fpptr = fopen("accounts_directory/password.txt", "a");

    if (fuptr == NULL || fpptr == NULL) {
        perror("Error opening files");
        return;
    }

    // Write credentials with newline
    fprintf(fuptr, "%d\n", username);
    fprintf(fpptr, "%s\n", password);

    fclose(fuptr);
    fclose(fpptr);

    printf("Account created successfully!\n");


    char newfilename[MAX_LINE_LENGTH];

    snprintf(newfilename, sizeof(newfilename), "accounts_directory/%d.txt", username);
    
    FILE* newfileptr = fopen(newfilename, "w");
    fprintf(newfileptr, "%d\n", 0);
    fclose(newfileptr);



}




int generate_username(){



    FILE *file;
    


    // Open the file in read mode
    file = fopen("accounts_directory/username.txt", "r"); 


    //check for file opening error
    if (file == NULL) {
        perror("Error opening file");

    }

    char userstring[MAX_LINE_LENGTH];
    char lastline[MAX_LINE_LENGTH];

    // Read each line until end-of-file
    while (fgets(userstring, sizeof(userstring), file) != NULL) {

        strcpy(lastline, userstring);
        
        }


    // Remove newline if present
    lastline[strcspn(lastline, "\n")] = '\0';


    int username = atoi(lastline)+1;

    // Close the file
    fclose(file);

    return username;


}
