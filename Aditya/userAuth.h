#include <stdio.h>
#include <stdlib.h>
#include <string.h>



typedef struct user {
    char username[20];
    char password[20];
    char email[50];
    struct user* next;
    struct user* prev;
} user;

int userLoginMenu();


void saveUsersToFile(user* head) {
    FILE* file = fopen("users.txt", "w");
    if (file == NULL) {
        printf("Error opening file.\n");
        return;
    }

    user* temp = head;
    while (temp != NULL) {
        fprintf(file, "%s %s %s\n", temp->email, temp->username, temp->password);
        temp = temp->next;
    }

    fclose(file);
}

user* readUsersFromFile() {
    FILE* file = fopen("users.txt", "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return NULL;
    }

    user* head = NULL;
    char email[50], username[20], password[20];
    while (fscanf(file, "%s %s %s", email, username, password) != EOF) {
        user* newUser = (user*)malloc(sizeof(user));
        strcpy(newUser->email, email);
        strcpy(newUser->username, username);
        strcpy(newUser->password, password);
        newUser->next = NULL;
        newUser->prev = NULL;

        if (head == NULL) {
            head = newUser;
        } else {
            user* temp = head;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newUser;
            newUser->prev = temp;
        }
    }

    fclose(file);
    return head;
}

user* registerUser() {
    char username[20], password[20], email[50];
    printf("Please enter your email: ");
    scanf(" %[^\n]", email);  // Use %[^\n] to read the whole line

    printf("Please enter a username: ");
    scanf(" %[^\n]", username);  // Use %[^\n] to read the whole line

    printf("Please enter a password: ");
    scanf(" %[^\n]", password);  // Use %[^\n] to read the whole line


    user* newUser = (user*)malloc(sizeof(user));
    newUser->next = NULL;
    newUser->prev = NULL;
    strcpy(newUser->email, email);
    strcpy(newUser->username, username);
    strcpy(newUser->password, password);

    return newUser;
}

void login(user* head) {
    char email[50], username[20], password[20];  // Change email array size to 50
    printf("Please enter your email: ");
    scanf(" %[^\n]", email);  // Use %[^\n] to read the whole line

    printf("Please enter a username: ");
    scanf("%s", username);

    printf("Please enter a password: ");
    scanf("%s", password);

    user* temp = head;
    if (temp == NULL) {
        printf("No users\n");
        return;
    }
    while (temp != NULL) {
        if (strcmp(temp->email, email) == 0 && strcmp(temp->username, username) == 0 && strcmp(temp->password, password) == 0) {
            printf("Login Successful\n");
            return;
        }
        temp = temp->next;
    }
    printf("User not found, kindly register\n");
    userLoginMenu();

}

void addUser(user** headPtr) {
    user* newUser = registerUser();
    if (*headPtr == NULL) {
        *headPtr = newUser;
    } else {
        newUser->next = *headPtr;
        (*headPtr)->prev = newUser;
        *headPtr = newUser;
    }
    printf("User added successfully.\n\n");

}

int userLoginMenu() {
    user* head = NULL;
    head=readUsersFromFile();
    int choice;
    do {
        printf("Menu:\n");
        printf("1. Register User\n");
        printf("2. Login\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        fflush(stdin);

        switch (choice) {
            case 1:
                addUser(&head);
                saveUsersToFile(head);
                break;
            case 2:
                login(head);
                // Check if login was successful
                // Return 1 to indicate successful login
                return 1;
                break;
            case 3:
                printf("Exiting program...\n");
                exit(0);
                return 0;  // Return 0 to indicate program exit
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 3);

    return 0;  // Return 0 if the program reaches the end without a successful login
}


