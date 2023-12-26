#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "userAuth.h"

#define ROWS 8
#define COLS 4

void waitForKeypress()
{
    printf("\nPress Enter to continue...");
    getch();
    fflush(stdin);
}

typedef struct Person
{
    char name[50];
    int age;
    char gender[10];
    int seatNo;
    struct Person *next;
} Person;

void inputPersonDetails(Person *person)
{
    printf("Enter name: ");
    scanf("%s", person->name);

    printf("Enter age: ");
    scanf("%d", &(person->age));

    printf("Enter gender: ");
    scanf("%s", person->gender);
}

void enqueue(Person **front, Person **rear, Person *newPerson)
{
    if (*rear == NULL)
    {
        *front = newPerson;
        *rear = newPerson;
    }
    else
    {
        (*rear)->next = newPerson;
        *rear = newPerson;
    }
}

Person *dequeue(Person **front, Person **rear)
{
    if (*front == NULL)
        return NULL;

    Person *temp = *front;
    *front = (*front)->next;

    if (*front == NULL)
        *rear = NULL;

    return temp;
}

void allotSeats(int seats[ROWS][COLS], Person *person)
{
    int row = -1;
    int col = -1;

    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            if (seats[i][j] == 0)
            {
                row = i;
                col = j;
                break;
            }
        }
        if (row != -1 && col != -1)
        {
            break;
        }
    }

    if (row == -1 || col == -1)
    {
        printf("All seats are occupied.\n");
        waitForKeypress();
        return;
    }

    seats[row][col] = 1;
    person->seatNo = row * COLS + col;

    char username[100];
    printf("\nPlease Enter the User name again:\n");
    scanf("%s", username);
    char cartFile[100];
    snprintf(cartFile, sizeof(cartFile), "%s_cart.txt", username);
    buyProduct(person, cartFile);

    FILE *fp = fopen("1.txt", "w");
    if (fp == NULL)
    {
        printf("Failed to open file.\n");
        waitForKeypress();
        return;
    }

    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            fprintf(fp, "%d ", seats[i][j]);
        }
        fprintf(fp, "\n");
    }

    fclose(fp);
}

void buyProduct(Person *head, char *cartFile)
{
    system("cls");
    if (head == NULL)
    {
        printf("No tickets are booked.\n\n");
        waitForKeypress();
        return;
    }

    Person *current = head;

    FILE *file = fopen(cartFile, "a");
    if (file == NULL)
    {
        printf("Error opening file.\n");
        waitForKeypress();
        return;
    }

    fprintf(file, "Name: %s\n", current->name);
    fprintf(file, "Age: %d\n", current->age);
    fprintf(file, "Gender: %s\n", current->gender);
    fprintf(file, "Seat No: %d\n", current->seatNo);
    fprintf(file, "---------------------------------\n");

    fclose(file);

    printf("Your ticket has been booked.\n\n");
    // UserChoice();
}

void displayCart(char *cartFile)
{
    FILE *file = fopen(cartFile, "r");
    if (file == NULL)
    {
        printf("Error opening file.\n");
        waitForKeypress();
        return;
    }

    char line[100];
    
    printf("Cart:\n");
    if (fgets(line, sizeof(line), file) == NULL)
    {
        printf("Cart is empty.\n");
    }
    else
    {
        printf("%s", line);
        while (fgets(line, sizeof(line), file) != NULL)
        {
            printf("%s", line);
        }
    }

    fclose(file);
    waitForKeypress();
}

void bookTickets(int num)
{
    int number, t;
    int empty = 0;
    Person *front = NULL;
    Person *rear = NULL;
    char numberString[10];
    int tickets[ROWS][COLS];
    FILE *fp;
    fp = fopen("1.txt", "r");
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            fscanf(fp, "%d ", &tickets[i][j]);
        }
    }

    sprintf(numberString, "%d", num);
    char train[100];
    strcpy(train, numberString);
    strcat(train, ".txt");

    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            fscanf(fp, "%d ", &tickets[i][j]);
            if (tickets[i][j] == 0)
                empty = 1;
        }
    }
    system("cls");
    printf("Input Number of tickets: ");
    scanf("%d", &t);

    for (int i = 0; i < t; i++)
    {
        printf("\nEnter details for Person %d:\n", i + 1);

        Person *newPerson = (Person *)malloc(sizeof(Person));
        if (newPerson == NULL)
        {
            printf("Memory allocation failed.\n");
            return;
        }

        inputPersonDetails(newPerson);
        enqueue(&front, &rear, newPerson);
    }

    // Check if there are available seats and dequeue the queue
    if (empty)
    {
        for (int i = 0; i < ROWS; i++)
        {
            for (int j = 0; j < COLS; j++)
            {
                if (tickets[i][j] == 0)
                {
                    Person *bookedPerson = dequeue(&front, &rear);
                    allotSeats(tickets, bookedPerson);
                }
            }
        }
    }
    fclose(fp);
    UserChoice();
}

int trainselection()
{
    system("cls");
    printf("Choose destination\n");
    int choice;

    printf("=== Destination Selection ===\n");
    printf("1. New Delhi\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
        printf("You have selected New Delhi as your destination.\n");
        bookTickets(choice);
        break;

    default:
        printf("Invalid choice!\n");
    }

    return choice;
}

void UserChoice()
{
    int role1;
 system("cls");
    do
    {
        printf("\t\t\tYou have been successfully logged in.\n");
        printf("\t\t\tChoose from the following options:\n");
        printf("\t\t\t1. Book Ticket\n");
        printf("\t\t\t2. View Tickets\n");
        printf("\t\t\t3. Exit\n");
        printf("\t\t\tEnter your Choice: ");
        scanf("%d", &role1);

        switch (role1)
        {
        case 1:
            trainselection();
            break;
        case 2:
        {
            char username[100];
            printf("\nPlease Enter the User name again:\n");
            scanf("%s", username);
            char cartFile[100];
            snprintf(cartFile, sizeof(cartFile), "%s_cart.txt", username);
            displayCart(cartFile);
            break;
        }
        case 3:
            printf("Exiting program...\n");
            break;
        default:
            printf("Invalid Choice. Please try again.\n\n");
            break;
        }
    } while (role1 != 3);
}

int main()
{
    int role = 0;

    do
    
    {
        system("cls");
        printf("\t\t\tRailway Ticket Booking\n");
        printf("\t\t\tMenu:\n");
        printf("\t\t\t1. Proceed\n");
        printf("\t\t\t2. Exit\n");
        printf("\t\t\tEnter your Choice: ");
        scanf("%d", &role);

        switch (role)
        {
        case 1:
            if (userLoginMenu())
                UserChoice();
            break;
        case 2:
            printf("Exiting program...\n");
            break;
        default:
            printf("Invalid Choice. Please try again.\n\n");
            break;
        }
    } while (role != 2);

    return 0;
}